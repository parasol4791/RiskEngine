#pragma once
#include "Curve.h"

namespace DKRiskEngine
{

	class CurveFlat :
		public Curve
	{
	public:
		DefineSharedPtr(CurveFlat)

		CurveFlat(double rate);
		virtual ~CurveFlat();

		virtual MarketData_I* clone() const { return new CurveFlat(*this); }
		virtual double getDF(double t1, double t2) const;

	private:
		double rate_m;
	};
}

