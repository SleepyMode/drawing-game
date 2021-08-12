
#include <set>
#include <fstream>
#include <string>
#include <string_view>
#include <filesystem>
#include <platform/utils.h>
#include PLATFORM_HEADER(debug)
#include <input/datareader.h>

#define WORDS_FILE "data/words.txt" 

std::set<std::string> DataReader::getWordsList()
{
	std::set<std::string> words;

	// Make sure that the file exists and is not a directory.
	if (std::filesystem::exists(WORDS_FILE) and !std::filesystem::is_directory(WORDS_FILE))
	{
		try
		{
			std::ifstream fileHandle(WORDS_FILE);
			std::string result;
			while (std::getline(fileHandle, result))
			{
				words.insert(result);
			}
		}
		catch (...)
		{
			// TODO: Replace with proper error handling.
			Debug::displayPopup("Failed to read words file", "An error has occured while reading from the words file.");
		}
	}

	return words;
}
