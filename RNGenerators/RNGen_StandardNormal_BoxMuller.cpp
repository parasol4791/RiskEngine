#include "RNGen_StandardNormal_BoxMuller.h"
#include "RNGen_Uniform.h"
//#include "Maths/MathFunctions.h"


RNGen_StandardNormal_BoxMuller::RNGen_StandardNormal_BoxMuller()
{
}

RNGen_StandardNormal_BoxMuller::~RNGen_StandardNormal_BoxMuller()
{
}

double RNGen_StandardNormal_BoxMuller::getRN() const
{
	RNGen_Uniform uniformGen;
	double u1 = uniformGen.getRN();
	double u2 = uniformGen.getRN();

	//double pi = MathFunctions::pi();
	//double first = sqrt(2*)
	double z1(0);
	return z1;
}

void RNGen_StandardNormal_BoxMuller::getRN(
	size_t n,
	std::vector<double>& rnVec
) const
{

}
