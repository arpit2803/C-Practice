#include"stdafx.h"
#include"CComponentImpl.h"
#include"IComponent.h"
#include<conio.h>
#include<iostream>


using namespace std;
//QueryInterface, which is used in order to navigate between multiple interfaces on an object and 
//returns a pointer to a queried interface.
HRESULT __stdcall CComponent::QueryInterface(const IID& iid, void** ppv)
{
	if (iid == IID_IUnknown)
	{
		Print("Returning pointer to IUnknown...");
		*ppv = static_cast<IComponent*>(this);
	}

	else if (iid == IID_IComponent)
	{
		Print("Returning pointer to IComponent interface...");
		*ppv = static_cast<IComponent*>(this);
	}
	else
	{
		Print("Interface is not supported!.");
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	//The reinterpret_cast operator allows any pointer to be converted into 
	//any other pointer type.
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	// Incrementing the Reference count variable
	return S_OK;
}

ULONG __stdcall CComponent::AddRef()
{
	Print("Incrementing the reference count variable...");
	return InterlockedIncrement(&m_cRef);
}

ULONG __stdcall CComponent::Release()
{
	Print("Decrementing the reference count variable...");
	if (InterlockedDecrement(&m_cRef) == 0)
	{
		delete this;
		return 0;
	}
	return m_cRef;
}

CComponent::CComponent()
{
	Print("Constructing the component...");
	m_cRef = 0;
}

////////////////////////////////////////
CComponent::~CComponent()
{
	Print("Destructing the component...");
}

void __stdcall CComponent::Print(const char* msg)
{
	cout << "---------------------" << endl;

	cout << msg << endl;

	cout << "---------------------" << endl;


}

IUnknown* CreateInstance()
{
	IUnknown* pIUnknown = static_cast<IComponent*>(new CComponent);
	return pIUnknown;
}