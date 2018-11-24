/*************************************************************************
    > File Name: main.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Mon 19 Nov 2018 02:30:23 PM CST
 ************************************************************************/


#include "../const.h"
#include "../header.h"
#include "../Doublelinklist.h"
#include "../function.h"
#include "test.h"

int main(int argc, char const *argv[])
{

	int choose;
	char contiueYesNO;
	Doublelinklist<int> S;
	S.insert(1,1);
	S.insert(2,2);
	S.insert(3,3);
	S.insert(4,4);
	S.insert(5,5);
	S.insert(6,6);
	S.insert(7,7);
	while(1)
	{
		cout << "*********测试循环双链表的操作**********";
		cout << "1. 取循环双链表第i个结点数据" << endl;
		cout << "2. 在第i个结点之前插入一个数据域为e的结点" << endl;
		cout << "3. 判断循环双链表是否为空" << endl;
		cout << "4. 求循环双链表中结点的个数 " << endl;
		cout << "5. 返回循环双链表中数据为e的一个结点指针" << endl;
		cout << "6. 返回某结点的前驱结点数据" << endl;
		cout << "7. 返回某结点的后继结点数据" << endl;
		cout << "8. 删除循环双链表中第一个数据为e的结点" << endl;
		cout << "9. 把一个循环双链表赋值给另一个循环双链表" << endl;
		cout << "10. 把循环双链表置空" << endl;
		cout << "11. 随机生成循环双链表" << endl;
 		cout << "12. 用已有的循环双链表初始化另一个循环双链表" << endl;
		cout << "13. 输入循环双链表" << endl;
		cout<< "  其他.结束"<< endl;
		cout << "当前循环双链表为：" << endl;
		cout<< "////////////////////////////////////////"<<endl;
		S.show();
		cout<<"//////////////////////////////////////////"<<endl;
		cout<<"Please enter your operate code(1-13):";
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
			case 10: ex3_1_10(S);
			break;
			case 11: ex3_1_11(S);
			break;
			case 12: ex3_1_12(S);
			break;
			case 13: ex3_1_13(S);
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