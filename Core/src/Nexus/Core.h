#pragma once

#ifdef NX_PLATFORM_WINDOWS
	#ifdef NX_BUILD_DLL
		#define NEXUS_API __declspec(dllexport)
	#else 
		#define NEXUS_API __declspec(dllimport)
	#endif 
#else
	#error Nexus only suppports windows!
#endif 

#define BIT(x) (1 << x)