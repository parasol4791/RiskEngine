#pragma once
#include "RNGen_I.h"
class RNGen_StandardNormal_BoxMuller :
	public RNGen_I
{
public:
	RNGen_StandardNormal_BoxMuller();
	virtual ~RNGen_StandardNormal_BoxMuller();

	virtual double getRN() const;
	virtual void getRN(
		size_t n,
		std::vector<double>& rnVec
	) const;
};

