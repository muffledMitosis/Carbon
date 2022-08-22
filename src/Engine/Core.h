#pragma once

#define PLATFORM_LINUX

#ifdef PLATFORM_WINDOWS

#ifdef CARBON_BUILD_DLL
	#define C_API __declspec(dllexport)
#else
	#define C_API __declspec(dllimport)
#endif // CE_BUILD_DLL

#endif

#ifdef PLATFORM_LINUX

#ifdef CARBON_BUILD_DLL
	#define C_API __attribute__((visibility("default")))
#else
	#define C_API
#endif // CE_BUILD_DLL

#endif
