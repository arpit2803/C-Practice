// DLL_Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\..\DllLibRecompile\DllLibRecompile\DllLibRecompile.h"

int main()
{
	CMYClass classObj;
	classObj.Print("COM from scratch");
	system("Pause");
    return 0;
}

