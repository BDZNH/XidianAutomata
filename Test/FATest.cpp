#include<iostream>
#include"FA.h"
#include"RE.h"

using namespace std;

class FATestClass
{
public:
	void FA_RETest()
	{
		cout << "input a regular expression re:" << endl;
		RE re;
		cin >> re;//>>|*'a'*'b'
		cout << "re=" << re << endl;//.*'a'*'b'
		FA fa(re);
		cout << fa << endl;
	}
};

void FATest()
{
	FATestClass fat;
	fat.FA_RETest();
}