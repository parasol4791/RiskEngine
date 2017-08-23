#pragma once
#include "PayOff_I.h"

class PayOffEuropeanCall :
	public PayOff_I
{
public:
	PayOffEuropeanCall(double strike);
	virtual ~PayOffEuropeanCall();

	virtual PayOff_I* clone() const;
	virtual double operator()(double spot) const;

private:
	double strike_m;
};

