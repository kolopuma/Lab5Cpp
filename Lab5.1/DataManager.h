#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
template <class T>
class DataManager
{
public:
	DataManager() {
		max_size_ = 64;
		count_ = 0;
		mas = new T[64];
	}
	~DataManager() {
		delete[] mas;
	}
	void push(T elems[], size_t n) {
		for (int i = 0; i < n; i++) {
			push(elems[i]);
		}
	}

	void push(T elem) {
				if (count_ == max_size_) {
					std::ofstream out;
					out.open("dump.dat", std::ios::app);
					for (int i = 0; i < count_; i++) {
						out << mas[i] << std::endl;
					}
					out.close();
					count_ = 0;
				}
		mas[count_] = elem;
		count_++;
				
		Sort(mas, count_);

	}
	void Sort(T mas[],int count_)
	{
			/* Отсортируем массив по убыванию */
			for (int i = 1; i < count_; ++i)
			{
				for (int r = 0; r < count_ - i; r++)
				{
					if (mas[r] < mas[r + 1])
					{
						// Обмен местами
						double temp = mas[r];
						mas[r] = mas[r + 1];
						mas[r + 1] = temp;
					}
				}
			}
	}
	void print() {
		std::copy(mas, mas+count_, std::ostream_iterator<T>(std::cout, " "));
	}
	T peek() {
		return mas[count_-1];
	}
	T pop() {
		if (count_ != 0) {
			if (count_ < 2 ) {
				T buff = mas[count_  - 1];	
				for (int i = count_ -1; i < count_; i++) {
					mas[i - 1] = mas[i];
				}
				count_--;	
				chekEmpty();
				return buff;
			}
			else
			{
				T buff = mas[count_ -2];	
				for (int i = count_ - 1; i < count_; i++) {
					mas[i - 1] = mas[i];
				}
				count_--;
				chekEmpty();
				return buff;
			}
		}
	}
	void chekEmpty() {
		if (count_ == 0) {
			std::ifstream fin;
			std::ofstream fout;
			fin.open("dump.dat", std::ios::app);
			while (fin.peek() != EOF) {
				T temp;
				fin >> temp;
				buffer_vector.push_back(temp);
			}
			if (buffer_vector.size() > max_size_) {
				for (int i = 0; i < max_size_; i++) {
					mas[i] = buffer_vector[i];
				}
				fout.open("dump.dat", std::ios::app);
				for (int i = max_size_; i < buffer_vector.size(); i++) {
					fout << buffer_vector[i] << std::endl;
				}
				fout.close();
				buffer_vector.clear();
			}
			else {
				for (int i = 0; i < buffer_vector.size(); i++) {
					mas[i] = buffer_vector[i];
				}
				buffer_vector.clear();
			}
			fin.close();
			fin.open("dump.dat", std::ios::out | std::ios::trunc);
			fin.close();
		}
	}
private:
	T* mas;
	int max_size_;
	int count_;
	std::vector<T> buffer_vector;
};
template<>
class DataManager<char> {
public:
	DataManager() {
		max_size_ = 64;
		count_ = 0;
		mas = new char[64];
	}
	void push(char elem) {
		if (elem == '.' || elem == '-' || elem == ',' || elem == '?' || elem == '!' || elem == ';' || elem == ' ' || elem == ':') {
			elem = '_';
		}
		if (count_ == max_size_) {
			std::ofstream out;
			out.open("dump.dat", std::ios::app);
			for (int i = 0; i < count_; i++) {
				out << mas[i] << std::endl;
			}
			out.close();
			count_ = 0;
		}
		mas[count_] = elem;
		count_++;
		
	}
	char popUpper() {
		if (count_ != 0) {
			if (count_ < 2) {
				char buff = mas[count_ - 1];
				for (int i = count_ - 1; i < count_; i++) {
					mas[i - 1] = mas[i];
				}
				count_--;
				chekEmpty();
				return toupper(buff);
			}
			else
			{
				char buff = mas[count_ - 2];
				for (int i = count_ - 1; i < count_; i++) {
					mas[i - 1] = mas[i];
				}
				count_--;
				chekEmpty();				
				return toupper(buff);
			}
		}
	}
	char popLower() {
		if (count_ != 0) {
			if (count_ != 0) {
				if (count_ < 2) {
					char buff = mas[count_ - 1];
					count_--;
					chekEmpty();
					return tolower(buff);
				}
				else
				{
					char buff = mas[count_ - 2];

					count_--;
					chekEmpty();
					return tolower(buff);
				}
			}
		}
	}
	void chekEmpty() {
		if (count_ == 0) {
			std::ifstream fin;
			std::ofstream fout;
			fin.open("dump.dat", std::ios::app);
			while (fin.peek() != EOF) {
				char temp;
				fin >> temp;
				buffer_vector.push_back(temp);
			}
			if (buffer_vector.size() > max_size_) {
				for (int i = 0; i < max_size_; i++) {
					mas[i] = buffer_vector[i];
				}
				fout.open("dump.dat", std::ios::app);
				for (int i = max_size_; i < buffer_vector.size(); i++) {
					fout << buffer_vector[i] << std::endl;
				}
				fout.close();
				buffer_vector.clear();
			}
			else {
				for (int i = 0; i < buffer_vector.size(); i++) {
					mas[i] = buffer_vector[i];
				}
				buffer_vector.clear();
			}
			fin.close();
			fin.open("dump.dat", std::ios::out | std::ios::trunc);
			fin.close();
		}
	}
	void print() {
		std::copy(mas, mas + count_, std::ostream_iterator<char>(std::cout, " "));
	}
private:
	char* mas;
	int max_size_;
	int count_;
	std::vector<char> buffer_vector;
};

