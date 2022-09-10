#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
#include<time.h>
#include<map>

using namespace std;

//������� �� ������� ��� ��������� �������� � ������������ 
//���������


void task1()
{
	list<int> l;
	l.resize(100);
	generate_n(begin(l), 100, []() {return rand() % 10 + 1; });
	list<int>::iterator it = max_element(begin(l), end(l));

	copy(begin(l), end(l), ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	l.remove(*it);

	copy(begin(l), end(l), ostream_iterator<int>(cout, " "));
}

//����� ����� ��������� �������, ������������� ����� 
//����������� � ������������ ����������

void task2()
{
	srand(time(0));
	vector<int> l;
	l.resize(10);
	generate_n(begin(l), 10, []() {return rand() % 10 + 1; });
	vector<int>::iterator it_max = max_element(begin(l), end(l));
	vector<int>::iterator it_min = min_element(begin(l), end(l));

	copy(begin(l), end(l), ostream_iterator<int>(cout, " "));

	if (it_max > it_min) swap(it_max, it_min);
	cout << endl << accumulate(it_max + 1, it_min, 0) << endl;
}

//����������� �����, � ������� �������� :
//- �������� ������
//- �������� ������
//- �������� ����� - ���������
//����������� multimap, � ������� ����� ��������� ������
//����������.������������ �������� ��� ��������� � multimap
//������ ����������� �� ������, � �������� ����� ������ ��
//�������� ������.

class cust
{
public:
	string country;
	string city;
	string customer;

	cust(const string& country, const string& city, const string& customer)
	{
		this->country = country;
		this->city = city;
		this->customer = customer;
	}

	friend ostream& operator<< (ostream& out, const cust& c);
	friend bool operator< (const cust& obj1, const cust& obj2);
};

ostream& operator<< (ostream& out, const cust& c)
{
	out << c.country << " " << c.city << " " << c.customer;
	return out;
}

bool operator< (const cust& obj1, const cust& obj2)
{
	return(obj1.country < obj2.country);
}

void task3()
{
	multimap<cust, int> customer;
	customer.insert(make_pair(cust("Russia", "Tymen", "Vkusno i tochka"), 1000)); //���� � �� ��
	customer.emplace(cust("Russia", "Tymen", "KFC"), 2000); //���� � �� ��
	customer.emplace(cust("Belarus", "Minsk", "Kroshka Kartoshka"), 4000); //���� � �� ��

	for_each(begin(customer), end(customer),
		[](const auto& val)
		{
			cout << val.first << endl;
			cout << val.second << endl;
		});
}

//����� ������ ��������� �����.���������� ������� 2 �������
//� ����������� � 1 - �� ������, �� 2 - �� �������� ��������
//�������

void task4()
{
	vector<int> v;
	vector<int> res1;
	vector<int> res2;
	v.resize(10);
	generate_n(begin(v), 10, []() {return rand() % 10 + 1; });
	copy(begin(v), end(v), ostream_iterator<int>(cout, " "));
	cout << endl;

	copy_if(begin(v), end(v), back_inserter(res1),
		[](int val)
		{
			return val % 2 == 0;
		});
	copy(begin(res1), end(res1), ostream_iterator<int>(cout, " "));
	cout << endl;

	copy_if(begin(v), end(v), back_inserter(res2),
		[](int val)
		{
			return val % 2 != 0;
		});
	copy(begin(res2), end(res2), ostream_iterator<int>(cout, " "));
	cout << endl;

	back_insert_iterator<vector<int>> it(v); // ��� ������� � ��������� (� �������� ���� ������)
	it = 5; //��������� 5 � v
}

//�������� ����� ���������� ����������� ���������� � ��������� sort.
//��� ����� ������� ������ ���������� �������� �������(��������, 10000 ���������), 
//�������� ����� ���������� ����� ������� ������� ����������� ���������� � ���������� sort.

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