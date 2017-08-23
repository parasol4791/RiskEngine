#include <iostream>
#include "PayOffs/PayOffEuropeanCall.h"
#include "Payoffs/InstrOptionVanilla.h"

#include <time.h>

using namespace std;

int main()
{
	PayOffEuropeanCall call1(100.0);
	InstrOptionVanilla callOpt(call1, 0.5);

	double callPayoff = callOpt.computePayoff(101.0);
	cout << callPayoff << endl;
	
	size_t i;

	
	

	int gg;
	cin >> gg;
}
