#pragma once
#include "Utils\Memory.h"
#include <string>
#include <map>

namespace DKRiskEngine
{

	enum MDataType
	{
		MDType_Spot = 1,
		MDType_YieldCurve = 2,
		MDType_VolSurface = 3
	};

	enum MDField
	{
		MDField_Currency = 1,
		MDField_ID = 2
	};

	class MDTag
	{
	public:
		DefineSharedPtr(MDTag)

		typedef std::multimap<MDField, std::string> MDFieldsMap;
		MDTag(MDataType type);
		void addCcy(const std::string& ccy);
		void addID(const std::string& id);

		bool operator< (const MDTag& rhs) const;

		static MDTag makeTag(
			const MDataType type,
			const std::string& ccy,
			const std::string& id = ""
		);

	private:
		int compare(
			const MDFieldsMap::const_iterator& iter1,
			const MDFieldsMap::const_iterator& iter2
		) const;

		MDataType mDataType_m;
		MDFieldsMap fields_m;
	};

}

