#include "InstrOptionVanilla.h"

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
