#include "DFA.h"
#include <iostream>
using namespace std;

void DFATest1();
void DFATest2();
void DFATest3();
void DFATest4();

void DFATest6();
void DFATest7();

//以数字作为transition_lable
void DFA_usefulfTest_integer();

// 以字母作为transition_lable
void DFA_usefulfTest_Alphabet();

// 有一个陷阱状态的自动机
void DFA_usefulf_sink_state();

void Trans_lable();

void DFATest()
{
	DFATest1();
	//DFATest2();
	//DFATest3();
	DFATest4();
	//DFATest5();
	//DFATest6();
	//DFATest7();


	

	/*Trans_lable();
	DFA_usefulfTest_integer();
	DFA_usefulfTest_Alphabet();*/
	//DFA_usefulf_sink_state();
}


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


	// T.set_domain()
	// DTransRel::set_domain(const int r) -->
	//       --> StateTo<DTrans>::set_domain(r);
	//                 
	dfa_com1.T.set_domain(10);
	dfa_com1.T.add_transition(0, '0', 1);
	dfa_com1.T.add_transition(1, '0', 2);
	dfa_com1.T.add_transition(2, '0', 3);
	dfa_com1.T.add_transition(3, '0', 3);
	dfa_com1.T.add_transition(0, '1', 0);
	dfa_com1.T.add_transition(1, '1', 0);
	dfa_com1.T.add_transition(2, '1', 0);
	dfa_com1.T.add_transition(3, '1', 0);
	/*dfa_com1.T.add_transition(1, '1', 4);
	dfa_com1.T.add_transition(2, '0', 5);*/


	DFA dfa1(dfa_com1);
	cout << dfa1 << endl;
	/*
	DFA
		Q = [0,10)
		S = { 0 }
		F = { 3 }
		Transitions =
		0->{ '0'->1  '1'->0 }
		1->{ '0'->2  '1'->0  '1'->4 }
		2->{ '0'->3  '1'->0  '0'->5 }
		3->{ '0'->3  '1'->0 }
		4->{}
		5->{}
		6->{}
		7->{}
		8->{}
		9->{}
	*/

	dfa1.min_Brzozowski();
	cout << dfa1 << endl;
	/*
	DFA
		Q = [0,5)
		S = { 0 }
		F = { 4 }
		Transitions =
		0->{ '0'->1  '1'->2 }
		1->{ '0'->3  '1'->2 }
		2->{}
		3->{ '0'->4  '1'->2 }
		4->{ '0'->4  '1'->2 }
	*/



	DFA dfa2(dfa1);
	cout << dfa2 << endl;
	dfa2.min_Brzozowski();
	cout << dfa2 << endl;
	/*
	DFA
		Q = [0,4)
		S = { 0 }
		F = { 3 }
		Transitions =
		0->{ '0'->1 }
		1->{ '0'->2 }
		2->{ '0'->3 }
		3->{ '0'->3 }
	*/
}


void DFATest2()
{
	/*
	初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)
	状态说明   状态    输入字符
						0      1
		start	q0      q1     q0
				q1      q2,q5  q0
				q2      q3,q6  q0
		accept 	q3      q3     q4
		accept  q4      q1     q0
		{x000|x \in {0,1}*} or {x001|x \in {0,1}*}
	*/
	DFA_components dfa_com1;

	// StateSet S  开始状态集
	dfa_com1.S.set_domain(10);
	dfa_com1.S.add(0);
	//dfa_com1.S.add(1);

	// StateSet F  结束状态集
	dfa_com1.F.set_domain(10);
	dfa_com1.F.add(3);
	dfa_com1.F.add(4);
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
	dfa_com1.T.add_transition(2, '1', 4);
	dfa_com1.T.add_transition(3, '1', 4);
	dfa_com1.T.add_transition(1, '0', 5);
	dfa_com1.T.add_transition(2, '0', 6);
	dfa_com1.T.add_transition(4, '0', 2);
	dfa_com1.T.add_transition(4, '0', 1);

	DFA dfa1(dfa_com1);
	cout << dfa1 << endl;
	dfa1.min_Brzozowski();
	cout << dfa1 << endl;
	/***************************
	状态说明   状态    输入字符
					0      1
	start	q0      q1     q0
			q1      q2     q0
			q2      q3     q1
	accept 	q3      q3     q1

	{x00|x \in {0,1}*}

	***************************/



	DFA dfa2(dfa1);
	cout << dfa2 << endl;
	dfa2.min_Brzozowski();
	cout << dfa2 << endl;
	/********************
	DFA
	Q = [0,8)
	S = { 0 }
	F = { 4  7 }
	Transitions =
	0->{ '0'->1  '1'->2 }
	1->{ '0'->3  '1'->2 }
	2->{}
	3->{ '0'->4  '1'->5 }
	4->{ '0'->4  '1'->5 }
	5->{ '0'->6 }
	6->{ '0'->7  '1'->5 }
	7->{}
	**********************/
}



