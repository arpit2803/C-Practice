// ClientToCOM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Interface.h"
#include"Create.h"
#include<conio.h>
#include<iostream>

using namespace std;
int main()
{
	HRESULT hr;

	// Get the name of the component to use.
	char dllname[20];
	cout << "Enter the filename of component's server [component.dll]:";
	cin >> dllname;

		// calling the CreateInstance function in the
		// DLL in order to create the component.
		//TRACE("Getting an IUnknown interface pointer...");
	//disadvantage of this method is we have to give dll name.
	//even client and component have been seperated, the client is closely related to the component's implementation i.e knowing dll name
	//is required.
	//this can be improved by : can move the component from one DLL to another or to the other directory.
	//solution is to replace the CallCreateInstance function with COM library function called CoCreateinstance
	//Once the CLSID is obtained, a client application submits the CLSID to the COM run - time library to load the 
	//COM object and retrieve an interface pointer
	//It(CoCreateinstance) takes a CLSID, creates an instance of the corresponding component, and returns an 
	//interface for this instance of the component. 
	//The CoCreateInstance function does not create COM components directly.Instead, it creates a component called class factory, 
	//which then creates the desired component. (http://www.codeproject.com/Articles/6727/COM-from-scratch-PART-TWO)

	IUnknown* pIUnknown = CallCreateInstance(dllname);

		IComponent* pIComponent;
	hr = pIUnknown->QueryInterface(IID_IComponent, (void**)&pIComponent);

	if (SUCCEEDED(hr))
	{
			pIComponent->Print("COM from scratch.");
		//using the component's functionality

		pIComponent->Release();
	}
	system("pause");
		return 0;
}

