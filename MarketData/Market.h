#pragma once
#include "MarketData_I.h"
#include "Tag.h"
#include <map>
#include <string>

namespace DKRiskEngine
{

	class Market :
		public MarketData_I
	{
	public:
		DefineSharedPtr(Market)

		typedef std::map<MDTag, MarketData_I::CPtr> MDMap;

		Market(double nowDate = 0.0);
		virtual ~Market() {}

		virtual MarketData_I* clone() const { return new Market(*this); }
		double getNowDate() const { return nowDate_m; }

		void add(
			const MDTag& tag,
			const MarketData_I& md
		);

		void add(
			const MDTag& tag,
			const MarketData_I::CPtr& md
		);

		void addSpot(
			const double spot,
			const std::string& ccy,
			const std::string& id = ""
		);

		void addFlatCurve(
			const double rate,
			const std::string& ccy,
			const std::string& id = ""
		);

		void addFlatSurface(
			const double sigma,
			const std::string& ccy,
			const std::string& id = ""
		);

	private:
		double nowDate_m;
		MDMap marketData_m;
	};

}
