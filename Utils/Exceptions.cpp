#include "Exceptions.h"
#include <sstream>
#include <iostream>

using namespace std;
using namespace DKRiskEngine;


void DKRiskEngine::throwExceptionFunc(
	const string& msg,
	const char* file,
	const char* function,
	const size_t line
)
{
	stringstream ss;
	ss << "FILE: " << file << "\nFUNCTION: " << function << "\nLINE: " << line << "\n";
	ss << "ERROR: \"" << msg << "\"\n";

	throw Exception(ss.str());
}

void DKRiskEngine::handleExceptions()
{
	try
	{
		throw;
	}
	catch (const Exception& e)
	{
		cout << e.what();
	}
	catch (const std::exception& e1)
	{
		cout << e1.what();
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	catch (...)
	{
		cout << "Unknown exception.";
	}
}

Exception::Exception(const string& str) :
	exception(),
	msg_m(str)
{}

Exception::~Exception() {}

const char*
Exception::what() const throw()
{
	return msg_m.c_str();
}

