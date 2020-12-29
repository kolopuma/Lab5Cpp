#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <functional>
#include <vector>
#pragma warning(disable : 4996)
//Федоров Максим (ИВТ-3).

/*Написать код для чтения произвольного текстового файла и вывода на экран всех слов
размером более 3 букв, встречающихся в нем не менее 7 раз, в порядке убывания
частоты встречаемости (приложение А). В качестве разделителей слов рассматривать
пробел, точку, запятую, тире, двоеточие, восклицательный знак, точку с запятой.
Использовать контейнер std::map.*/
void print(std::pair<std::string, int> pair) {
	if (pair.first.length() > 3 && pair.second >= 7)
		std::cout << pair.first << " " << pair.second << std::endl;
}
int main()
{
	std::map<std::string, int> map;
	std::ifstream fin;
	fin.open("Sonnets.txt", std::ios::app);
	while (fin.peek() != EOF)
	{
		const size_t MAXLEN = 1000;
		char text[MAXLEN];
		fin.getline(text, MAXLEN);
		char* substr = std::strtok(text, ".,:!;? ");
		while (substr != 0) {
			std::string word = substr;
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);
			auto founded_word = map.find(word);
			if (founded_word == map.cend()) {
				map.insert(std::make_pair(word, 1));
			}
			else
			{
				map[word]++;
			}
			substr = std::strtok(NULL, ".,:!;? ");
		}
	}
	std::vector < std::pair<std::string, int> > words(map.begin(), map.end());
	std::sort(words.begin(), words.end(), [](auto lefths, auto righths) 
		{
			return lefths.second > righths.second; 
		});
	std::for_each(words.begin(), words.end(), print);
}


