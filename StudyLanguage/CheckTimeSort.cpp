#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
#include<time.h>
#include<map>

using namespace std;

void sort_(vector<int>& vec)
{
	for (size_t i = 0; i < vec.size() - 1; i++)
	{
		for (size_t j = 0; j < vec.size() - i - 1; j++)
		{
			if (vec[j] > vec[j + 1])
			{
				swap(vec[j], vec[j + 1]);
			}
		}
	}
}

void task5()
{
	vector<int> vec;
	vec.resize(10000);
	generate_n(begin(vec), 10000, []() {return rand() % 10000000 + 1; });
	vector<int>vec2 = vec;

	//copy(begin(vec), end(vec), ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	int time1 = clock();
	sort(begin(vec), end(vec));
	//copy(begin(vec), end(vec), ostream_iterator<int>(cout, " "));
	int time2 = clock();
	cout << (time2 - time1) / 1000.0 << endl;

	time1 = clock();
	sort_(vec2);
	//copy(begin(vec), end(vec), ostream_iterator<int>(cout, " "));
	time2 = clock();
	cout << (time2 - time1) / 1000.0 << endl;

}