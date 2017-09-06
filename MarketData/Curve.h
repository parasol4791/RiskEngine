#pragma once
#include "MarketData_I.h"

namespace DKRiskEngine
{
	class Curve :
		public MarketData_I
	{
	public:
		DefineSharedPtr(Curve)

		Curve();
		virtual ~Curve();

		virtual double getDF(double t) const = 0;
	};

}

