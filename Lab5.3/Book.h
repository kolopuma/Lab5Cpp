#pragma once
#include <string>
class Book
{
public:
	Book(std::string name, std::string author, int year);
	std::string getName() const;
	std::string getAuthor() const;
	int getYear() const;
private:
	std::string name_;
	std::string author_;
	int year_;
};