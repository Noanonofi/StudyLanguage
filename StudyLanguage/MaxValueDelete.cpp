#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void task() {
	list<int> l;
	l.resize(100);
	generate_n(begin(l), 100, [&]() {return rand() % 10 + 1; });
	list<int>::iterator it = max_element(begin(l), end(l));
	std::cout << "List 1: " << std::endl;
	copy(begin(l), end(l), ostream_iterator<int>(cout, " "));
	l.remove(*it);
	std::cout << "List 2: " << std::endl;
	copy(begin(l), end(l), ostream_iterator<int>(cout, " "));
}