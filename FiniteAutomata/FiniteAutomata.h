/******************************************************************
一个用来生成TCT自动工具箱所用的ADS文件的小工具。
******************************************************************/


#ifndef FiniteAutomata_H
#define FiniteAutomata_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <assert.h>


typedef int state;
typedef int label;

struct Transition
{
	state Q0;
	label T;
	state Q1;
	Transition() :Q0(0), T(0), Q1(0) {};
	bool operator==(const Transition &D)
	{
		return (Q0 == D.Q0&&T == D.T&&Q1 == D.Q1);
	}
	bool operator!=(const Transition &D)
	{
		//return !(Q0 == D.Q0&&T == D.T&&Q1 == D.Q1);
		return !(*this==D);
	}
	bool operator<(const Transition &D)
	{
		if (Q0 == D.Q0)
		{
			return (T < D.T);
		}
		else
		{
			return (Q0 < D.Q0);
		}
	}
};

class FiniteAutomata
{
public:
	FiniteAutomata();
	FiniteAutomata(std::string str);
	~FiniteAutomata();
	FiniteAutomata& reconstruct(std::string str);
	size_t size();
	std::string FA();
	bool perform();
	bool perform(std::string filepath);
	FiniteAutomata& clear();
	friend std::istream& operator>>(std::istream& input, FiniteAutomata& D);  //重载输入运算符
	friend std::ostream& operator<<(std::ostream& output, FiniteAutomata& D); //重载输出运算符
	bool operator==(FiniteAutomata& D);                                       //重载等于运算符
	bool quite;
private:
	bool analyze(std::string& str);
	bool check(const state& t);
	std::vector<Transition> Trans;
	//std::vector<state> initial;
	std::vector<state> F;
	std::vector<state> Q;
	std::vector<label> V;
	std::string theFA;
	size_t num_state;
	//static int g_nStatus;
};



#endif // !FiniteAutomata_H

