#pragma once
#include "Book.h"
class BookFinder
{
public:
	BookFinder(int start_pos, int last_pos) {
		start_year_ = start_pos;
		last_year_ = last_pos;
	}
	bool operator()(Book* book) {
		return book->getYear() >= start_year_ && book->getYear() <= last_year_;
	}
private:
	int start_year_;
	int last_year_;
};

