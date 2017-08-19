#include "PayOffEuropeanCall.h"
#include <algorithm>



PayOffEuropeanCall::PayOffEuropeanCall(double strike) : strike_m(strike)
{
}


PayOffEuropeanCall::~PayOffEuropeanCall()
{
}

double PayOffEuropeanCall::operator()(double spot) const
{
	return std::max(spot-strike_m, 0.0);
}
