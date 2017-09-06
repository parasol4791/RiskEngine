#include "CurveFlat.h"
#include <math.h>

using namespace DKRiskEngine;

CurveFlat::CurveFlat(double rate) : rate_m(rate)
{
}


CurveFlat::~CurveFlat()
{
}

double CurveFlat::getDF(double t) const { return exp(-rate_m * t); }
