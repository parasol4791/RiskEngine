#include "DistributionNormal.h"
#include "Utils\Exceptions.h"

#include <cmath>

using namespace DKRiskEngine;

DistributionNormal::DistributionNormal(
	double mu,
	double sigma
) :
	mu_m(mu),
	sigma_m(sigma)
{
	if (sigma <= 0)
		throwException("Variance of Normal distribution must be positive");
}

double DistributionNormal::pdf(double x) const
{
	double arg = makeStandard(x);
	return 0.398942280401432678 / sigma_m * exp(-0.5*arg*arg);  // 1/sqrt(2*PI)
}

double DistributionNormal::cdf(double x) const
{
	return cdfStandard(makeStandard(x));
}

double DistributionNormal::cdfStandard(double x) const
{
	double cumNorm(0.0);
	double xAbs = abs(x);
	if (xAbs > 37.0)
		cumNorm = 0.0;
	else
	{
		double exponential = exp(-xAbs*xAbs / 2.0);
		double build;
		if (xAbs < 7.07106781186547)
		{
			build = 3.52624965998911E-02 * xAbs + 0.700383064443688;
			build = build * xAbs + 6.37396220353165;
			build = build * xAbs + 33.912866078383;
			build = build * xAbs + 112.079291497871;
			build = build * xAbs + 221.213596169931;
			build = build * xAbs + 220.206867912376;
			cumNorm = exponential * build;
			build = 8.83883476483184E-02 * xAbs + 1.75566716318264;
			build = build * xAbs + 16.064177579207;
			build = build * xAbs + 86.7807322029461;
			build = build * xAbs + 296.564248779674;
			build = build * xAbs + 637.333633378831;
			build = build * xAbs + 793.826512519948;
			build = build * xAbs + 440.413735824752;
			cumNorm = cumNorm / build;
		}
		else
		{
			build = xAbs + 0.65;
			build = xAbs + 4.0 / build;
			build = xAbs + 3.0 / build;
			build = xAbs + 2.0 / build;
			build = xAbs + 1.0 / build;
			cumNorm = exponential / build / 2.506628274631;
		}
	}
	if (x > 0.0)
		cumNorm = 1.0 - cumNorm;

	return cumNorm;
}

double DistributionNormal::makeStandard(double x) const
{
	return (x - mu_m) / sigma_m;
}