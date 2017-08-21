#include "RNGen_StandardNormal_BoxMuller.h"
#include "RNGen_Uniform.h"
#include "Maths/MathFunctions.h"


RNGen_StandardNormal_BoxMuller::RNGen_StandardNormal_BoxMuller()
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
	size_t single = n / 2;
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
	RNGen_Uniform uniformGen;
	double u1 = uniformGen.getRN();
	double u2 = uniformGen.getRN();

	double twoPi = 2.0 * MathFunctions::pi();
	double first = sqrt(twoPi*u1);
	double arg = twoPi * u2;

	z1 = first * sin(arg);
	if (n<2)
		z2 = first * cos(arg);
}
