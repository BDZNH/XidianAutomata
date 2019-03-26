#include "DFA.h"
#include <iostream>
using namespace std;
void DFATest()
{
	DFA_components dfa_com1;

	// StateSet S  开始状态集
	dfa_com1.S.set_domain(10);
	dfa_com1.S.add(0);
	//dfa_com1.S.add(1);

	// StateSet F  结束状态集
	dfa_com1.F.set_domain(10);
	dfa_com1.F.add(3);
	dfa_com1.F.add(5);
	dfa_com1.F.add(7);
	int i = 10;
	while (i--)
	{
		dfa_com1.Q.allocate();
	}
	

	dfa_com1.T.set_domain(10);
	DFA dfa1(dfa_com1);
	cout << dfa1 << endl;
	dfa1.min_Brzozowski();
	cout << dfa1 << endl;
	const DFA dfa2(dfa_com1);

	cout << dfa2.Usefulf() << endl;

	//cout << /*dfa1.S*/ << endl;

}