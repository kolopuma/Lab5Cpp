#pragma once
#include <stdexcept>
class CacheOverflowException :public std::exception
{
public:
	CacheOverflowException() {}
};

