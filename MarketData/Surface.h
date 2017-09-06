#pragma once
#include "MarketData_I.h"

namespace DKRiskEngine
{

	class Surface :
		public MarketData_I
	{
	public:

		DefineSharedPtr(Surface)

		Surface();
		virtual ~Surface();

		virtual double getVol(
			double x,
			double y
		) const = 0;
	};

}

