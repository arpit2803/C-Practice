#include "stdafx.h"
#include "Unknwn.h"
#pragma once
interface IComponent :IUnknown
{
	virtual void __stdcall Print(const char* msg) = 0;
}; 

// {4E321486-62FB-489B-BB5D-F5DA24388829}
static const IID IID_IComponent = { 0x4e321486, 0x62fb, 0x489b,{ 0xbb, 0x5d, 0xf5, 0xda, 0x24, 0x38, 0x88, 0x29 } };
