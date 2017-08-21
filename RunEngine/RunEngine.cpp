#include <iostream>
#include "RNGenerators/RNGen_StandardNormal_BoxMuller.h"

#include <time.h>

using namespace std;

int main()
{
	RNGen_StandardNormal_BoxMuller bmGen;
	vector<double> rns;
	bmGen.getRN(5, rns);

	for (size_t i = 0; i < rns.size(); ++i)
		cout << rns[i] << endl;
	

	int gg;
	cin >> gg;
}
