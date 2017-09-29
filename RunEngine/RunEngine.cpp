#include <iostream>
#include <iomanip>
#include "PayOffs/PayOffEuropeanCall.h"
#include "Payoffs/InstrOptionVanilla.h"
#include "MarketData/Market.h"
#include "Utils\Exceptions.h"
#include "Maths\DistributionNormal.h"
#include "Maths\MathFunctions.h"

#include <time.h>
#include <iomanip>

using namespace std;
using namespace DKRiskEngine;

int main()
{
	try
	{
		double a;
		cin >> a;
		//double a = 1.0e+3;
		double eps = 5.0e-15*a;
		double aplus = a + eps;
		double aminus = a - eps;
		

		cout << std::setprecision(38) << a << endl;
		cout << aminus << endl;
		cout << aplus << endl;
		cout << "eps: " << eps << endl;

		cout << "std::equal: " << MathFunctions::equalToEps(aplus, aminus) << endl;

		Market market;

		string ccy("usd");
		market.addSpot(100.0, ccy);
		market.addFlatCurve(0.015, ccy);
		market.addFlatSurface(0.2, ccy);

		string ccy1("eur");
		market.addSpot(10.0, ccy1);
		market.addFlatCurve(0.01, ccy1);
		market.addFlatSurface(0.25, ccy1);



		//throwException("Something's wrong");

		market.addFlatSurface(0.55, ccy);  //TODO:  add exception if a duplicate is attempted to be added

		PayOffEuropeanCall call1(100.0);
		InstrOptionVanilla callOpt(call1, 0.5);
		//market.getSpot(callOpt.get);

		DistributionNormal norm(1.0, 3.0);
		size_t dLimit = numeric_limits<long double>::digits10+1;
		cout << setprecision(dLimit);
		for (int i = -38; i < 39; ++i)
			cout << i << "\t" << norm.pdf(i) << "\t" << norm.cdf(i) << endl;



		double callPayoff = callOpt.computePayoff(101.0);
	//	cout << callPayoff << endl;

		//size_t i;

	} 
	catch (...)
	{
		handleExceptions();
	}
	
	

	int gg;
	cin >> gg;
}
