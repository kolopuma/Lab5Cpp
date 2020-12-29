#pragma once
#include <string>
class SymbolsContraster
{
public:
	SymbolsContraster(std::string contraster) {
		contraster_ = contraster;
	}
	bool operator()(std::string test) {
		return contraster_[0] == test[0];
	}
private:
	std::string contraster_;
};

