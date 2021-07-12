// 3r_idl_first.cpp : 
////////////////////////////////////////////////////////////////////////////////////
//**********************************************************************************
//  This is an unpublished work, the copyright in which rests in Portrait Software *
//  International Limited. All rights reserved. The information contained herein   *
//  is the  property of Portrait Software International Limited, and no part may   *
//  be reproduced, used or disclosed, except as authorised by contract or other    *
//  written permission. The copyright and the foregoing restriction on             *
//  reproduction, use and disclosure extend to all the media in which this         *
//  information may be embodied. Some material contained within is the copyright   *
//  of other parties, and such material may not be reproduced, used or disclosed   *
//  except as agreed with those parties.                                           *
//**********************************************************************************
//
// Copyright   : Portrait Software International Limited, 2016
// Date        : 18 November 2016
// Author      : Donald Matthews
// Description : Implementation of DLL Exports.
//
// 
// $Log:  $
//	
//	Ver : /main/eds_platform_upgrade_2009/1;  Mon Nov 21 15:25:12 2016;  RCBuild using rcbuild_SCWIN7BLD_eds_platform_upgrade_2009_sn_view view
//	DMatthews. New project 3r_idl_first to build parent type libraries.
//	
//


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f 3r_idl_firstps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include <3r_idl_first.h>
#include <3r_idl_first_i.c>


CComModule _Module;

BEGIN_OBJECT_MAP( ObjectMap )
END_OBJECT_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLL Entry Point

extern "C"
BOOL WINAPI DllMain( HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/ )
{
    if( dwReason == DLL_PROCESS_ATTACH )
    {
        _Module.Init( ObjectMap, hInstance, &LIBID_My3r_idl_firstLib );
        DisableThreadLibraryCalls( hInstance );
    }
    else if( dwReason == DLL_PROCESS_DETACH )
        _Module.Term();
    return TRUE;    // ok
}

/////////////////////////////////////////////////////////////////////////////
// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow( void )
{
    return (_Module.GetLockCount() == 0) ? S_OK : S_FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// Returns a class factory to create an object of the requested type

STDAPI DllGetClassObject( REFCLSID rclsid, REFIID riid, LPVOID* ppv )
{
    return _Module.GetClassObject( rclsid, riid, ppv );
}

/////////////////////////////////////////////////////////////////////////////
// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer( void )
{
    // registers object, typelib and all interfaces in typelib
    return _Module.RegisterServer( TRUE );
}

/////////////////////////////////////////////////////////////////////////////
// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer( void )
{
    return _Module.UnregisterServer( TRUE );
}


