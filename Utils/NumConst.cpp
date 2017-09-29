#include "NumConst.h"

#include <limits>

using namespace DKRiskEngine;
using namespace std;


int NumConst::INT_Min()
{
	return numeric_limits<int>::min();
}

int NumConst::INT_Max()
{
	return numeric_limits<int>::max();
}

double NumConst::DBL_ROUND()
{
	return DBL_ROUND_ERROR() * pow(10.0, -DBL_DIGITS10() + 1);   // max rounding error
}

double NumConst::DBL_Min()
{
	return numeric_limits<double>::min();
}

double NumConst::DBL_Max()
{
	return numeric_limits<double>::max();
}

int NumConst::DBL_DIGITS10()
{
	return numeric_limits<double>::digits10;  // number of significant decimal digits in mantissa (numbers after floating point)
}

double NumConst::DBL_ROUND_ERROR()
{
	return numeric_limits<double>::round_error();  // max rounding error in units of the last significant digit
}

