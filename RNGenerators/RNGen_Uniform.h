#pragma once
#include "RNGen_I.h"
class RNGen_Uniform :
	public RNGen_I
{
public:
	RNGen_Uniform(int seed = 0);
	virtual ~RNGen_Uniform();

	virtual double getRN() const;
	virtual void getRN(
		size_t n,
		std::vector<double>& rnVec
	) const;
};

