#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void task() {
	vector<int> v;
	v.resize(100);
	generate_n(begin(v), 100, [&]() {return rand() % 10 + 1; });
	vector<int>::iterator it_min = min_element(begin(v), end(v));
	vector<int>::iterator it_max = max_element(begin(v), end(v));

	if (it_min > it_max) {
		std::swap(it_min, it_max);
	}

	std::cout << "Sum: " << accumulate(it_min + 1, it_max, 0) << std::endl;


}