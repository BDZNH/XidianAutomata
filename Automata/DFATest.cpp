#include "DFA.h"
#include <iostream>
using namespace std;

void DFATest1()
{
	/*
	初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)
	状态说明   状态    输入字符
						0   1
		start	q0      q1  q0
				q1      q2  q0
				q2      q3  q0
		accept 	q3      q3  q0 
	*/
	DFA_components dfa_com1;

	// StateSet S  开始状态集
	dfa_com1.S.set_domain(10);
	dfa_com1.S.add(0);
	//dfa_com1.S.add(1);

	// StateSet F  结束状态集
	dfa_com1.F.set_domain(10);
	dfa_com1.F.add(3);
	/*dfa_com1.F.add();
	dfa_com1.F.add();*/
	/*int i = 10;
	while (i--)
	{
		dfa_com1.Q.allocate();
	}*/

	dfa_com1.Q.set_domain(10);

	dfa_com1.T.set_domain(10);
	dfa_com1.T.add_transition(0, '0', 1);
	dfa_com1.T.add_transition(1, '0', 2);
	dfa_com1.T.add_transition(2, '0', 3);
	dfa_com1.T.add_transition(3, '0', 3);
	dfa_com1.T.add_transition(0, '1', 0);
	dfa_com1.T.add_transition(1, '1', 0);
	dfa_com1.T.add_transition(2, '1', 0);
	dfa_com1.T.add_transition(3, '1', 0);
	dfa_com1.T.add_transition(1, '1', 4);
	dfa_com1.T.add_transition(2, '0', 5);

	dfa_com1.T.set_domain(10);
	DFA dfa1(dfa_com1);
	cout << dfa1 << endl;
	dfa1.min_Brzozowski();
	cout << dfa1 << endl;
	DFA dfa2(dfa1);
	cout << dfa2 << endl;
	dfa2.min_Brzozowski();
	cout << dfa2 << endl;
}

void DFATest()
{
	DFATest1();

	//cout << /*dfa1.S*/ << endl;

}