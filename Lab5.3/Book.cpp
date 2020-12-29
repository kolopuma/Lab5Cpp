#include "Book.h"
Book::Book(std::string name, std::string author, int year) {
	name_ = name;
	author_ = author;
	year_ = year;
}
std::string Book::getName() const {
	return name_;
}
std::string Book::getAuthor() const {
	return author_;
}
int Book::getYear() const {
	return year_;
}