
#pragma once

#if defined(_WIN32)
#	define CURRENT_PLATFORM windows
#elif defined(__linux__)
#	define CURRENT_PLATFORM linux
#else
#	define CURRENT_PLATFORM unknown
#endif

#define PLATFORM_HEADER(fileName) <platform/CURRENT_PLATFORM/fileName.h>
