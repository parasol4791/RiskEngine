#include "PayOffEuropeanCall.h"
#include <algorithm>

using namespace DKRiskEngine;

PayOffEuropeanCall::PayOffEuropeanCall(double strike) : strike_m(strike)
{
}


PayOffEuropeanCall::~PayOffEuropeanCall()
{
}

PayOff_I* PayOffEuropeanCall::clone() const
{
	return new PayOffEuropeanCall(*this);
}

double PayOffEuropeanCall::operator()(double spot) const
{
	return std::max(spot-strike_m, 0.0);
}
