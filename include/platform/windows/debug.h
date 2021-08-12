
#pragma once

#include <string_view>
#include <wrapper/windows.h>

class Debug
{
public:
	Debug() = delete;

	static inline void displayPopup(std::string_view title, std::string_view text)
	{
		MessageBoxA(NULL, text.data(), title.data(), MB_OK | MB_ICONINFORMATION);
	}
};
