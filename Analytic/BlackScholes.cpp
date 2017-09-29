#include "BlackScholes.h"
#include "Maths\DistributionNormal.h"

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


BlackScholes::~BlackScholes() {}

double
BlackScholes::computeCall() const
{
	double t = market_m->getNowDate();
	double T = instrument_m->getExpiry();
	// TODO:
	//double spot = market_m->getSpot(instrument_m);
	//double df = market_m->getDomesticCurve(instrument_m)->getDF(t,T);

	return 0.0;
}
