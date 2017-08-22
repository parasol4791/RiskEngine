#pragma once
#include "RNGen_I.h"
class RNGen_StandardNormal_BoxMuller :
	public RNGen_I
{
public:
	RNGen_StandardNormal_BoxMuller(int seed = 0);
	virtual ~RNGen_StandardNormal_BoxMuller();

	virtual double getRN() const;
	virtual void getRN(
		size_t n,
		std::vector<double>& rnVec
	) const;

private:
	void getStNorm(
		double& z1,
		double& z2,
		size_t n = 2 // how many RNs to return (1 or 2)
	) const;

};


	

