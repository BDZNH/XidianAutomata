#include"StateEqRel.h"
#include"StateSet.h"
using namespace std;
void StateEqRelTest()
{
	StateEqRel P(10);  //初始化等价类集合 [0,10) 
	cout << P << endl;

	StateSet st1;
	st1.set_domain(10);
	st1.add(0);
	st1.add(1);
	st1.add(2);         
	cout << st1 << endl;// 状态集 (0,1,2)

	P.split(st1);       // 从 P 中分离 st1
	cout << P << endl;

	StateSet st2;
	st2.set_domain(10);
	st2.add(5);
	st2.add(6);
	cout << st2 << endl;// 状态集 (0,5,6)

	P.split(st2);       // 从 P 中分离 st2
	cout << P << endl;

	cout << P.representatives() << endl;// P 中等价类代表的集合
	cout << P.equivalent(0, 1) << endl; // 0 和 1 是否在一个等价类
	cout << P.equivalent(0, 9) << endl; // 0 和 9 是否在一个等价类
	cout << P.equivalent(0, 5) << endl; // 0 和 5 是否在一个等价类
	cout << P.equiv_class(5) << endl;   // [5]
	cout << P.eq_class_representative(8) << endl; // [8] 的代表
	cout << P.eq_class_representative(6) << endl; // [6] 的代表
	cout << P << endl;
	cout << P.equivalize(0, 5) << endl; // 合并 (0,1,2) 和 (5,6)
	P.identity();                       // 使所有状态都不等价
	cout << P << endl;                  
}
