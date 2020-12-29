#pragma once
#include <functional>
#include "Book.h"
class BookSorter
{
public:
	BookSorter(int key) {
		key_ = key;
	}
	BookSorter() {
		key_ = 2;
	}
	bool operator()(Book* book1, Book* book2) {
		if (key_ == 1) {
			return book1->getAuthor() < book2->getAuthor();
		}
		return book1->getName() < book2->getName();
	}
private:
	int key_;
};

