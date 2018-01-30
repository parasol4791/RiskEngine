#pragma once
#include "ClassManagement\Tag.h"
#include <string>

namespace DKRiskEngine
{
	class Taggable_I
	{
	public:
		Taggable_I();
		Taggable_I(
			const std::string& ccy,
			const std::string& id
		);

		virtual ~Taggable_I();

		const MDTag virtual makeTag(const MDataType type) const;

	private:
		std::string id_m;
		std::string ccy_m;
	};

}

