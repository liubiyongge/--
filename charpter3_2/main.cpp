/*************************************************************************
    > File Name: main.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Sat 24 Nov 2018 09:13:15 AM CST
 ************************************************************************/


#include "header.h"
#include "const.h"
#include "linkStack.h"
#include "test.h"

int main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));
	LinkStack<int> S;
	int choose;
	char contiueYesNO;
	S.push(3);
	S.push(5);
	S.push(7);
	S.push(9);

	while(1)
	{
		cout << "*********测试链栈的操作**********\n";
		cout << "1. 在栈顶压入元素e" << endl;
		cout << "2. 弹出栈顶元素到e" << endl;
		cout << "3. 读栈顶元素" << endl;
		cout << "4. 判读顺序栈是否为空" << endl;
		cout << "5. 求顺序栈中元素的个数" << endl;
		cout << "6. 把一个链栈赋值给另一个链栈" << endl;
		cout << "7. 把链栈置空" << endl;
		cout << "8. 随机生成链栈" << endl;
		cout << "9. 用已有的链栈初始化另一个链栈" << endl;	
		cout<< "  其他.结束"<< endl;
		cout << "当前链栈为：" << endl;
		cout<< "////////////////////////////////////////"<<endl;
		S.show();
		cout<<"//////////////////////////////////////////"<<endl;
		cout<<"Please enter your operate code(1-9):";
		cin >> choose;
		switch(choose)
		{
			case 1: ex3_1_1(S);
			break;
			case 2: ex3_1_2(S);
			break;
			case 3: ex3_1_3(S);
			break;
			case 4: ex3_1_4(S);
			break;
			case 5: ex3_1_5(S);
			break;
			case 6: ex3_1_6(S);
			break;
			case 7: ex3_1_7(S);
			break;
			case 8: ex3_1_8(S);
			break;
			case 9: ex3_1_9(S);
			break;
			default: cout<<"\n you choice have ended"<<endl<<endl;
				return 0;
		} 
		cout<<"continue?(Y.continue\tN.end)";
		cin >> contiueYesNO;
		if(contiueYesNO == 'N' || contiueYesNO == 'n')
			break;	

	}	
	return 0;
}

