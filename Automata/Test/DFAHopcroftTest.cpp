#include "DFA.h"
#include <string>
#include <iostream>

using namespace std;

void MinimiAlgorithmFunction(DFA_components dfa_com);
DFA_components DfaCom(int);

void DFAHopcroftTest()
{
	int n = 1;
	while (n<6)
	{
		std::cout << "Now test No:  " << n << std::endl << std::endl;
		DFA_components dfa_com = DfaCom(n);
		DFA dfa1(dfa_com);
		std::cout << "Original DFA:" << std::endl;
		std::cout << dfa1 << std::endl;
		dfa1.min_Hopcroft();
		std::cout << "Minimized by Hopcroft:" << std::endl;
		std::cout << dfa1 << std::endl;
		std::cout << "################################################" << std::endl;
		n++;
	}
}


DFA_components DfaCom(int n)
{
	DFA_components dfa_com1;
	switch (n)
	{
	case 1:
	{
		/*

		初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)

		状态说明    状态     输入字符
							a      b
        开始状态     q0      q1     q2
		             q1      q3     
		结束状态     q2             q3
		结束状态     q3      q4
		结束状态     q4
		
		预期结果：   本身为最小的 DFA

		状态说明    状态     输入字符

		*/
		/// 此例子 Hopcroft 中止
		// StateSet S  开始状态集
		dfa_com1.S.set_domain(5);
		dfa_com1.S.add(0);

		// StateSet F  结束状态集
		dfa_com1.F.set_domain(5);
		dfa_com1.F.add(2);
		dfa_com1.F.add(3);
		dfa_com1.F.add(4);

		dfa_com1.Q.set_domain(5);

		dfa_com1.T.set_domain(5);
		dfa_com1.T.add_transition(0, 'a', 1);
		dfa_com1.T.add_transition(0, 'b', 2);
		dfa_com1.T.add_transition(1, 'a', 3);
		dfa_com1.T.add_transition(2, 'b', 3);
		dfa_com1.T.add_transition(3, 'b', 4);
	}
	break;
	case 2:
	{
		/*
		此例 Hopcroft 错误
		初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)

		状态说明    状态     输入字符
							a      b
        开始状态     q0      q1     q2
		结束状态	 q1             q2
		结束状态     q2      q1

		预期结果    本身为最小的 DFA

		*/

		// StateSet S  开始状态集
		dfa_com1.S.set_domain(3);
		dfa_com1.S.add(0);

		// StateSet F  结束状态集
		dfa_com1.F.set_domain(3);
		dfa_com1.F.add(1);
		dfa_com1.F.add(2);

		dfa_com1.Q.set_domain(3);

		dfa_com1.T.set_domain(3);
		dfa_com1.T.add_transition(0, 'a', 1);
		dfa_com1.T.add_transition(0, 'b', 2);
		dfa_com1.T.add_transition(1, 'b', 2);
		dfa_com1.T.add_transition(2, 'a', 1);

	}
	break;
	case 3:
	{
		/*
		此例 Hopcroft 正确

		初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)

		状态说明    状态     输入字符
							a      b
		开始状态	q0      q1     
					q1             q2
		结束状态	q2      q3
		结束状态	q3
		预期结果    本身为最小的 DFA

		*/
		// 此例Hopcroft正确 
		// StateSet S  开始状态集
		dfa_com1.S.set_domain(4);
		dfa_com1.S.add(0);

		// StateSet F  结束状态集
		dfa_com1.F.set_domain(4);
		dfa_com1.F.add(2);
		dfa_com1.F.add(3);

		dfa_com1.Q.set_domain(4);

		dfa_com1.T.set_domain(4);
		dfa_com1.T.add_transition(0, 'a', 1);
		dfa_com1.T.add_transition(1, 'b', 2);
		dfa_com1.T.add_transition(2, 'a', 3);
	}
	break;
	case 4:
	{
		/*
		
		初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)

		状态说明    状态     输入字符
							a      b
		开始状态	q0      q1
					q1             q2
		结束状态	q2      q3
		结束状态	q3             q4
		结束状态	q4
		预期结果    本身为最小的 DFA

		*/
		// 此例子 Hopcroft 中止
		// StateSet S  开始状态集
		dfa_com1.S.set_domain(5);
		dfa_com1.S.add(0);

		// StateSet F  结束状态集
		dfa_com1.F.set_domain(5);
		dfa_com1.F.add(2);
		dfa_com1.F.add(3);
		dfa_com1.F.add(4);
		//dfa_com1.F.add(6);

		dfa_com1.Q.set_domain(5);

		dfa_com1.T.set_domain(5);
		dfa_com1.T.add_transition(0, 'a', 1);
		dfa_com1.T.add_transition(1, 'b', 2);
		dfa_com1.T.add_transition(2, 'a', 3);
		dfa_com1.T.add_transition(3, 'b', 4);
	}
	break;
	case 5:
	{
		/*
		
		初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)

		状态说明    状态     输入字符
							a      b
		开始状态	q0      q1
					q1             q2
					q2      q3
		结束状态	q3             q4
		结束状态	q4
		预期结果    本身为最小的 DFA

		*/
		// 此例 Hopcroft 正确
		// StateSet S  开始状态集
		dfa_com1.S.set_domain(5);
		dfa_com1.S.add(0);

		// StateSet F  结束状态集
		dfa_com1.F.set_domain(5);
		//dfa_com1.F.add(2);
		dfa_com1.F.add(3);
		dfa_com1.F.add(4);
		//dfa_com1.F.add(6);

		dfa_com1.Q.set_domain(5);

		dfa_com1.T.set_domain(5);
		dfa_com1.T.add_transition(0, 'a', 1);
		dfa_com1.T.add_transition(1, 'b', 2);
		dfa_com1.T.add_transition(2, 'a', 3);
		dfa_com1.T.add_transition(3, 'b', 4);
	}
	break;
	default:
		break;
	}
	return dfa_com1;
}