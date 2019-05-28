/*

对类 FiniteAutomata 的使用做一些示范。

*/

#include <iostream>
#include "FiniteAutomata.h"

void usage();
void hint();

int main()
{
	int n;
	FiniteAutomata ffa;
	bool flag = false;
	usage();
	while (std::cin>>n)
	{
		if (n == 4)
			break;
		switch (n)
		{
		case 1:  // 从键盘输入一个DFA，然后对它调用min_Watson进行最小化
		{
			system("cls");
			std::cin >> ffa;
			flag = true;

			DFA_components dfa_com = ffa.getDFA();

			DFA dfa(dfa_com);

			std::cout << dfa.min_Watson() << std::endl;

			hint();
			usage();
		}
			break;
		case 2:  // 把选项 1 输入的DFA转换成 .ADS 文件
		{
			system("cls");
			if (!flag)
			{
				std::cout << "execute step 2 after step 1" << std::endl;
			}
			else
			{
				std::string filename;
				std::cout << "type in the .ADS file's name : " << std::flush;
				std::cin >> filename;
				while (filename == "")
				{
					std::cin >> filename;
				}
				if (-1 == filename.find(".ads") && -1 == filename.find(".ADS"))
				{
					filename += ".ADS";
				}

				std::transform(filename.begin(), filename.end(), filename.begin(), ::toupper); // 把输出文件名转换成大写

				ffa.perform(filename);

				std::cout << "\nsee details at the file" << filename << std::endl;
			}
		}
			hint();
			usage();
			break;
		case 3:
		{
			system("cls");
			std::cout << "type in the .ADS file's name: " << std::flush;
			std::string filename;
			std::cin >> filename;
			while (filename == "")
			{
				std::cin >> filename;
			}
			if (-1 == filename.find(".ads") && -1 == filename.find(".ADS"))
			{
				filename += ".ADS";
			}

			//std::transform(filename.begin(), filename.end(), filename.begin(), ::toupper); // 把输出文件名转换成大写

			ffa.adsToDFA(filename);
			DFA_components  dfa_com = ffa.getDFA();
			DFA dfa1(dfa_com);
			std::cout << dfa1 << std::endl;
		}
			hint();
			usage();
			break;
		default:
			break;
		}
	}
}

void usage()
{
	system("cls");
	std::cout << "#######################################################################################################" << std::endl;
	std::cout << "##                                                                                                   ##\n" << std::flush;
	std::cout << "##                                                                                                   ##\n" << std::flush;
	std::cout << "##           1 . type 1 to type in a DFA in console.                                                 ##\n" << std::flush;
	std::cout << "##           2 . type 2 to generate .ADS file for the TCT Tool.(execute after step 1)                ##\n" << std::flush;
	std::cout << "##           3 . type 3 to read in a .ADS file to get a DFA object.                                  ##\n" << std::flush;
	std::cout << "##           4 . type 4 to quit.                                                                     ##\n" << std::flush;
	std::cout << "##                                                                                                   ##\n" << std::flush;
	std::cout << "##                                                                                                   ##\n" << std::flush;
	std::cout << "#######################################################################################################" << std::endl;
}

void hint()
{
	fflush(stdin);
	std::cout << "\n\n  press Enter to continue" << std::endl;
	char c;
	c = getchar();
	c = 0;
	while (c = getchar())
	{
		if (c == '\n')
			break;
	}
}