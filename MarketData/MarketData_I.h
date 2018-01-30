#pragma once
#include "ClassManagement\Taggable_I.h"
#include "Utils\Memory.h"

namespace DKRiskEngine
{

	class MarketData_I
	{
	public:
		DefineSharedPtr(MarketData_I)

		MarketData_I();
		virtual ~MarketData_I();

		virtual MarketData_I* clone() const = 0;
	};

}

