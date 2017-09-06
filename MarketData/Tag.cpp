#include "Tag.h"
#include "Utils\StringUtils.h"

using namespace std;
using namespace DKRiskEngine;

/////////////////
/// Class MDTag
//////////////////

MDTag::MDTag(MDataType type) :
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

