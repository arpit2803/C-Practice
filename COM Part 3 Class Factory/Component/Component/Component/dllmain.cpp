// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
HRESULT __stdcall DllRegisterServer();
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	DllRegisterServer();
	return TRUE;
}

