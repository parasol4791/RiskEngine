#include "PayOffEuropeanPut.h"
#include <algorithm>

PayOffEuropeanPut::PayOffEuropeanPut(double strike) : strike_m(strike)
{
}

PayOffEuropeanPut::~PayOffEuropeanPut()
{
}

double PayOffEuropeanPut::operator()(double spot) const
{
	return std::max(strike_m-spot, 0.0);
}
