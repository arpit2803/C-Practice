#pragma once
#include"stdafx.h"
#include<Unknwn.h>

interface IComponent : IUnknown
{
	virtual void __stdcall Print(const char* msg) = 0;
};


// Forward references for GUID
extern "C"
{
	extern const IID IID_IComponent;

}