// usefulf() 移除自动机中不可以到达final state的状态
// 判断是不是所有的状态都可以到达final state
void DFATest3()
{
	/*
	初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)
	状态说明   状态    输入字符
						0      1
		start	q0      q1     q0
				q1      q2,q5  q0
				q2      q3,q6  q0
		accept 	q3      q3     q4
		accept  q4      q1     q0

		L(FA) = {x000|x \in {0,1}*} or {x001|x \in {0,1}*}
	*/
	DFA_components dfa_com1;

	// StateSet S  开始状态集
	dfa_com1.S.set_domain(10);
	dfa_com1.S.add(0);
	//dfa_com1.S.add(1);

	// StateSet F  结束状态集
	dfa_com1.F.set_domain(10);
	dfa_com1.F.add(3);
	dfa_com1.F.add(4);

	dfa_com1.Q.set_domain(10);

	dfa_com1.T.set_domain(10);
	dfa_com1.T.add_transition(0, '0', 1);
	dfa_com1.T.add_transition(1, '0', 2);
	dfa_com1.T.add_transition(2, '0', 3);
	dfa_com1.T.add_transition(3, '0', 3);
	dfa_com1.T.add_transition(0, '1', 0);
	dfa_com1.T.add_transition(1, '1', 0);
	dfa_com1.T.add_transition(2, '1', 4);
	dfa_com1.T.add_transition(3, '1', 4);
	dfa_com1.T.add_transition(1, '0', 5);
	dfa_com1.T.add_transition(2, '0', 6);
	dfa_com1.T.add_transition(4, '0', 1);
	dfa_com1.T.add_transition(4, '1', 0);

	DFA dfa1(dfa_com1);
	cout << dfa1 << endl;
	dfa1.usefulf();
	cout << dfa1 << endl;
}


void DFATest4()
{
	/*
	初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)
	状态说明   状态    输入字符 (《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 154  fig. 5-7   )
						0      1
		start	q0      q1     q5
				q1      q2     q5
				q2      q3     q6
				q3      q2     q4
		accept  q4      q8     q1
				q5      q1     q6
				q6      q7     q2
				q7      q6     q8
		accept  q8      q5     q5
				q9      q7     q5

	*/
	DFA_components dfa_com1;

	// StateSet S  开始状态集
	dfa_com1.S.set_domain(10);
	dfa_com1.S.add(0);
	//dfa_com1.S.add(1);

	// StateSet F  结束状态集
	dfa_com1.F.set_domain(10);
	dfa_com1.F.add(4);
	dfa_com1.F.add(8);

	dfa_com1.Q.set_domain(10);

	dfa_com1.T.set_domain(10);
	dfa_com1.T.add_transition(0, '0', 1);
	dfa_com1.T.add_transition(0, '1', 5);
	dfa_com1.T.add_transition(1, '1', 2);
	dfa_com1.T.add_transition(1, '0', 5);
	dfa_com1.T.add_transition(2, '0', 3);
	dfa_com1.T.add_transition(2, '1', 6);
	dfa_com1.T.add_transition(3, '0', 2);
	dfa_com1.T.add_transition(3, '1', 4);
	dfa_com1.T.add_transition(4, '0', 8);
	dfa_com1.T.add_transition(4, '1', 1);
	dfa_com1.T.add_transition(5, '0', 1);
	dfa_com1.T.add_transition(5, '1', 6);
	dfa_com1.T.add_transition(6, '1', 2);
	dfa_com1.T.add_transition(6, '0', 7);
	dfa_com1.T.add_transition(7, '1', 8);
	dfa_com1.T.add_transition(7, '0', 6);
	dfa_com1.T.add_transition(8, '1', 4);
	dfa_com1.T.add_transition(8, '0', 5);
	dfa_com1.T.add_transition(9, '0', 7);
	dfa_com1.T.add_transition(9, '1', 5);
	//dfa_com1.T.add_transition(5, '0', 5);

	DFA dfa1(dfa_com1);
	
	DFA dfa2(dfa1);
	dfa2.usefulf();
	cout << dfa2 << endl;
	cout << "is the DFA Usefulf? : " << dfa2.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_dragon(): " << endl;
	dfa2.min_dragon();
	cout << dfa2 << endl;
	cout << "is the DFA Usefulf? : " << dfa2.Usefulf() << endl;
	cout << "****************************************" << endl;
	/*
		Minimized by DFA::min_dragon():

		DFA
		Q = [0,3)
		S = { 0 }
		F = { 2 }
		Transitions =
		0->{ '0'->1  '1'->2 }
		1->{ ['0','1']->2 }
		2->{ '0'->2 }

		current = -1

		is the DFA Usefulf? : 1
	*/

	// DFA::min_Brzozowski
	DFA dfa3(dfa1);
	dfa3.usefulf();
	cout << dfa3 << endl;
	cout << "is the DFA Usefulf? : " << dfa3.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_Brzozowski(): " << endl;
	dfa3.min_Brzozowski();
	cout << dfa3 << endl;
	cout << "is the DFA Usefulf? : " << dfa3.Usefulf() << endl;
	cout << "****************************************" << endl;
	/*
		Minimized by DFA::min_Brzozowski():

		DFA
		Q = [0,3)
		S = { 0 }
		F = { 1 }
		Transitions =
		0->{ ['0','1']->1 }
		1->{ '0'->2 }
		2->{ '0'->2 }

		current = -1

		is the DFA Usefulf? : 0
	*/


	// Minimized by DFA::min_Hopcroft():
	DFA dfa4(dfa1);
	dfa4.usefulf();
	cout << dfa4 << endl;
	cout << "is the DFA Usefulf? : " << dfa4.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_Hopcroft(): " << endl;
	//dfa4.min_Hopcroft(); //abort min-hop.cpp 102 ***State r(split(p, q, C.iterator(L[q]), P));***
	cout << dfa4 << endl;
	cout << "is the DFA Usefulf? : " << dfa4.Usefulf() << endl;
	cout << "****************************************" << endl;



	// Minimized by DFA::min_HopcroftUllman()
	DFA dfa5(dfa1);
	dfa5.usefulf();
	cout << dfa5 << endl;
	cout << "is the DFA Usefulf? : " << dfa5.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_HopcroftUllman(): " << endl;
	dfa5.min_HopcroftUllman();
	cout << dfa5 << endl;
	cout << "is the DFA Usefulf? : " << dfa5.Usefulf() << endl;
	cout << "****************************************" << endl;
	/*
		Minimized by DFA::min_HopcroftUllman():

		DFA
		Q = [0,3)
		S = { 0 }
		F = { 2 }
		Transitions =
		0->{ '0'->1  '1'->2 }
		1->{ ['0','1']->2 }
		2->{ '0'->2 }

		current = -1

		is the DFA Usefulf? : 1

	*/



	// Minimized by DFA::min_Watson():
	DFA dfa6(dfa1);
	dfa6.usefulf();
	cout << dfa6 << endl;
	cout << "is the DFA Usefulf? : " << dfa6.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_Watson(): " << endl;
	dfa6.min_Watson();
	cout << dfa6 << endl;
	cout << "is the DFA Usefulf? : " << dfa6.Usefulf() << endl;
	cout << "****************************************" << endl;
	/*
		Minimized by DFA::min_Watson():

		DFA
		Q = [0,3)
		S = { 0 }
		F = { 2 }
		Transitions =
		0->{ '0'->1  '1'->2 }
		1->{ ['0','1']->2 }
		2->{ '0'->2 }

		current = -1

		is the DFA Usefulf? : 1

	*/


}


