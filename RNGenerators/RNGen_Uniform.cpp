#include "RNGen_Uniform.h"

using namespace std;
using namespace DKRiskEngine;


RNGen_Uniform::RNGen_Uniform(int seed) : RNGen_I(seed)
{
}


RNGen_Uniform::~RNGen_Uniform()
{
}

double RNGen_Uniform::getRN() const
{
	double r = rand();
	return r / RAND_MAX;
}

void RNGen_Uniform::getRN(
	size_t n,
	vector<double>& rnVec
) const
{
	rnVec.resize(n);
	for (size_t i = 0; i < n; ++i)
		rnVec[i] = getRN();
}
