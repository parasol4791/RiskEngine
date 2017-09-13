#pragma once

namespace DKRiskEngine
{

	class DistributionNormal
	{
	public:
		DistributionNormal(
			double mu = 0.0,
			double sigma = 1.0
		);

		double pdf(double x) const;
		double cdf(double x) const;


	private:
		double mu_m;
		double sigma_m;

		double makeStandard(double x) const;
		double cdfStandard(double x) const;
	};

}

