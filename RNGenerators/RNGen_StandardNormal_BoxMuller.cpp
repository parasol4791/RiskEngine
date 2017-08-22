#include "RNGen_StandardNormal_BoxMuller.h"
#include "RNGen_Uniform.h"
#include "Maths/MathFunctions.h"
#include <vector>


RNGen_StandardNormal_BoxMuller::RNGen_StandardNormal_BoxMuller(int seed) : RNGen_I(seed)
{
}

RNGen_StandardNormal_BoxMuller::~RNGen_StandardNormal_BoxMuller()
{
}

double RNGen_StandardNormal_BoxMuller::getRN() const
{
	double z1, z2;
	getStNorm(z1, z2, 1);
	return z1;
}

void RNGen_StandardNormal_BoxMuller::getRN(
	size_t n,
	std::vector<double>& rnVec
) const
{
	rnVec.resize(n);
	size_t single = n % 2;
	size_t nPairs = (n - single) / 2;
	double z1, z2;
	for (size_t i = 0; i < nPairs; ++i)
	{
		getStNorm(z1, z2);
		rnVec[i * 2] = z1;
		rnVec[i * 2 + 1] = z2;
	}
	if (single != 0)
	{
		getStNorm(z1, z2, 1);
		rnVec[nPairs * 2] = z1;
	}
}

void RNGen_StandardNormal_BoxMuller::getStNorm(
	double& z1,
	double& z2,
	size_t n
) const
{
	std::vector<double> U;
	RNGen_Uniform uniformGen(seed_m);
	uniformGen.getRN(2, U);

	double first = sqrt(-2.0*log(U[0]));
	double arg = 2.0 * MathFunctions::pi() * U[1];

	z1 = first * sin(arg);
	if (n==2)
		z2 = first * cos(arg);
}
