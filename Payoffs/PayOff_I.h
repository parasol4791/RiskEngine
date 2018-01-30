#pragma once
#include <Utils\Memory.h>

namespace DKRiskEngine
{

	class PayOff_I
	{
	public:
		DefineSharedPtr(PayOff_I)

		PayOff_I();
		virtual ~PayOff_I();

		virtual PayOff_I* clone() const = 0;
		virtual double operator()(double spot) const = 0;
	};

}

