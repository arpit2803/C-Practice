#include"stdafx.h"
#include "iostream"
#include "unknwn.h"//IUnknown definition file.
#include "Create.h"

typedef IUnknown* (*CREATEFUNCPTR)();
//////////////////////////////////////////
IUnknown* CallCreateInstance(char* dllname)
{
	//-----------------------------------------------------------------//
	// Load dynamic link library into client's process.
	//Loadlibrary maps a DLL module and return a handle 
	//that can be used in GetProcAddress 
	//to get the address of a DLL function 
	//-----------------------------------------------------------------// 
	HMODULE hm = ::LoadLibraryA(dllname);
	if (hm == NULL)
		return NULL;
	// Get  the address of CreateInstance function. 
	CREATEFUNCPTR Function =
		(CREATEFUNCPTR)::GetProcAddress(hm, "CreateInstance");
	if (Function == NULL)
		return NULL;
	return Function();
}