#include "Market.h"
#include "CurveFlat.h"
#include "SurfaceFlat.h"
#include "Utils\Exceptions.h"

#include <sstream>

using namespace std;
using namespace DKRiskEngine;

/////////////////
/// Class Market
//////////////////

Market::Market(double nowDate) :
	nowDate_m(nowDate),
	marketData_m()
{}

MarketData_I::CPtr Market::get(const MDTag& tag) const
{
	MDMap::const_iterator iter = marketData_m.find(tag);
	if (iter != marketData_m.end())
		return iter->second;
	else
	{
		stringstream ss;
		ss << "Market data " << tag.toString() << " is not found";
		throwException(ss.str());
		return NULL;
	}
}

Scalar::CPtr
Market::getSpot(const MDTag& tag) const
{
	MarketData_I::CPtr md = get(tag);
	Scalar::CPtr spot = dynamic_pointer_cast<const Scalar>(md);
	if (spot)
		return spot;
	else
	{
		stringstream ss;
		ss << "Market data object " << tag.toString() << " is not Spot";
		throwException(ss.str());
		return NULL;
	}
}

void Market::add(
	const MDTag& tag,
	const MarketData_I& md
)
{
	const MarketData_I::CPtr newMD(md.clone());
	add(tag, newMD);
}

void Market::add(
	const MDTag& tag,
	const MarketData_I::CPtr& md
)
{
	marketData_m.insert(pair<MDTag, MarketData_I::CPtr>(tag, md));
}

void
Market::addSpot(
	const double spot,
	const std::string& ccy,
	const std::string& id
)
{
	MDTag tag = MDTag::makeTag(MDType_Spot, ccy, id);
	Scalar::CPtr spotObj(new Scalar(spot));
	add(tag, spotObj);
}

void
Market::addFlatCurve(
	const double rate,
	const string& ccy,
	const string& id
)
{
	MDTag tag = MDTag::makeTag(MDType_YieldCurve, ccy, id);
	CurveFlat::CPtr curve(new CurveFlat(rate));
	add(tag, curve);
}


void
Market::addFlatSurface(
	const double sigma,
	const string& ccy,
	const string& id
)
{
	MDTag tag = MDTag::makeTag(MDType_VolSurface, ccy, id);
	SurfaceFlat::CPtr surface(new SurfaceFlat(sigma));
	add(tag, surface);
}
