// ClientToCOM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<Unknwn.h>
#include"../Component/IComponent.h"
extern "C"
{
	extern const IID IID_IComponent;

}
extern "C"
{
	extern const IID CLSID_Component;

}
int main()

	{
		HRESULT hr;
		IUnknown* pIUnknown;
		IComponent* pIComponent;
		IClassFactory* pIClassFactory;

		::CoInitialize(NULL);
		/*
		//Once the CoCreateInstance is called, the component
		//will be created and the client can not
		//control it, that's why CoCreateInstance is inflexible
		//and the solution is to call CoGetClassObject function
		hr = ::CoCreateInstance(CLSID_Component,NULL,
		CLSCTX_INPROC_SERVER,IID_IUnknown,(void**)&pIUnknown) ;
		if (SUCCEEDED(hr))
		{
		hr=pIUnknown->QueryInterface(IID_IComponent,(void**)&pIComponent);
		if(SUCCEEDED(hr))
		pIComponent->Print("COM from scratch.");
		}

		*/
		//-------------------------------//
		// improvement of the client code
		//------------------------------//
		// By calling the CoGetClassObject function, the client can control
		// creation of the component
		hr = CoGetClassObject(CLSID_Component, CLSCTX_INPROC_SERVER,
			NULL, IID_IClassFactory, (void**)&pIClassFactory);
		if (SUCCEEDED(hr))
		{
			hr = pIClassFactory->CreateInstance(NULL,
				IID_IComponent, (void**)&pIComponent);
			if (SUCCEEDED(hr))
				pIComponent->Print("COM from scratch.");
		}

		::CoUninitialize();
		system("pause");
		return 0;

	}
   