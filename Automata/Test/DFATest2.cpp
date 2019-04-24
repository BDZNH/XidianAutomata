#include "DFA.h"
#include <iostream>
#include <string>
using namespace std;

DFA_components DfaCom1(int n);

void MinimiAlgorithm(DFA_components dfa_com);

void DFATest()
{
	DFA_components dfa_com = DfaCom1(6);
	MinimiAlgorithm(dfa_com);

}

DFA_components DfaCom1(int n)
{
	DFA_components dfa_com1;
	switch (n)
	{
	case 1:
	{
		/*
		初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)
		《形式语言与自动机理论》（ISBN 978-7-302-31802-6）Fg. 3-3
		状态说明   状态    输入字符
							0   1
			start	q0      q1  q0
					q1      q2  q0
					q2      q3  q0
			accept 	q3      q3  q0

		预期结果： 该自动机本身便为最小自动机
		*/


		// StateSet S  开始状态集
		dfa_com1.S.set_domain(10);
		dfa_com1.S.add(0);

		// StateSet F  结束状态集
		dfa_com1.F.set_domain(10);
		dfa_com1.F.add(3);

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
	}
		break;
	case 2:
	{
		/*
		初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)
		《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 77   ,  fg. 3-5
		状态说明   状态    输入字符
							0      1
			start	q0      q1     q0
					q1      q2,q5  q0
					q2      q3,q6  q0
			accept 	q3      q3     q4
			accept  q4      q1     q0
			{x000|x \in {0,1}*} or {x001|x \in {0,1}*}

		预期结果: 该自动机本身为最小自动机     

		*/

		// StateSet S  开始状态集
		dfa_com1.S.set_domain(10);
		dfa_com1.S.add(0);
		//dfa_com1.S.add(1);

		// StateSet F  结束状态集
		dfa_com1.F.set_domain(10);
		dfa_com1.F.add(3);
		dfa_com1.F.add(4);

		int i = 10;
		while (i--)
		{
			dfa_com1.Q.allocate();
		}


		dfa_com1.T.set_domain(10);
		dfa_com1.T.add_transition(0, '0', 1);
		dfa_com1.T.add_transition(1, '0', 2);
		dfa_com1.T.add_transition(2, '0', 3);
		dfa_com1.T.add_transition(3, '0', 3);
		dfa_com1.T.add_transition(0, '1', 0);
		dfa_com1.T.add_transition(1, '1', 0);
		dfa_com1.T.add_transition(2, '1', 4);
		dfa_com1.T.add_transition(3, '1', 4);
		dfa_com1.T.add_transition(4, '0', 1);
		dfa_com1.T.add_transition(4, '1', 0);
	}
		break;
	case 3:
	{
		/*
		初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)
		状态说明   状态    输入字符 (《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 141 fig. 5-4)
							0      1
			start	q0      q1     q2
					q1      q0     q3
			accept  q2      q4     
			accept  q3      q4     
			accept  q4      q4     

		预期结果 《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 153 fig. 5-6

		状态说明   状态        输入字符
							  0         1
			start	q0,q1     q0,q1     q2,q3,q4
			accept  q2,q3,q4  q2,q3,q4  q5


		或者：

		状态说明   状态        输入字符
							  0         1
			start	q0        q0        q1
			accept  q1        q1
		*/

		// StateSet S  开始状态集
		dfa_com1.S.set_domain(10);
		dfa_com1.S.add(0);
		//dfa_com1.S.add(1);

		// StateSet F  结束状态集
		dfa_com1.F.set_domain(10);
		dfa_com1.F.add(2);
		dfa_com1.F.add(3);
		dfa_com1.F.add(4);

		/*int i = 10;
		while (i--)
		{
			dfa_com1.Q.allocate();
		}*/

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
	}
		break;
	case 4:
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
			start	q0,q1     q0,q1     q2,q3,q4
			accept  q2,q3,q4  q2,q3,q4  q5
			sink    q5        q5        q5

		或者：

		状态说明   状态        输入字符
							  0         1
			start	q0        q0        q1
			accept  q1        q1        q2
			sink    q2        q5        q5
		*/

		// StateSet S  开始状态集
		dfa_com1.S.set_domain(10);
		dfa_com1.S.add(0);

		// StateSet F  结束状态集
		dfa_com1.F.set_domain(10);
		dfa_com1.F.add(2);
		dfa_com1.F.add(3);
		dfa_com1.F.add(4);

		/*int i = 10;
		while (i--)
		{
			dfa_com1.Q.allocate();
		}*/

		dfa_com1.Q.set_domain(10);

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
	}
	break;
	case 5:
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

		预期结果：q9为不可达状态，该自动机去除q9后为一个最小自动机
		*/

		// StateSet S  开始状态集
		dfa_com1.S.set_domain(10);
		dfa_com1.S.add(0);
		//dfa_com1.S.add(1);

		// StateSet F  结束状态集
		dfa_com1.F.set_domain(10);
		dfa_com1.F.add(4);
		dfa_com1.F.add(8);

		/*int i = 10;
		while (i--)
		{
			dfa_com1.Q.allocate();
		}*/

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
		/*dfa_com1.T.add_transition(9, '0', 7);
		dfa_com1.T.add_transition(9, '1', 5);*/
	}
	break;
	case 6:
	{
		/*
		样例来自：  https://www.cnblogs.com/wendellyi/p/3695489.html
		初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)

		状态说明    状态     输入字符
							0      1
			start	q0      q1     q2
					q1      q4     q2
			accept  q2      q1     q3
			accept  q3      q6     q3
			accept  q4      q4     q5
			accept  q5      q6     q5
			accept  q6      q4     q5

		预期结果：

		状态说明    状态     输入字符
							a      b
			start	q0      q1     q2
					q1      q3     q2
			        q2      q1     q3
			accept  q3      q3     q3

		*/

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
		dfa_com1.T.add_transition(3, 'a', 6);
		dfa_com1.T.add_transition(3, 'b', 3);
		dfa_com1.T.add_transition(4, 'a', 4);
		dfa_com1.T.add_transition(4, 'b', 5);
		dfa_com1.T.add_transition(5, 'a', 6);
		dfa_com1.T.add_transition(5, 'b', 5);
		dfa_com1.T.add_transition(6, 'a', 4);
		dfa_com1.T.add_transition(6, 'b', 5);
	}
		break;
	case 7:
	{
		/*
			初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)
			状态说明   状态    输入字符 (《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 154  fig. 5-7  去除状态9 )
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


			预期结果：含有一个开始状态不可达状态（q9）,
			该自动机为一个最小自动机
		*/

		// StateSet S  开始状态集
		dfa_com1.S.set_domain(10);
		dfa_com1.S.add(0);
		//dfa_com1.S.add(1);

		// StateSet F  结束状态集
		dfa_com1.F.set_domain(10);
		dfa_com1.F.add(4);
		dfa_com1.F.add(8);

		/*int i = 10;
		while (i--)
		{
			dfa_com1.Q.allocate();
		}*/

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
	}
		break;
	case 8:
	{
		/*
		测试中
			初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)
			状态说明   状态    输入字符 (《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 154  fig. 5-7  去除状态9 )
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


			预期结果：q9为不可达状态，该自动机去除q9后为一个最小自动机
		*/

		// StateSet S  开始状态集
		dfa_com1.S.set_domain(10);
		dfa_com1.S.add(0);
		//dfa_com1.S.add(1);

		// StateSet F  结束状态集
		dfa_com1.F.set_domain(10);
		dfa_com1.F.add(4);
		dfa_com1.F.add(8);

		/*int i = 10;
		while (i--)
		{
			dfa_com1.Q.allocate();
		}*/

		dfa_com1.Q.set_domain(10);

		dfa_com1.T.set_domain(10);
		dfa_com1.T.add_transition(0, '0', 1);
		dfa_com1.T.add_transition(0, '1', 5);
		dfa_com1.T.add_transition(1, '1', 2);
		//dfa_com1.T.add_transition(1, '0', 5);
		dfa_com1.T.add_transition(2, '0', 3);
		//dfa_com1.T.add_transition(2, '1', 6);
		//dfa_com1.T.add_transition(3, '0', 2);
		dfa_com1.T.add_transition(3, '1', 4);
		dfa_com1.T.add_transition(4, '0', 8);
		dfa_com1.T.add_transition(4, '1', 4);
		//dfa_com1.T.add_transition(5, '0', 1);
		dfa_com1.T.add_transition(5, '1', 6);
		//dfa_com1.T.add_transition(6, '1', 2);
		dfa_com1.T.add_transition(6, '0', 7);
		dfa_com1.T.add_transition(7, '1', 8);
		//dfa_com1.T.add_transition(7, '0', 6);
		dfa_com1.T.add_transition(8, '0', 4);
		dfa_com1.T.add_transition(8, '1', 8);
		
		/*dfa_com1.T.add_transition(9, '0', 1);
		dfa_com1.T.add_transition(9, '1', 5);*/



		//dfa_com1.T.add_transition(8, '0', 5);
		/*dfa_com1.T.add_transition(9, '0', 7);
		dfa_com1.T.add_transition(9, '1', 5);*/
	}
		break;
	case 9:
	{
		/*
		测试中
			初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)
			状态说明   状态    输入字符 (《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 154  fig. 5-7  去除状态9 )
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


			预期结果：q9为不可达状态，该自动机去除q9后为一个最小自动机
		*/

		// StateSet S  开始状态集
		dfa_com1.S.set_domain(10);
		dfa_com1.S.add(0);
		//dfa_com1.S.add(1);

		// StateSet F  结束状态集
		dfa_com1.F.set_domain(10);
		dfa_com1.F.add(4);
		dfa_com1.F.add(8);

		/*int i = 10;
		while (i--)
		{
			dfa_com1.Q.allocate();
		}*/

		dfa_com1.Q.set_domain(10);

		dfa_com1.T.set_domain(10);
		dfa_com1.T.add_transition(0, '0', 1);
		dfa_com1.T.add_transition(0, '1', 5);
		dfa_com1.T.add_transition(1, '1', 2);
		//dfa_com1.T.add_transition(1, '0', 5);
		dfa_com1.T.add_transition(2, '0', 3);
		//dfa_com1.T.add_transition(2, '1', 6);
		//dfa_com1.T.add_transition(3, '0', 2);
		dfa_com1.T.add_transition(3, '1', 4);
		dfa_com1.T.add_transition(4, '0', 8);
		dfa_com1.T.add_transition(4, '1', 4);
		//dfa_com1.T.add_transition(5, '0', 1);
		dfa_com1.T.add_transition(5, '1', 6);
		//dfa_com1.T.add_transition(6, '1', 2);
		dfa_com1.T.add_transition(6, '0', 7);
		dfa_com1.T.add_transition(7, '1', 8);
		//dfa_com1.T.add_transition(7, '0', 6);
		dfa_com1.T.add_transition(8, '0', 4);
		dfa_com1.T.add_transition(8, '1', 8);

		dfa_com1.T.add_transition(9, '0', 1);
		dfa_com1.T.add_transition(9, '1', 5);



		//dfa_com1.T.add_transition(8, '0', 5);
		/*dfa_com1.T.add_transition(9, '0', 7);
		dfa_com1.T.add_transition(9, '1', 5);*/
	}
		break;
	case 10:
	{
		/*
		样例来自：  https://www.cnblogs.com/wendellyi/p/3695489.html
		初始化这样一个DFA (此表格的意义可以查看《形式语言与自动机理论》（ISBN 978-7-302-31802-6）pg. 73)

		状态说明    状态     输入字符
							0      1
			start	q0      q1     q2
					q1      q4     q2
			accept  q2      q1     q3
			accept  q3      q6     q3
			accept  q4      q4     q5
			accept  q5      q6     q5
			accept  q6      q4     q5

		预期结果：

		状态说明    状态     输入字符
							a      b
			start	q0      q1     q2
					q1      q3     q2
					q2      q1     q3
			accept  q3      q3     q3

		*/

		// StateSet S  开始状态集
		dfa_com1.S.set_domain(10);
		dfa_com1.S.add(0);

		// StateSet F  结束状态集
		dfa_com1.F.set_domain(10);
		dfa_com1.F.add(2);
		dfa_com1.F.add(3);
		dfa_com1.F.add(4);
		//dfa_com1.F.add(6);

		dfa_com1.Q.set_domain(10);

		dfa_com1.T.set_domain(10);
		dfa_com1.T.add_transition(0, 'a', 1);
		dfa_com1.T.add_transition(0, 'b', 2);
		//dfa_com1.T.add_transition(1, 'a', 2);
		dfa_com1.T.add_transition(1, 'a', 3);
		//dfa_com1.T.add_transition(2, 'b', 1);
		dfa_com1.T.add_transition(2, 'b', 3);
		dfa_com1.T.add_transition(3, 'b', 4);

	}
		break;
	default:
		break;
	}
	return dfa_com1;
}

