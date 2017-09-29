#pragma once

namespace DKRiskEngine
{

	class NumConst
	{
	public:
		NumConst() {}
		~NumConst() {}

		static int INT_Max();
		static int INT_Min();

		static double DBL_ROUND();
		static double DBL_Min();
		static double DBL_Max();
		

	private:
		static int DBL_DIGITS10();
		static double DBL_ROUND_ERROR();

	};

}

