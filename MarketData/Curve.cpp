#include "Curve.h"
#include "Utils\Exceptions.h"
#include "Maths\MathFunctions.h"

#include <sstream>

using namespace DKRiskEngine;
using namespace std;

Curve::Curve() {}
Curve::~Curve() {}

void
Curve::checkDates(double t1, double t2) const
{
	if (t1 > t2)
	{
		stringstream ss;
		ss << "While computing DF, first date [" << t1 << "] is larger than the second date [" << t2 << "]";
		throwException(ss.str());
	}

	if (t1 > t2)
	{
		stringstream ss;
		ss << "While computing DF, first date [" << t1 << "] is larger than the second date [" << t2 << "]";
		throwException(ss.str());
	}
	else if (MathFunctions::equalToEps(t1, t2))
	{
		stringstream ss;
		ss << "While computing DF, both dates are equal [" << t1 << "]";
		throwException(ss.str());
	}
}