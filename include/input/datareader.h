#pragma once

#include <set>
#include <string_view>

class DataReader
{
public:
	DataReader() = delete;

	/**
	 * @brief returns a set of the words appearing in the words file.
	 * @return The list of words from the data/words.txt file.
	*/
	static std::set<std::string> getWordsList();
};
