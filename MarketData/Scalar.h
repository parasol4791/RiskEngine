#pragma once
#include "MarketData_I.h"

namespace DKRiskEngine
{

	class Scalar :
		public MarketData_I
	{
	public:
		DefineSharedPtr(Scalar)

		Scalar(double value);
		virtual ~Scalar();

		virtual MarketData_I* clone() const { return new Scalar(*this); }

	private:
		double value_m;
	};

}

