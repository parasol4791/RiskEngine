#include <iostream>

#include <time.h>

using namespace std;

int main()
{
	int seed(0);
	srand(seed);
	
	cout << "Max rand: " << RAND_MAX << endl;

	size_t n = 50;
	for (size_t j = 1; j < 10; ++j)
	{
		n *= 2;
		double sum(0.0);
		for (size_t i = 0; i < n; ++i)
		{
			double r = rand();
			double rr = r / RAND_MAX;
			sum += rr;
		}
		sum /= n;
		cout << "Mean [" << n << "] = " << sum << endl;
	}

	int gg;
	cin >> gg;
}
