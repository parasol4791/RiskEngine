#pragma once
#include "MarketData\Market.h"
#include "Payoffs\InstrOptionVanilla.h"

namespace DKRiskEngine
{

	class BlackScholes
	{
	public:
		BlackScholes(
			const InstrOptionVanilla::CPtr& instr,
			const Market::CPtr& market
		);

		~BlackScholes();

		double computeCall() const;
		double computePut() const;

	private:
		InstrOptionVanilla::CPtr instrument_m;
		Market::CPtr market_m;

	};

}

