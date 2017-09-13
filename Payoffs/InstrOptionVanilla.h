#pragma once
#include "Instrument_I.h"

namespace DKRiskEngine
{

	class InstrOptionVanilla :
		public Instrument_I
	{
	public:
		DefineSharedPtr(InstrOptionVanilla)

		InstrOptionVanilla(
			const PayOff_I& payOff,
			double expiry
		);
		virtual ~InstrOptionVanilla();

		virtual void checkSanity(const Market::CPtr& market) const;

		double getExpiry() const { return expiry_m; }

	private:
		double expiry_m;
	};

}
