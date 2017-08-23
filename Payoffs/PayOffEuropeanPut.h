#pragma once
#include "PayOff_I.h"
class PayOffEuropeanPut :
	public PayOff_I
{
public:
	PayOffEuropeanPut(double strike);
	virtual ~PayOffEuropeanPut();

	virtual PayOff_I* clone() const;
	virtual double operator()(double spot) const;

private:
	double strike_m;
};

