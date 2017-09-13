#include "BlackScholes.h"

using namespace DKRiskEngine;


BlackScholes::BlackScholes(
	const InstrOptionVanilla::CPtr& instr,
	const Market::CPtr& market
) :
	instrument_m(instr),
	market_m(market)
{
	instr->checkSanity(market);
}


BlackScholes::~BlackScholes()
{
}
