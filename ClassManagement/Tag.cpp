#include "Tag.h"
#include "Utils\StringUtils.h"
#include "Utils\Exceptions.h"

#include <sstream>

using namespace std;
using namespace DKRiskEngine;

/////////////////
/// Enums
//////////////////

const char*
MDTag::toString(const MDataType mdType)
{
	switch (mdType)
	{
		case MDType_Spot: return "Spot";
		case MDType_YieldCurve: return "YieldCurve";
		case MDType_VolSurface: return "VolSurface";
		default: 
		{
			throwException("Unknown Market Data type");
			return "";
		}
	}
}

const char*
MDTag::toString(const MDField mdField)
{
	switch (mdField)
	{
		case MDField_Currency: return "Ccy";
		case MDField_ID: "ID";
		default:
		{
			throwException("Unknown Market Data field type");
			return "";
		}
	}
}

string MDTag::toString() const
{
	const char* sep1(":");
	const char* sep2("-");
	stringstream ss;
	ss << "[" << toString(mDataType_m);
	MDFieldsMap::const_iterator iter = fields_m.begin();
	for (; iter != fields_m.end(); ++iter)
	{
		ss << sep1 << toString(iter->first) << sep2 << iter->second;
	}
	ss << "]";
	return ss.str();
}

/////////////////
/// Class MDTag
//////////////////

MDTag::MDTag(const MDataType type) :
	mDataType_m(type)
{}

void MDTag::addCcy(const std::string& ccy)
{
	string strUp = StringUtils::toUpper(ccy);
	fields_m.insert(std::pair<MDField, std::string>(MDField_Currency, strUp));
}

void MDTag::addID(const std::string& id)
{
	fields_m.insert(std::pair<MDField, std::string>(MDField_ID, StringUtils::toUpper(id)));
}

bool MDTag::operator< (const MDTag& rhs) const
{
	if (mDataType_m < rhs.mDataType_m)
		return true;
	else if (mDataType_m > rhs.mDataType_m)
		return false;
	else
	{
		if (fields_m.size() < rhs.fields_m.size())
			return true;
		else if (fields_m.size() > rhs.fields_m.size())
			return false;
		else // same size
		{
			MDFieldsMap::const_iterator iter1 = fields_m.begin();
			MDFieldsMap::const_iterator iter2 = rhs.fields_m.begin();
			for (; iter1 != fields_m.end(); ++iter1)
			{
				int c = compare(iter1, iter2);
				if (c != 0)
					return (c == 1) ? true : false;
				++iter2;
			}
		}
		return false; // equal
	}
}

int MDTag::compare(
	const MDFieldsMap::const_iterator& iter1,
	const MDFieldsMap::const_iterator& iter2
) const
{
	if (iter1->first < iter2->first)
		return 1;
	else if (iter1->first > iter2->first)
		return -1;

	if (iter1->second < iter2->second)
		return 1;
	else if (iter1->second > iter2->second)
		return -1;

	return 0; // equal
}

MDTag
MDTag::makeTag(
	const MDataType type,
	const string& ccy,
	const string& id
)
{
	MDTag tag(type);
	tag.addCcy(ccy);
	tag.addID(id);

	return tag;
}


