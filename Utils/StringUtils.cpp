#include "StringUtils.h"
#include <cctype>

using namespace std;
using namespace DKRiskEngine;


StringUtils::StringUtils() {}
StringUtils::~StringUtils() {}

string
StringUtils::toUpper(const string& str)
{
	string strUp(str);
	for (size_t i = 0; i < str.size(); ++i)
		strUp[i] = std::toupper(str[i]);

	return strUp;
}
