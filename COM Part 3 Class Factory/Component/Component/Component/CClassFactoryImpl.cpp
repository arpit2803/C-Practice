#pragma once

#include "stdafx.h"
#include "IClassFactory.h"
#include"CClassFacotryImpl.h"



extern "C"
{
	extern const IID IID_IComponent;

}
extern "C"
{
	extern const IID CLSID_Component;

}

//
// Class factory IUnknown implementation
//////////////////////////////////////////////////////////////////////
HRESULT __stdcall CFactory::QueryInterface(const IID& iid, LPVOID* ppv)
{
	if ((iid == IID_IUnknown) || (iid == IID_IClassFactory))
		*ppv = static_cast<IClassFactory*>(this);
	else
	{
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return S_OK;
}

///////////////////////////////////
ULONG __stdcall CFactory::AddRef()
{
	return ::InterlockedIncrement(&m_cRef);
}


////////////////////////////////////
ULONG __stdcall CFactory::Release()
{

	if (::InterlockedDecrement(&m_cRef) == 0)
	{
		delete this;
		return 0;
	}
	return m_cRef;
}

HRESULT __stdcall DllRegisterServer(void)
{
	cout << "Heyyyy";
	return HRESULT(0);
}

STDAPI DllGetClassObject(const CLSID& clsid, const IID& iid, void** ppv)
{
	if (clsid != CLSID_Component)
		return CLASS_E_CLASSNOTAVAILABLE;
	// Create class factory.
	CFactory* pFactory = new CFactory;
	if (pFactory == NULL)
		return E_OUTOFMEMORY;
	// Get requested interface.
	HRESULT hr = pFactory->QueryInterface(iid, ppv);
	pFactory->Release();
	return hr;

}

//
// IClassFactory implementation
///////////////////////////////////////////////////////////////
HRESULT __stdcall CFactory::CreateInstance(IUnknown* pUnkOuter,
	const IID& iid, void** ppv)
{

	HRESULT hr;
	if (pUnkOuter != NULL)
	{
		return CLASS_E_NOAGGREGATION;
	}
	CComponent* pComponent = new CComponent;
	if (pComponent == NULL)
	{

		return E_OUTOFMEMORY;
	}

	// Get the requested interface.
	hr = pComponent->QueryInterface(iid, (void**)ppv);


	if (FAILED(hr))
		pComponent->Release();

	return hr;
}
//-----------------------------------------------------------------------//
// LockServer
// Called by the client of a class object to keep a server open in memory,
// allowing instances to be created more quickly.
//-----------------------------------------------------------------------//
///////////////////////////////////////////////////
HRESULT __stdcall CFactory::LockServer(BOOL bLock)
{
	return S_OK;
}