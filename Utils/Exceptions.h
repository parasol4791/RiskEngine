#pragma once
#include <stdexcept>
#include <string>

namespace DKRiskEngine
{

	void throwExceptionFunc(
		const std::string& msg,
		const char* file,
		const char* function,
		const size_t line
	);

	void handleExceptions();

#define throwException(str)   throwExceptionFunc(str, __FILE__, __FUNCTION__, __LINE__)


	class Exception : public std::exception
	{
	public:
		Exception(const std::string& str);
		virtual ~Exception();

		virtual const char* what() const throw();

	protected:
		std::string msg_m;
	};

}

