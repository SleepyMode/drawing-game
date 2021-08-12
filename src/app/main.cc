
#include <cstdio>
#include <platform/utils.h>
#include PLATFORM_HEADER(entry)
#include PLATFORM_HEADER(debug)
#include <input/datareader.h>
#include <wrapper/windows.h>

#include <set>

using namespace std;

void GlobalMain()
{
	std::set<std::string> words = DataReader::getWordsList();

	OutputDebugStringA("Words list:\n");
	for (auto word : words)
	{
		OutputDebugStringA(word.c_str());
		OutputDebugStringA("\n");
	}
}
