#include "InstrOptionVanilla.h"
#include "Utils\Exceptions.h"

using namespace DKRiskEngine;
using namespace std;

InstrOptionVanilla::InstrOptionVanilla(
	const PayOff_I& payOff,
	const double expiry,
	const string& ccy,
	const string& id
) :
	Instrument_I(payOff, ccy, id),
	expiry_m(expiry)
{
}


InstrOptionVanilla::~InstrOptionVanilla() {}

void InstrOptionVanilla::checkSanity(const Market::CPtr& market) const
{
	double nowDate = market->getNowDate();
	if (expiry_m < nowDate)
		throwException("Expired vanilla instrument");
}
