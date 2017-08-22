#include <iostream>
#include "RNGenerators/RNGen_Uniform.h"
#include "RNGenerators/RNGen_StandardNormal_BoxMuller.h"

#include <time.h>

using namespace std;

int main()
{
	size_t i;

	RNGen_Uniform rnUniform;
	vector<double> rnU;
	rnUniform.getRN(5, rnU);
	cout << "Uniform RNs:\n";
	for (i = 0; i < rnU.size(); ++i)
		cout << rnU[i] << endl;

	RNGen_StandardNormal_BoxMuller bmGen;
	vector<double> rnN;
	bmGen.getRN(5, rnN);
	cout << "Standard Normal RNs (Box-Muller):" << endl;
	for (size_t i = 0; i < rnN.size(); ++i)
		cout << rnN[i] << endl;

	bmGen.getRN(20000, rnN);
	cout << "Standard Normal RNs (Box-Muller) mean:" << endl;
	double sum = 0.0;
	for (size_t i = 0; i < rnN.size(); ++i)
		sum += rnN[i];
	sum /= rnN.size();
	cout << sum << endl;
	

	int gg;
	cin >> gg;
}
