#include"stdafx.h"
#include"CClassFacotryImpl.h"


//////////////////////////////////////
ULONG __stdcall CComponent::AddRef()
{
	Print("Incrementing the referance count variable...");
	return InterlockedIncrement(&m_cRef);
}

//////////////////////////////////////
ULONG __stdcall CComponent::Release()
{
	Print("Decrementing the referance count variable...");
	if (InterlockedDecrement(&m_cRef) == 0)
	{
		delete this;
		return 0;
	}
	return m_cRef;
}

//-----------------------------// 
//QueryInterface implementation
//-----------------------------// 
///////////////////////////////////////////////////////////////////////////
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
	return S_OK;
}


//////////////////////////////////////////////////
void __stdcall CComponent::Print(const char* msg)
{
	cout << "Component:\t" << msg << endl;

}

/////////////////////////////////
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


//------------------------------------//
// Creation function for the Component 
//------------------------------------//

extern "C" IUnknown* CreateInstance()
{
	//IUnknown* pIUnknown =static_cast<IComponent*>(new CComponent) ;
	IUnknown* pIUnknown = (new CComponent);

	return pIUnknown;
}