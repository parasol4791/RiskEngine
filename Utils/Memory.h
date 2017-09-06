#pragma once
#include <memory>

namespace DKRiskEngine
{
#define DefineSharedPtr(T) typedef std::shared_ptr<T> Ptr; \
						   typedef std::shared_ptr<const T> CPtr;

#define DefineUniquePtr(T) typedef std::unique_ptr<T> UPtr; \
						   typedef std::unique_ptr<const T> UCPtr;


	class Memory
	{
	public:
		Memory();
		~Memory();
	};

}

