#pragma once

#ifdef GURISTAS_PLATFORM_WINDOWS
	#ifdef GURISTAS_BUILD_DLL
		#define GURISTAS_API __declspec(dllexport)
	#else 
		#define GURISTAS_API __declspec(dllimport)
	#endif
#else
	#error Guristas only support Windows!
#endif
