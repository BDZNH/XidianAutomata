#include "DFA.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void DFA_usefulf1();
void DFA_usefulf2();
void minDFATest3();

void DFA_usefulf()
{
	//DFA_usefulf1();
	//DFA_usefulf2();
	minDFATest3();
}



void DFA_usefulf1()
{
	/*
	初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)
	状态说明   状态    输入字符 
						0      1
		start	q0      q2     q1
		sink	q1      q1     q1
		        q2      q3     q1
		accept  q3      q3     q1



	预期结果 

	状态说明   状态        输入字符
						  0         1
		start	q0        q1        
		accept  q1        q2      
		accept  q2        q2

	或者：
*/
	DFA_components dfa_com1;

	// StateSet S  开始状态集
	dfa_com1.S.set_domain(10);
	dfa_com1.S.add(0);

	// StateSet F  结束状态集
	dfa_com1.F.set_domain(10);
	dfa_com1.F.add(3);

	int i = 10;
	while (i--)
	{
		dfa_com1.Q.allocate();
	}

	//dfa_com1.Q.set_domain(10);

	dfa_com1.T.set_domain(10);
	dfa_com1.T.add_transition(0, '0', 2);
	dfa_com1.T.add_transition(0, '1', 1);
	dfa_com1.T.add_transition(1, '0', 1);
	dfa_com1.T.add_transition(1, '1', 1);
	dfa_com1.T.add_transition(2, '0', 3);
	dfa_com1.T.add_transition(2, '1', 1);
	dfa_com1.T.add_transition(3, '0', 3);
	dfa_com1.T.add_transition(3, '1', 1);

	//实例化一个DFA对象
	DFA dfa1(dfa_com1);
	cout << "\n\n****************************************************\n\n" << std::flush;
	cout << dfa1 << endl;
	cout << " is the DFA Usefulf ?: " << dfa1.Usefulf() << endl;
	dfa1.usefulf();
	cout << dfa1 << endl;
	cout << " is the DFA Usefulf ?: " << dfa1.Usefulf() << endl;
}

void DFA_usefulf2()
{
	/*
		初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)
		状态说明   状态    输入字符 (《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 141 fig. 5-4)
							0      1
			start	q0      q1     q2
					q1      q0     q3
			accept  q2      q4     q5
			accept  q3      q4     q5
			accept  q4      q4     q5
			sink	q5      q5     q5


		预期结果 《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 153 fig. 5-6

		状态说明   状态        输入字符
							  0         1
			start	q0        q0        q1
			accept  q1        q1        

	*/

	DFA_components dfa_com1;

	// StateSet S  开始状态集
	dfa_com1.S.set_domain(10);
	dfa_com1.S.add(0);

	// StateSet F  结束状态集
	dfa_com1.F.set_domain(10);
	dfa_com1.F.add(2);
	dfa_com1.F.add(3);
	dfa_com1.F.add(4);

	int i = 10;
	while (i--)
	{
		dfa_com1.Q.allocate();
	}

	//dfa_com1.Q.set_domain(10);

	dfa_com1.T.set_domain(10);
	dfa_com1.T.add_transition(0, '0', 1);
	dfa_com1.T.add_transition(0, '1', 2);
	dfa_com1.T.add_transition(1, '0', 0);
	dfa_com1.T.add_transition(1, '1', 3);
	dfa_com1.T.add_transition(2, '0', 4);
	dfa_com1.T.add_transition(2, '1', 5);
	dfa_com1.T.add_transition(3, '0', 4);
	dfa_com1.T.add_transition(3, '1', 5);
	dfa_com1.T.add_transition(4, '0', 4);
	dfa_com1.T.add_transition(4, '1', 5);
	dfa_com1.T.add_transition(5, '0', 5);
	dfa_com1.T.add_transition(5, '1', 5);

	//实例化一个DFA对象
	DFA dfa1(dfa_com1);
	cout << "\n\n****************************************************\n\n" << std::flush;
	cout << dfa1 << endl;
	cout << " is the DFA Usefulf ?: " << dfa1.Usefulf() << endl;
	dfa1.usefulf();
	cout << dfa1 << endl;
	cout << " is the DFA Usefulf ?: " << dfa1.Usefulf() << endl;

}


void minDFATest3()
{
	DFA_components dfa_com1;

	// StateSet S  开始状态集
	dfa_com1.S.set_domain(5);
	dfa_com1.S.add(0);

	// StateSet F  结束状态集
	dfa_com1.F.set_domain(5);
	dfa_com1.F.add(3);
	dfa_com1.F.add(4);

	int i = 5;
	while (i--)
	{
		dfa_com1.Q.allocate();
	}

	dfa_com1.T.set_domain(5);
	dfa_com1.T.add_transition(0, '0', 4);
	dfa_com1.T.add_transition(0, '1', 2);
	dfa_com1.T.add_transition(1, '0', 2);
	dfa_com1.T.add_transition(1, '1', 2);
	dfa_com1.T.add_transition(2, '0', 4);
	dfa_com1.T.add_transition(2, '1', 2);
	dfa_com1.T.add_transition(3, '0', 2);
	dfa_com1.T.add_transition(3, '1', 3);
	dfa_com1.T.add_transition(4, '0', 4);
	dfa_com1.T.add_transition(4, '1', 4);

	//实例化一个DFA对象
	DFA dfa1(dfa_com1);
	cout << "\n************ DFA\n" << std::flush;
	cout << dfa1 << endl;

	cout << " is the DFA Usefulf ?: " << dfa1.Usefulf() << endl;
	dfa1.usefulf();  // 没有删除1,3 ？
	cout << dfa1 << endl;
	cout << " is the DFA Usefulf ?: " << dfa1.Usefulf() << endl;

	dfa1.min_Hopcroft();
	cout << "\n************ minDFA (Hopcroft) \n" << std::flush;
	cout << dfa1 << endl;

	stringstream ss;
	ss << dfa1;
	string temp(ss.str());
	//ss >> temp;
	cout << "ss=\n" << ss.str() << endl;
	cout << "temp=\n" << temp << endl;



	//增加对其他最小化算法的测试
	DFA dfa2(dfa_com1);
	dfa2.min_Brzozowski();
	cout << "\n************ minDFA (Brzozowski)\n" << std::flush;
	cout << dfa2 << endl;

	DFA dfa3(dfa_com1);
	dfa3.usefulf();
	dfa3.min_dragon();
	cout << "\n************ minDFA (dragon) \n" << std::flush;
	cout << dfa3 << endl;

	DFA dfa4(dfa_com1);
	dfa4.usefulf();
	dfa4.min_HopcroftUllman();
	cout << "\n************ minDFA (HopcroftUllman) \n" << std::flush;
	cout << dfa4 << endl;

	DFA dfa5(dfa_com1);
	dfa5.usefulf();
	dfa5.min_Watson();
	cout << "\n************ minDFA (Watson)\n" << std::flush;
	cout << dfa5 << endl;
}