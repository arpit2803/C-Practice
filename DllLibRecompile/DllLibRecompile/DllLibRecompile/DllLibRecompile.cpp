// DllLibRecompile.cpp : Defines the exported functions for the DLL application.
//
#include"stdafx.h"
#include"DllLibRecompile.h"

__declspec(dllexport) void CMYClass::Print(const char* msg)
{
	m_i = 0;
	cout << msg << endl;
	cout << msg << endl;
}