void DFA_usefulf_sink_state()
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
				q5      q5     q5

	
	预期结果 《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 141 fig. 5-6

	状态说明   状态        输入字符
						  0         1
		start	q0,q1     q0,q1     q2,q3,q4
		accept  q2,q3,q4  q2,q3,q4  q5
		sink    q5        q5        q5
	*/
	DFA_components dfa_com1;

	// StateSet S  开始状态集
	dfa_com1.S.set_domain(10);
	dfa_com1.S.add(0);
	//dfa_com1.S.add(1);

	// StateSet F  结束状态集
	dfa_com1.F.set_domain(10);
	dfa_com1.F.add(2);
	dfa_com1.F.add(3);
	dfa_com1.F.add(4);

	dfa_com1.Q.set_domain(10);

	dfa_com1.T.set_domain(10);
	dfa_com1.T.add_transition(0, '0', 1);
	dfa_com1.T.add_transition(0, '1', 2);
	dfa_com1.T.add_transition(1, '1', 3);
	dfa_com1.T.add_transition(1, '0', 0);
	dfa_com1.T.add_transition(2, '0', 4);
	dfa_com1.T.add_transition(2, '1', 5);
	dfa_com1.T.add_transition(3, '0', 4);
	dfa_com1.T.add_transition(3, '1', 5);
	dfa_com1.T.add_transition(4, '0', 4);
	dfa_com1.T.add_transition(4, '1', 5);
	dfa_com1.T.add_transition(5, '0', 5);
	dfa_com1.T.add_transition(5, '1', 5);

	DFA dfa1(dfa_com1);

	DFA dfa2(dfa1);
	dfa2.usefulf();
	cout << dfa2 << endl;
	cout << "is the DFA Usefulf? : " << dfa2.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_dragon(): " << endl;
	dfa2.min_dragon();
	cout << dfa2 << endl;
	cout << "is the DFA Usefulf? : " << dfa2.Usefulf() << endl;
	cout << "****************************************" << endl;
	/*
		Minimized by DFA::min_dragon():

		DFA
		Q = [0,3)
		S = { 0 }
		F = { 2 }
		Transitions =
		0->{ '0'->1  '1'->2 }
		1->{ ['0','1']->2 }
		2->{ '0'->2 }

		current = -1

		is the DFA Usefulf? : 1
	*/

	// DFA::min_Brzozowski
	DFA dfa3(dfa1);
	dfa3.usefulf();
	cout << dfa3 << endl;
	cout << "is the DFA Usefulf? : " << dfa3.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_Brzozowski(): " << endl;
	dfa3.min_Brzozowski();
	cout << dfa3 << endl;
	cout << "is the DFA Usefulf? : " << dfa3.Usefulf() << endl;
	cout << "****************************************" << endl;
	/*
		Minimized by DFA::min_Brzozowski():

		DFA
		Q = [0,3)
		S = { 0 }
		F = { 1 }
		Transitions =
		0->{ ['0','1']->1 }
		1->{ '0'->2 }
		2->{ '0'->2 }

		current = -1

		is the DFA Usefulf? : 0
	*/


	// Minimized by DFA::min_Hopcroft():
	DFA dfa4(dfa1);
	dfa4.usefulf();
	cout << dfa4 << endl;
	cout << "is the DFA Usefulf? : " << dfa4.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_Hopcroft(): " << endl;
	dfa4.min_Hopcroft(); //abort min-hop.cpp 102 ***State r(split(p, q, C.iterator(L[q]), P));***
	cout << dfa4 << endl;
	cout << "is the DFA Usefulf? : " << dfa4.Usefulf() << endl;
	cout << "****************************************" << endl;



	// Minimized by DFA::min_HopcroftUllman()
	DFA dfa5(dfa1);
	dfa5.usefulf();
	cout << dfa5 << endl;
	cout << "is the DFA Usefulf? : " << dfa5.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_HopcroftUllman(): " << endl;
	dfa5.min_HopcroftUllman();
	cout << dfa5 << endl;
	cout << "is the DFA Usefulf? : " << dfa5.Usefulf() << endl;
	cout << "****************************************" << endl;
	/*
		Minimized by DFA::min_HopcroftUllman():

		DFA
		Q = [0,3)
		S = { 0 }
		F = { 2 }
		Transitions =
		0->{ '0'->1  '1'->2 }
		1->{ ['0','1']->2 }
		2->{ '0'->2 }

		current = -1

		is the DFA Usefulf? : 1

	*/



	// Minimized by DFA::min_Watson():
	DFA dfa6(dfa1);
	dfa6.usefulf();
	cout << dfa6 << endl;
	cout << "is the DFA Usefulf? : " << dfa6.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_Watson(): " << endl;
	dfa6.min_Watson();
	cout << dfa6 << endl;
	cout << "is the DFA Usefulf? : " << dfa6.Usefulf() << endl;
	cout << "****************************************" << endl;
	/*
		Minimized by DFA::min_Watson():

		DFA
		Q = [0,3)
		S = { 0 }
		F = { 2 }
		Transitions =
		0->{ '0'->1  '1'->2 }
		1->{ ['0','1']->2 }
		2->{ '0'->2 }

		current = -1

		is the DFA Usefulf? : 1

	*/


}

