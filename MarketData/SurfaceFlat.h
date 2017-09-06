#pragma once
#include "Surface.h"

namespace DKRiskEngine
{

	class SurfaceFlat :
		public Surface
	{
	public:
		DefineSharedPtr(SurfaceFlat)

		SurfaceFlat(double vol);
		virtual ~SurfaceFlat();

		virtual MarketData_I* clone() const { return new SurfaceFlat(*this); }

		virtual double getVol(
			double t,
			double strike
		) const
		{
			return vol_m;
		}

	private:
		double vol_m;
	};

}

