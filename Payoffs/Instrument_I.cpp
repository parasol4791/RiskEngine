#include "Instrument_I.h"

using namespace std;


Instrument_I::Instrument_I(const PayOff_I& payOff)
{
	payOff_m.reset(payOff.clone());
}

Instrument_I::~Instrument_I()
{
}

double Instrument_I::computePayoff(double spot) const
{
	if (payOff_m.get())
		return (*payOff_m)(spot);
	else
		throw "Missing payoff";
}
