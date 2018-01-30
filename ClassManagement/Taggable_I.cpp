#include "Taggable_I.h"

using namespace DKRiskEngine;
using namespace std;

Taggable_I::Taggable_I() {}

Taggable_I::Taggable_I(
	const std::string& ccy,
	const std::string& id
) :
	ccy_m(ccy),
	id_m(id)
{}


Taggable_I::~Taggable_I() {}

const MDTag Taggable_I::makeTag(const MDataType type) const
{
	MDTag tag(type);
	tag.addCcy(ccy_m);
	tag.addID(id_m);
	return tag;
}