void MinimiAlgorithm(DFA_components dfa_com)
{
	DFA dfa1(dfa_com);
	cout << "*************************************\n\n" << endl;
	cout << "original FA:" << endl;
	cout << dfa1 << endl;
	string s = dfa1.Usefulf() ? "yes" : "no";
	cout << "Is the FA Usefulf?:  " << s << "\n\n" << endl;

	cout << "*************************************\n\n" << endl;
	cout << "Minimized by DFA::min_Hopcroft():" << endl;
	cout << "Usefulf required ?: true" << endl;
	DFA dfa5(dfa1);
	cout << dfa5 << endl;
	dfa5.usefulf();
	cout << "after useful(): " << endl << dfa5 << endl;
	dfa5.min_Hopcroft();
	cout << dfa5 << endl;
	s = dfa5.Usefulf() ? "yes" : "no";
	cout << "Is the FA Usefulf?:  " << s << "\n\n" << endl;

	cout << "*************************************\n\n" << endl;
	cout << "Minimized by DFA::min_Brzozowski():" << endl;
	cout << "Usefulf required ?: false" << endl;
	DFA dfa2(dfa1);
	cout << dfa2 << endl;
	dfa2.min_Brzozowski();
	cout << dfa2 << endl;
	s = dfa2.Usefulf() ? "yes" : "no";
	cout << "Is the FA Usefulf?:  " << s << "\n\n" << endl;

	cout << "*************************************\n\n" << endl;
	cout << "Minimized by DFA::min_HopcroftUllman():" << endl;
	cout << "Usefulf required ?: true" << endl;
	DFA dfa3(dfa1);
	cout << dfa3 << endl;
	dfa3.usefulf();
	dfa3.min_HopcroftUllman();
	cout << dfa3 << endl;
	s = dfa3.Usefulf() ? "yes" : "no";
	cout << "Is the FA Usefulf?:  " << s << "\n\n" << endl;

	cout << "*************************************\n\n" << endl;
	cout << "Minimized by DFA::min_dragon():" << endl;
	cout << "Usefulf required ?: true" << endl;
	DFA dfa4(dfa1);
	cout << dfa4 << endl;
	dfa4.usefulf();
	dfa4.min_dragon();
	cout << dfa4 << endl;
	s = dfa4.Usefulf() ? "yes" : "no";
	cout << "Is the FA Usefulf?:  " << s << "\n\n" << endl;

	cout << "*************************************\n\n" << endl;
	cout << "Minimized by DFA::min_Watson():" << endl;
	cout << "Usefulf required ?: true" << endl;
	DFA dfa6(dfa1);
	cout << dfa6 << endl;
	dfa6.usefulf();
	dfa6.min_Watson();
	cout << dfa6 << endl;
	s = dfa6.Usefulf() ? "yes" : "no";
	cout << "Is the FA Usefulf?:  " << s << "\n\n" << endl;
}