void Trans_lable()
{
	//按顺序添加transition
	DTransRel T1;
	T1.set_domain(5);
	T1.add_transition(3, '0', 4);
	cout << T1.transition_on_range(3, '0') << endl;  /*4*/
	T1.add_transition(3, '1', 5);
	cout << T1.transition_on_range(3, '0') << endl;  /*4*/
	cout << T1.transition_on_range(3, '1') << endl;  /*5*/
	cout << T1 << endl;

	//不按顺序添加transition
	DTransRel T2;
	T2.set_domain(5);
	T2.add_transition(3, '1', 5);
	cout << T2.transition_on_range(3, '1') << endl;  /*5*/
	T2.add_transition(3, '0', 4);
	cout << T2.transition_on_range(3, '0') << endl;  /*5*/
	cout << T2.transition_on_range(3, '1') << endl;  /*5*/
	cout << T2 << endl;
}

void DFATest6()
{
	/*
	初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)
	去掉原DFA中的陷阱状态。

	状态说明   状态    输入字符 (《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 141 fig. 5-4 移除状态5及其边)
						0      1
		start	q0      q1     q2
				q1      q0     q3
		accept  q2      q4     
		accept  q3      q4     
		accept  q4      q4     
				           
	预期结果 《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 141 fig. 5-6
	
	状态说明   状态        输入字符
						  0         1
		start	q0,q1     q0,q1     q2,q3,q4
		accept  q2,q3,q4  q2,q3,q4  q5
		sink    q5        q5        q5
	*/
	DFA_components dfa_com1;

	// StateSet S  开始状态集
	dfa_com1.S.set_domain(10);
	dfa_com1.S.add(0);
	//dfa_com1.S.add(1);

	// StateSet F  结束状态集
	dfa_com1.F.set_domain(10);
	dfa_com1.F.add(2);
	dfa_com1.F.add(3);
	dfa_com1.F.add(4);

	dfa_com1.Q.set_domain(10);

	dfa_com1.T.set_domain(10);
	dfa_com1.T.add_transition(0, '0', 1);
	dfa_com1.T.add_transition(0, '1', 2);
	dfa_com1.T.add_transition(1, '1', 3);
	dfa_com1.T.add_transition(1, '0', 0);
	dfa_com1.T.add_transition(2, '0', 4);
	//dfa_com1.T.add_transition(2, '1', 5);
	dfa_com1.T.add_transition(3, '0', 4);
	//dfa_com1.T.add_transition(3, '1', 5);
	dfa_com1.T.add_transition(4, '0', 4);
	//dfa_com1.T.add_transition(4, '1', 5);
	//dfa_com1.T.add_transition(5, '0', 5);
	//dfa_com1.T.add_transition(5, '1', 5);


	// DFA::min_dragon();
	DFA dfa1(dfa_com1);
	cout << "****************************************" << endl;
	cout << dfa1 << endl;
	cout << "is the DFA Usefulf? : " << dfa1.Usefulf() << endl;
	cout << "****************************************" << endl;
	
	
	
	DFA dfa2(dfa1);
	dfa2.usefulf(); 
	cout << dfa2 << endl;
	cout << "is the DFA Usefulf? : " << dfa2.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_dragon(): " << endl;
	dfa2.min_dragon();
	cout << dfa2 << endl;
	cout << "is the DFA Usefulf? : " << dfa2.Usefulf() << endl;
	cout << "****************************************" << endl;
	/*
		Minimized by DFA::min_dragon():

		DFA
		Q = [0,3)
		S = { 0 }
		F = { 2 }
		Transitions =
		0->{ '0'->1  '1'->2 }
		1->{ ['0','1']->2 }
		2->{ '0'->2 }

		current = -1

		is the DFA Usefulf? : 1
	*/

	// DFA::min_Brzozowski
	DFA dfa3(dfa1);
	dfa3.usefulf(); 
	cout << dfa3 << endl;
	cout << "is the DFA Usefulf? : " << dfa3.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_Brzozowski(): " << endl;
	dfa3.min_Brzozowski();
	cout << dfa3 << endl;
	cout << "is the DFA Usefulf? : " << dfa3.Usefulf() << endl;
	cout << "****************************************" << endl;
	/*
		Minimized by DFA::min_Brzozowski():

		DFA
		Q = [0,3)
		S = { 0 }
		F = { 1 }
		Transitions =
		0->{ ['0','1']->1 }
		1->{ '0'->2 }
		2->{ '0'->2 }

		current = -1

		is the DFA Usefulf? : 0
	*/


	// Minimized by DFA::min_Hopcroft():
	DFA dfa4(dfa1);
	dfa4.usefulf();
	cout << dfa4 << endl;
	cout << "is the DFA Usefulf? : " << dfa4.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_Hopcroft(): " << endl;
	dfa4.min_Hopcroft(); //abort min-hop.cpp 102 ***State r(split(p, q, C.iterator(L[q]), P));***
	cout << dfa4 << endl;
	cout << "is the DFA Usefulf? : " << dfa4.Usefulf() << endl;
	cout << "****************************************" << endl;



	// Minimized by DFA::min_HopcroftUllman()
	DFA dfa5(dfa1);
	dfa5.usefulf();
	cout << dfa5 << endl;
	cout << "is the DFA Usefulf? : " << dfa5.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_HopcroftUllman(): " << endl;
	dfa5.min_HopcroftUllman();
	cout << dfa5 << endl;
	cout << "is the DFA Usefulf? : " << dfa5.Usefulf() << endl;
	cout << "****************************************" << endl;
	/*
		Minimized by DFA::min_HopcroftUllman():

		DFA
		Q = [0,3)
		S = { 0 }
		F = { 2 }
		Transitions =
		0->{ '0'->1  '1'->2 }
		1->{ ['0','1']->2 }
		2->{ '0'->2 }

		current = -1

		is the DFA Usefulf? : 1
	
	*/



	// Minimized by DFA::min_Watson():
	DFA dfa6(dfa1);
	dfa6.usefulf();
	cout << dfa6 << endl;
	cout << "is the DFA Usefulf? : " << dfa6.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_Watson(): " << endl;
	dfa6.min_Watson();
	cout << dfa6 << endl;
	cout << "is the DFA Usefulf? : " << dfa6.Usefulf() << endl;
	cout << "****************************************" << endl;
	/*
		Minimized by DFA::min_Watson():

		DFA
		Q = [0,3)
		S = { 0 }
		F = { 2 }
		Transitions =
		0->{ '0'->1  '1'->2 }
		1->{ ['0','1']->2 }
		2->{ '0'->2 }

		current = -1

		is the DFA Usefulf? : 1
	
	*/
}

