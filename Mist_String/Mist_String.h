#ifndef __MIST_STRING_H
#define __MIST_STRING_H

#include <string>
#include <vector>
#include <algorithm>

namespace Mist
{
	inline std::vector<std::string> Split(const std::string& str, char split)
	{
		size_t splitCount = 0;
		size_t largestSplitSize = 0;
		size_t currentSplitSize = 0;
		for (char c : str)
		{
			if (c == split)
			{
				++splitCount;
				largestSplitSize = std::max(currentSplitSize, largestSplitSize);
			}
			else
			{
				++currentSplitSize;
			}
		}

		if (splitCount == 0)
		{
			return {};
		}

		std::vector<std::string> splitStrings;
		splitStrings.reserve(splitCount);

		std::string workingString;
		workingString.reserve(largestSplitSize);

		size_t strSize = str.size();
		for (size_t i = 0; i < strSize; ++i)
		{
			char c = str[i];
			if (c != split)
			{
				workingString += c;
			}
			else
			{
				splitStrings.push_back(workingString);
				workingString = "";
			}
		}
		splitStrings.push_back(workingString);

		return splitStrings;
	}

	inline std::string Join(const std::vector<std::string>& strs, char joinChar)
	{
		size_t stringSize = 0;
		for (const std::string& str : strs)
		{
			stringSize += str.size() + 1;
		}

		std::string result;
		result.reserve(stringSize);

		size_t strSize = strs.size();
		for (size_t i = 0; i < strSize; ++i)
		{
			result += strs[i];
			if (i < strSize - 1)
			{
				result += joinChar;
			}
		}

		return result;
	}

	inline std::string TrimLeft(const std::string& str, char trimChar = ' ')
	{
		size_t strSize = str.size();
		size_t trimPos = 0;
		for (size_t i = 0; i < strSize; ++i)
		{
			if (str[i] == trimChar)
			{
				trimPos++;
			}
			else
			{
				break;
			}
		}

		return str.substr(trimPos);
	}

	inline std::string TrimRight(const std::string& str, char trimChar = ' ')
	{
		size_t strSize = str.size();
		size_t trimPos = 0;
		for (size_t i = 0; i < strSize; ++i)
		{
			if (str[strSize - (i + 1)] == trimChar)
			{
				trimPos++;
			}
			else
			{
				break;
			}
		}

		return str.substr(0, strSize - trimPos);
	}

	inline std::string Trim(const std::string& str, char trimChar = ' ')
	{
		return TrimRight(TrimLeft(str, trimChar), trimChar);
	}

	inline bool Contains(const std::string& str, const std::string& contain)
	{
		return str.find(contain) != std::string::npos;
	}
}

#endif // __MIST_STRING_H
