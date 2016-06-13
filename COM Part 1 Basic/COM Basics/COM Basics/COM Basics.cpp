// COM Basics.cpp : Defines the entry point for the console application.
//
///http://www.codeproject.com/Articles/6726/COM-from-scratch-PART-ONE
#include "stdafx.h"
#include"IComponent.h"

IUnknown* CreateInstance();
int main()
{
	IUnknown* pIUnknown = CreateInstance();
	IComponent* pIComponent = NULL;
	pIUnknown->QueryInterface(IID_IComponent, (void**)&pIComponent);
	pIComponent->Print("COM from scratch.");

	pIComponent->Release();

	system("pause");
    
}

