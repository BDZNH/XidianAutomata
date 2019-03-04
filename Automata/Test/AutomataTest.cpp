/*#include "../stdafx.h" */ // fatal error C1010: 在查找预编译头时遇到意外的文件结尾。是否忘记了向源中添加“#include "stdafx.h"”?
//#include "stdafx.h"  // 虽然在Test目录下无此文件，但是却骗取了编译器，无上述错误了
 
/*关于stdafx.h文件缺失的问题，因为Automatatest.cpp文件位于项目的Test文件夹内，stdafx.h 文件位于它的上一级目录，所以正确包含这个文件的方法是
#include "../stdafx.h"
若使用   #include "stdafx.h" ，则应该在VS的项目属性里面将当前项目的项目目录也设置为头文件路径*/

void CRSetTest();
void StateSetTest();
void StateToStateSetTest();
void StateRelTest();
void TransTest();
void ThompsonTest();
void RFATest();

void AutomataTest()
{
	//CRSetTest();
	//StateSetTest();
	//StateToStateSetTest();
	//StateRelTest();
	//TransTest();
	ThompsonTest();
	RFATest();
}