void DFATest7()
{
	/*
	样例来自：  https://www.cnblogs.com/wendellyi/p/3695489.html
	初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)

	状态说明   状态    输入字符 (《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 141 fig. 5-4 移除状态5及其边)
						0      1
		start	q0      q1     q2
				q1      q4     q2
		accept  q2      q1     q3
		accept  q3      q6     q3
		accept  q4      q4     q5
		accept  q5      q6
		accept  q6      q4     q5


	*/
	DFA_components dfa_com1;

	// StateSet S  开始状态集
	dfa_com1.S.set_domain(10);
	dfa_com1.S.add(0);
	//dfa_com1.S.add(1);

	// StateSet F  结束状态集
	dfa_com1.F.set_domain(10);
	dfa_com1.F.add(3);
	dfa_com1.F.add(4);
	dfa_com1.F.add(5);
	dfa_com1.F.add(6);

	dfa_com1.Q.set_domain(10);

	dfa_com1.T.set_domain(10);
	dfa_com1.T.add_transition(0, '0', 1);
	dfa_com1.T.add_transition(0, '1', 2);
	dfa_com1.T.add_transition(1, '0', 4);
	dfa_com1.T.add_transition(1, '1', 2);
	dfa_com1.T.add_transition(2, '0', 1);
	dfa_com1.T.add_transition(2, '1', 3);
	dfa_com1.T.add_transition(3, '0', 6);
	dfa_com1.T.add_transition(3, '1', 3);
	dfa_com1.T.add_transition(4, '0', 4);
	dfa_com1.T.add_transition(4, '1', 5);
	dfa_com1.T.add_transition(5, '0', 6);
	dfa_com1.T.add_transition(6, '0', 4);
	dfa_com1.T.add_transition(6, '1', 5);


	
	DFA dfa1(dfa_com1);
	cout << "****************************************" << endl;
	cout << dfa1 << endl;
	cout << "is the DFA Usefulf? : " << dfa1.Usefulf() << endl;
	cout << "****************************************" << endl;


	// DFA::min_dragon();
	DFA dfa2(dfa1);
	dfa2.usefulf();
	cout << dfa2 << endl;
	cout << "is the DFA Usefulf? : " << dfa2.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_dragon(): " << endl;
	dfa2.min_dragon();
	cout << dfa2 << endl;
	cout << "is the DFA Usefulf? : " << dfa2.Usefulf() << endl;
	cout << "****************************************" << endl;
	/*
		****************************************
		Minimized by DFA::min_dragon():

		DFA
		Q = [0,6)
		S = { 0 }
		F = { 3  4  5 }
		Transitions =
		0->{ '0'->1  '1'->2 }
		1->{ '0'->4  '1'->2 }
		2->{ '0'->1  '1'->3 }
		3->{ '0'->4  '1'->3 }
		4->{ '0'->4  '1'->5 }
		5->{ '0'->4 }

		current = -1

		is the DFA Usefulf? : 1
		****************************************
	*/

	// DFA::min_Brzozowski
	DFA dfa3(dfa1);
	dfa3.usefulf();
	cout << dfa3 << endl;
	cout << "is the DFA Usefulf? : " << dfa3.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_Brzozowski(): " << endl;
	dfa3.min_Brzozowski();
	cout << dfa3 << endl;
	cout << "is the DFA Usefulf? : " << dfa3.Usefulf() << endl;
	cout << "****************************************" << endl;
	/*
		****************************************
		Minimized by DFA::min_Brzozowski():

		DFA
		Q = [0,15)
		S = { 0 }
		F = { 3  4  5  7  8  9  10  11  12 }
		Transitions =
		0->{ '0'->1  '1'->2 }
		1->{ '0'->3  '1'->4 }
		2->{ '1'->5  '0'->6 }
		3->{ '0'->3  '1'->4 }
		4->{ '0'->7  '1'->5 }
		5->{ '0'->8  '1'->5 }
		6->{ '0'->9  '1'->4 }
		7->{ '0'->9  '1'->4 }
		8->{ '0'->10  '1'->11 }
		9->{ '0'->12  '1'->11 }
		10->{ '0'->10  '1'->13 }
		11->{ '0'->10 }
		12->{ '0'->9  '1'->2 }
		13->{ '0'->14 }
		14->{ '0'->10  '1'->13 }

		current = -1

		is the DFA Usefulf? : 1
		****************************************
	*/


	// Minimized by DFA::min_Hopcroft():
	DFA dfa4(dfa1);
	dfa4.usefulf();
	cout << dfa4 << endl;
	cout << "is the DFA Usefulf? : " << dfa4.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_Hopcroft(): " << endl;
	//dfa4.min_Hopcroft(); //abort min-hop.cpp 102 ***State r(split(p, q, C.iterator(L[q]), P));***
	cout << dfa4 << endl;
	cout << "is the DFA Usefulf? : " << dfa4.Usefulf() << endl;
	cout << "****************************************" << endl;



	// Minimized by DFA::min_HopcroftUllman()
	DFA dfa5(dfa1);
	dfa5.usefulf();
	cout << dfa5 << endl;
	cout << "is the DFA Usefulf? : " << dfa5.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_HopcroftUllman(): " << endl;
	dfa5.min_HopcroftUllman();
	cout << dfa5 << endl;
	cout << "is the DFA Usefulf? : " << dfa5.Usefulf() << endl;
	cout << "****************************************" << endl;
	/*
		Minimized by DFA::min_HopcroftUllman():

		DFA
		Q = [0,6)
		S = { 0 }
		F = { 3  4  5 }
		Transitions =
		0->{ '0'->1  '1'->2 }
		1->{ '0'->4  '1'->2 }
		2->{ '0'->1  '1'->3 }
		3->{ '0'->4  '1'->3 }
		4->{ '0'->4  '1'->5 }
		5->{ '0'->4 }

		current = -1

		is the DFA Usefulf? : 1
		****************************************

	*/



	// Minimized by DFA::min_Watson():
	DFA dfa6(dfa1);
	dfa6.usefulf();
	cout << dfa6 << endl;
	cout << "is the DFA Usefulf? : " << dfa6.Usefulf() << endl;
	cout << "****************************************" << endl;
	cout << "Minimized by DFA::min_Watson(): " << endl;
	dfa6.min_Watson();
	cout << dfa6 << endl;
	cout << "is the DFA Usefulf? : " << dfa6.Usefulf() << endl;
	cout << "****************************************" << endl;
	/*
		****************************************
		Minimized by DFA::min_Watson():

		DFA
		Q = [0,6)
		S = { 0 }
		F = { 3  4  5 }
		Transitions =
		0->{ '0'->1  '1'->2 }
		1->{ '0'->4  '1'->2 }
		2->{ '0'->1  '1'->3 }
		3->{ '0'->4  '1'->3 }
		4->{ '0'->4  '1'->5 }
		5->{ '0'->4 }

		current = -1

		is the DFA Usefulf? : 1
		****************************************
	*/
}

