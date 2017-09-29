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

		virtual double getDF(double t1, double t2) const = 0;

	protected:
		void checkDates(double t1, double t2) const;
	};

}

