#pragma once
#include "PayOff_I.h"

namespace DKRiskEngine
{

	class PayOffEuropeanPut :
		public PayOff_I
	{
	public:
		DefineSharedPtr(PayOffEuropeanPut)

		PayOffEuropeanPut(double strike);
		virtual ~PayOffEuropeanPut();

		virtual PayOff_I* clone() const;
		virtual double operator()(double spot) const;

	private:
		double strike_m;
	};

}

