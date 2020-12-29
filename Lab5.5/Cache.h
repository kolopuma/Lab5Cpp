#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "CacheOverflowException.h"
#include "SymbolsContraster.h"
template <class T>
class Cache
{
public:
	Cache() {
		vector.reserve(10);
	}
	void put(T elem) {
		vector.push_back(elem);
	}
	void operator+=(T elem) {
		vector.push_back(elem);
	}
	bool contains(T elem) {
		return std::find(vector.begin(), vector.end(), elem) != vector.end();
	}
private:
	std::vector<T> vector;
};
template<>
class Cache<std::string> {
public:
	Cache() {
		vector.reserve(10);
	}
	void put(std::string elem) {
		if (vector.size() < 100) {
			vector.push_back(elem);
		}
		else
		{
			throw new CacheOverflowException;
		}
	}
	void operator+=(std::string elem) {
		vector.push_back(elem);
	}
	bool contains(std::string elem) {
		SymbolsContraster comparer(elem);
		return std::find_if(vector.begin(), vector.end(), comparer) != vector.end();
	}
private:
	std::vector<std::string> vector;
};

