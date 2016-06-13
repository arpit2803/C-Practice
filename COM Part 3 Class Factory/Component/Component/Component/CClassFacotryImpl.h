#include "stdafx.h"
#include "Unknwn.h"
#include"Icomponent.h"
#include<iostream>
using namespace std;
class CComponent : public IComponent
{
public:
	// IUnknown implementation
	virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();

	// Interface IComponent implementation
	virtual void __stdcall Print(const char* msg);

public:
	CComponent();
	~CComponent();

private:

	long m_cRef;// The referance count

};	

