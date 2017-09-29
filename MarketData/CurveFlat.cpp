#include "CurveFlat.h"
#include <math.h>

using namespace DKRiskEngine;

CurveFlat::CurveFlat(double rate) : rate_m(rate)
{
}


CurveFlat::~CurveFlat()
{
}

double CurveFlat::getDF(double t1, double t2) const
{
	checkDates(t1, t2);
	return exp(-rate_m * (t2-t1));
}
