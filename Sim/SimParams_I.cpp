#include "SimParams_I.h"

using namespace DKRiskEngine;

SimParams_I::SimParams_I() {}
SimParams_I::~SimParams_I() {}


SimParamsMC::SimParamsMC(
	size_t paths,
	size_t timesteps,
	size_t seed
) :
	paths_m(paths),
	timesteps_m(timesteps),
	seed_m(seed)
{}

size_t SimParamsMC::getPaths() const
{
	return paths_m;
}

size_t SimParamsMC::getTimesteps() const
{
	return timesteps_m;
}

size_t SimParamsMC::getSeed() const
{
	return seed_m;
}