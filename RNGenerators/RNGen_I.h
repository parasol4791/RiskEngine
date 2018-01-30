#pragma once
#include <vector>

namespace DKRiskEngine
{

	class RNGen_I
	{
	public:
		RNGen_I(int seed = 0);
		virtual ~RNGen_I();

		virtual double getRN() const = 0;
		virtual void getRN(
			size_t n,
			std::vector<double>& rnVec
		) const = 0;

	protected:
		int seed_m;
	};

}