void DFA_usefulfTest_integer()
{
	/*
	样例来自：  https://www.cnblogs.com/wendellyi/p/3695489.html
	初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)

	状态说明   状态    输入字符 (《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 141 fig. 5-4 移除状态5及其边)
						0      1
		start	q0      q1     q2
				q1      q4     q2
		accept  q2      q1     q3
		accept  q3      q6     q3
		accept  q4      q4     q5
		accept  q5      q6     
		accept  q6      q4     q5
	*/
	DFA_components dfa_com1;

	// StateSet S  开始状态集
	dfa_com1.S.set_domain(10);
	dfa_com1.S.add(0);
	//dfa_com1.S.add(1);

	// StateSet F  结束状态集
	dfa_com1.F.set_domain(10);
	dfa_com1.F.add(3);
	dfa_com1.F.add(4);
	dfa_com1.F.add(5);
	dfa_com1.F.add(6);

	dfa_com1.Q.set_domain(10);

	dfa_com1.T.set_domain(10);
	dfa_com1.T.add_transition(0, '0', 1);
	dfa_com1.T.add_transition(0, '1', 2);
	dfa_com1.T.add_transition(1, '0', 4);
	dfa_com1.T.add_transition(1, '1', 2);
	dfa_com1.T.add_transition(2, '0', 1);
	dfa_com1.T.add_transition(2, '1', 3);

	// 有自环，有序
	dfa_com1.T.add_transition(3, '0', 6);
	dfa_com1.T.add_transition(3, '1', 3);

	// 无自环，无序
	dfa_com1.T.add_transition(4, '1', 5);
	dfa_com1.T.add_transition(4, '0', 4);
	
	dfa_com1.T.add_transition(5, '0', 6);
	dfa_com1.T.add_transition(6, '0', 4);
	dfa_com1.T.add_transition(6, '1', 5);

	DFA dfa1(dfa_com1);
	cout << "************************************************" << endl;
	cout << "Ordered:" << endl;
	cout << dfa1 << endl;
	cout << "************************************************" << endl;
	cout << "After DFA::usefulf():" << endl;
	dfa1.usefulf();
	cout << dfa1 << endl;
	cout << "is the DFA Usefulf()? :   " << dfa1.Usefulf() << endl;
	cout << "************************************************\n\n\n\n" << endl;



	DFA_components dfa_com2;

	// StateSet S  开始状态集
	dfa_com2.S.set_domain(10);
	dfa_com2.S.add(0);
	//dfa_com1.S.add(1);

	// StateSet F  结束状态集
	dfa_com2.F.set_domain(10);
	dfa_com2.F.add(3);
	dfa_com2.F.add(4);
	dfa_com2.F.add(5);
	dfa_com2.F.add(6);

	dfa_com2.Q.set_domain(10);

	dfa_com2.T.set_domain(10);
	dfa_com2.T.add_transition(0, '0', 1);
	dfa_com2.T.add_transition(0, '1', 2);
	dfa_com2.T.add_transition(1, '0', 4);
	dfa_com2.T.add_transition(1, '1', 2);
	dfa_com2.T.add_transition(2, '0', 1);
	dfa_com2.T.add_transition(2, '1', 3);

	// 有自环，无序
	dfa_com2.T.add_transition(3, '1', 3);
	dfa_com2.T.add_transition(3, '0', 6);

	// 无自环，有序
	dfa_com2.T.add_transition(4, '0', 4);
	dfa_com2.T.add_transition(4, '1', 5);

	dfa_com2.T.add_transition(5, '0', 6);
	dfa_com2.T.add_transition(6, '0', 4);
	dfa_com2.T.add_transition(6, '1', 5);

	DFA dfa2(dfa_com2);
	cout << "************************************************" << endl;
	cout << "Unordered:" << endl;
	cout << dfa2 << endl;
	cout << "************************************************" << endl;
	cout << "After DFA::usefulf():" << endl;
	dfa2.usefulf();
	cout << dfa2 << endl;
	cout << "is the DFA Usefulf()? :   " << dfa2.Usefulf() << endl;
	cout << "************************************************\n\n\n\n" << endl;

}


