#pragma once
#include <string>
#include <vector>
class Book
{
public:
	Book(std::string name, std::string author, int year);
	std::string getName() const;
	std::string getAuthor() const;
	bool operator>(int number) {
		return this->year_ > number;
	}
	bool operator<(int number) {
		return this->year_ < number;
	}
	static std::vector<int> YearsVector(std::vector<Book*> books) {
		std::vector<int> years;
		for (int i = 0; i < books.size(); i++) {
			years.push_back(books[i]->year_);
		}
		return years;
	}
	int getYear() const;
private:
	std::string name_;
	std::string author_;
	int year_;
};

