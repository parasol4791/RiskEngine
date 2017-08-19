#pragma once
#include "PayOff_I.h"
class PayOffEuropeanPut :
	public PayOff_I
{
public:
	PayOffEuropeanPut(double strike);
	virtual ~PayOffEuropeanPut();

	virtual double operator()(double spot) const;

private:
	double strike_m;
};

