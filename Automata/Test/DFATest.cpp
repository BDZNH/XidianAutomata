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
	cout << "****************************************" << endl;
	cout << dfa1 << endl;
	cout << "****************************************" << endl;
	cout << "is the DFA Usefulf? : " << dfa1.Usefulf() << endl;
	cout << "****************************************" << endl;
	dfa1.min_dragon();
	cout << dfa1 << endl;
	

}


void DFATest5()
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
	cout << "****************************************" << endl;
	cout << dfa1 << endl;
	cout << "****************************************" << endl;
	cout << "is the DFA Usefulf? : " << dfa1.Usefulf() << endl;
	cout << "****************************************" << endl;
	dfa1.usefulf();
	cout << dfa1 << endl;
	cout << "****************************************" << endl;
	cout << "is the DFA Usefulf? : " << dfa1.Usefulf() << endl;
	cout << "****************************************" << endl;
	dfa1.min_dragon();
	cout << dfa1 << endl;


}

void DFATest()
{
	//DFATest1();
	//DFATest2();
	//DFATest3();
	//DFATest4();
	DFATest5();
}