#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <Windows.h>

using namespace std;

class miracle_game {
	vector<string> words;
	bool game_state = false;
	string mask;
public:
	miracle_game() {
		ifstream file("1grams.txt");
		words.reserve(1060000);
		string buf;
		while (!file.eof()) {
			//123 привет
			getline(file, buf);
			//buf = buf.substr(buf.find(' ') + 1);
			words.push_back(buf.substr(buf.find('\t') + 1));
		}
	}

	void play_game() {
		cout << "Загадайте слово, укажите количество букв в нем: " << endl;
		int size;
		cin >> size;
		mask.clear();
		mask.resize(size, '-');
		vector<string>::iterator it = begin(words);
		while (!game_state) {
			system("cls");
			cout << mask << endl;
			cout << "Дайте подсказку - букву и ее номер: " << endl;
			char letter;
			int num;
			cin >> letter >> num;
			mask[num - 1] = letter;
			it = find_if(it, end(words),
				[&](const string& w) {
					if (w.size() != mask.size())
						return false;
					for (size_t i = 0; i < mask.size(); i++)
					{
						if (mask[i] != '-' && w[i] != mask[i])
							return false;
					}
					return true;
				});
			if (it == end(words)) {
				cout << "Такого слова не найдено." << endl;
				break;
			}
			cout << "Ваше слово " << *it << "?" << endl
				<< "1 - Да." << endl
				<< "0 - Нет." << endl;
			bool answer;
			cin >> answer;
			if (answer) {
				game_state = true;
				cout << "Угадал!" << endl;
			}


			it++;
		}
	}
};

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	miracle_game game;
	game.play_game();
}