void DFA_usefulfTest_Alphabet()
{
	/*
	样例来自：  https://www.cnblogs.com/wendellyi/p/3695489.html
	初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)

	状态说明   状态    输入字符 (《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 141 fig. 5-4 移除状态5及其边)
						0      1
		start	q0      q1     q2
				q1      q4     q2
		accept  q2      q1     q3
		accept  q3      q6     q3
		accept  q4      q4     q5
		accept  q5      q6     
		accept  q6      q4     q5

	*/
	DFA_components dfa_com1;

	// StateSet S  开始状态集
	dfa_com1.S.set_domain(10);
	dfa_com1.S.add(0);
	//dfa_com1.S.add(1);

	// StateSet F  结束状态集
	dfa_com1.F.set_domain(10);
	dfa_com1.F.add(3);
	dfa_com1.F.add(4);
	dfa_com1.F.add(5);
	dfa_com1.F.add(6);

	dfa_com1.Q.set_domain(10);

	dfa_com1.T.set_domain(10);
	dfa_com1.T.add_transition(0, 'a', 1);
	dfa_com1.T.add_transition(0, 'b', 2);
	dfa_com1.T.add_transition(1, 'a', 4);
	dfa_com1.T.add_transition(1, 'b', 2);
	dfa_com1.T.add_transition(2, 'a', 1);
	dfa_com1.T.add_transition(2, 'b', 3);

	// 有自环，有序
	dfa_com1.T.add_transition(3, 'a', 6);
	dfa_com1.T.add_transition(3, 'b', 3);

	// 无自环，有序
	dfa_com1.T.add_transition(4, 'a', 4);
	dfa_com1.T.add_transition(4, 'b', 5);
	
	dfa_com1.T.add_transition(5, 'a', 6);
	dfa_com1.T.add_transition(6, 'a', 4);
	dfa_com1.T.add_transition(6, 'b', 5);

	DFA dfa1(dfa_com1);
	cout << "************************************************" << endl;
	cout << "unrdered:" << endl;
	cout << dfa1 << endl;
	cout << "************************************************" << endl;
	cout << "After DFA::usefulf():" << endl;
	dfa1.usefulf();
	cout << dfa1 << endl;
	cout << "is the DFA Usefulf()? :   " << dfa1.Usefulf() << endl;
	cout << "************************************************\n\n\n\n" << endl;



	DFA_components dfa_com2;

	// StateSet S  开始状态集
	dfa_com2.S.set_domain(10);
	dfa_com2.S.add(0);
	//dfa_com1.S.add(1);

	// StateSet F  结束状态集
	dfa_com2.F.set_domain(10);
	dfa_com2.F.add(3);
	dfa_com2.F.add(4);
	dfa_com2.F.add(5);
	dfa_com2.F.add(6);

	dfa_com2.Q.set_domain(10);

	dfa_com2.T.set_domain(10);
	dfa_com2.T.add_transition(0, 'a', 1);
	dfa_com2.T.add_transition(0, 'b', 2);
	dfa_com2.T.add_transition(1, 'a', 4);
	dfa_com2.T.add_transition(1, 'b', 2);
	dfa_com2.T.add_transition(2, 'a', 1);
	dfa_com2.T.add_transition(2, 'b', 3);

	// 有自环，无序
	dfa_com2.T.add_transition(3, 'b', 3);
	dfa_com2.T.add_transition(3, 'a', 6);

	// 无自环，无序
	dfa_com2.T.add_transition(4, 'b', 5);
	dfa_com2.T.add_transition(4, 'a', 4);

	dfa_com2.T.add_transition(5, 'a', 6);
	dfa_com2.T.add_transition(6, 'a', 4);
	dfa_com2.T.add_transition(6, 'b', 5);

	DFA dfa2(dfa_com2);
	cout << "************************************************" << endl;
	cout << "Unordered:" << endl;
	cout << dfa2 << endl;
	cout << "************************************************" << endl;
	cout << "After DFA::usefulf():" << endl;
	dfa2.usefulf();
	cout << dfa2 << endl;
	cout << "is the DFA Usefulf()? :   " << dfa2.Usefulf() << endl;
	cout << "************************************************\n\n\n\n" << endl;
}