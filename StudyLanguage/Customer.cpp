#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <map>

using namespace std;

class Customer {
	//string country, city, name;
public:
	string country, city, name;
	Customer(const string& country, const string& city, const string& name) {
		this->country = country;
		this->city = city;
		this->name = name;
	}
	friend bool operator<(const Customer& obj1, const Customer& obj2);
	friend ostream& operator<<(ostream& os, const Customer& customer);
};

bool operator<(const Customer& obj1, const Customer& obj2) {
	return obj1.country < obj2.country;
}

ostream& operator<<(ostream& os, const Customer& customer) {
	os << customer.country << " ; " << customer.city << " ; " << customer.name;
	return os;
}

bool myPred(const Customer& obj1, const Customer& obj2) {
	return obj1.country < obj2.country;
}

void task3() {
	multimap<Customer, int> customer;
	//customer.insert(make_pair({ "Russia", "Tyumen", "Gazprom" }, 1000));
	customer.insert(make_pair(Customer("Russia", "Tyumen", "Gazprom"), 1000));
	customer.emplace(Customer("Russia", "Tyumen", "Transneft"), 5000);
	customer.emplace(Customer("Germany", "Moscow", "Deutch"), 15000);
	customer.emplace(Customer("USA", "Moscow", "BP"), 25000);

	for_each(begin(customer), end(customer),
		[](const auto& val)
		{
			cout << val.first << " " << val.second << endl;
		});
}