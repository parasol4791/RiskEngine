#pragma once
#include <string>

namespace DKRiskEngine
{

	class StringUtils
	{
	public:
		StringUtils();
		~StringUtils();

		static std::string toUpper(const std::string& str);
	};

}

