#pragma once
#include "Utils\Memory.h"

namespace DKRiskEngine
{

	class SimParams_I
	{
	public:
		DefineSharedPtr(SimParams_I)

		SimParams_I();
		virtual ~SimParams_I();
	};

	class SimParamsMC : public SimParams_I
	{
	public:
		DefineSharedPtr(SimParamsMC)

		SimParamsMC(
			size_t paths,
			size_t timesteps = 1,
			size_t seed = 0
		);

		size_t getPaths() const;
		size_t getTimesteps() const;
		size_t getSeed() const;

	private:
		size_t paths_m;
		size_t timesteps_m;
		size_t seed_m;
	};

}
