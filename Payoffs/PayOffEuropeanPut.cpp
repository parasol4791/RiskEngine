#include "PayOffEuropeanPut.h"
#include <algorithm>

using namespace DKRiskEngine;

PayOffEuropeanPut::PayOffEuropeanPut(double strike) : strike_m(strike)
{
}

PayOffEuropeanPut::~PayOffEuropeanPut()
{
}

PayOff_I* PayOffEuropeanPut::clone() const
{
	return new PayOffEuropeanPut(*this);
}

double PayOffEuropeanPut::operator()(double spot) const
{
	return std::max(strike_m-spot, 0.0);
}
