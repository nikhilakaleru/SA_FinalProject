// Core.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "Core.h"
#include <iostream>
//#include "..\GenericObserverPattern\TopLevelSession.h"

//static CoreSession* m_coreSession = nullptr;

CORE_API int initializeProduct(void)
{
	std::cout << "Product Core is Initialized" << std::endl;
	//TopLevelSession::GetInstance();
	return 0;
}

CORE_API int shutdownProduct(void)
{
	std::cout << "Product Core is Shutdown" << std::endl;
	//TopLevelSession::GetInstance().ClearObservers();
	return 0;
}

