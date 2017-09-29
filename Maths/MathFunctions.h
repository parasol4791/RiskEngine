#pragma once
#include "Utils\NumConst.h"

namespace DKRiskEngine
{

	class MathFunctions
	{
	public:
		MathFunctions();
		~MathFunctions();

		static double pi();
		static double e();

		static bool equalToEps(
			double d1,
			double d2,
			double eps = NumConst::DBL_ROUND()
		);
		
	};

}

