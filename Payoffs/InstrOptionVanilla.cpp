#include "InstrOptionVanilla.h"
#include "Utils\Exceptions.h"

using namespace DKRiskEngine;

InstrOptionVanilla::InstrOptionVanilla(
	const PayOff_I& payOff,
	double expiry
) :
	Instrument_I(payOff),
	expiry_m(expiry)
{
}


InstrOptionVanilla::~InstrOptionVanilla()
{
}

void InstrOptionVanilla::checkSanity(const Market::CPtr& market) const
{
	double nowDate = market->getNowDate();
	if (expiry_m < nowDate)
		throwException("Expired vanilla instrument");
}
