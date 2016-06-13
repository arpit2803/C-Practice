#pragma once

#include"IComponent.h"

class CComponent : public IComponent
{
	public :
		virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv);
		virtual ULONG __stdcall AddRef();
		virtual ULONG __stdcall Release();

		virtual void __stdcall Print(const char* msg);
		CComponent();
		~CComponent();
	private:
		long m_cRef;

};