#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>

using namespace std;

void task4() {
	vector<int> v;
	vector<int> a;
	vector<int> b;
	v.resize(10);
	generate_n(begin(v), v.size(), []() {return rand() % 10 + 1; });
	cout << "Array 1: " << endl;
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	copy_if(begin(v), end(v), back_inserter(a), [](int val) {return val % 2 == 0; });
	cout << "\nArray a: " << endl;
	copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
	copy_if(begin(v), end(v), back_inserter(b), [](int val) {return val % 2 != 0; });
	cout << "\nArray b: " << endl;
	copy(begin(b), end(b), ostream_iterator<int>(cout, " "));
	back_insert_iterator<vector<int>> it(a);//итератор для push_back
	it = 5;
}