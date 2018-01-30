#pragma once
#include "ClassManagement\Taggable_I.h"
#include "Payoffs\PayOff_I.h"
#include "Utils\Memory.h"
#include <memory>
#include "MarketData\Market.h"

namespace DKRiskEngine
{

	class Instrument_I : public Taggable_I
	{
	public:
		DefineSharedPtr(Instrument_I)

		Instrument_I(
			const PayOff_I& payOff,
			const std::string& ccy,
			const std::string& id = ""
		);

		virtual ~Instrument_I();

		virtual void checkSanity(const Market::CPtr& market) const = 0;

		double computePayoff(double spot) const;

		std::shared_ptr<PayOff_I> getPayOff() const { return payOff_m; }

	private:
		PayOff_I::Ptr payOff_m;
	};

}

