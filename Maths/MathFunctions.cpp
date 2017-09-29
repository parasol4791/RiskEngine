#include "MathFunctions.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>

using namespace DKRiskEngine;
using namespace std;

MathFunctions::MathFunctions()
{
}


MathFunctions::~MathFunctions()
{
}

double MathFunctions::pi()
{
	return M_PI;	// 3.14159265358979323846
}

double MathFunctions::e()
{
	return M_E;		// 2.71828182845904523536
}

bool MathFunctions::equalToEps(
	double d1,
	double d2,
	double eps
)
{
	double maxD = std::max(fabs(d1), fabs(d2));
	return (fabs(d1-d2) < eps*maxD);
}
