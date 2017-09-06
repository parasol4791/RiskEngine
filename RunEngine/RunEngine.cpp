#include <iostream>
#include "PayOffs/PayOffEuropeanCall.h"
#include "Payoffs/InstrOptionVanilla.h"
#include "MarketData/Market.h"

#include <time.h>

using namespace std;
using namespace DKRiskEngine;

int main()
{
	Market market;

	string ccy("usd");
	market.addSpot(100.0, ccy);
	market.addFlatCurve(0.015, ccy);
	market.addFlatSurface(0.2, ccy);

	string ccy1("eur");
	market.addSpot(10.0, ccy1);
	market.addFlatCurve(0.01, ccy1);
	market.addFlatSurface(0.25, ccy1);

	market.addFlatSurface(0.55, ccy);  //TODO:  add exception if a duplicate is attempted to be added

	PayOffEuropeanCall call1(100.0);
	InstrOptionVanilla callOpt(call1, 0.5);

	double callPayoff = callOpt.computePayoff(101.0);
	cout << callPayoff << endl;
	
	//size_t i;

	
	

	int gg;
	cin >> gg;
}
