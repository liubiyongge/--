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

int main(int argc, char const *argv[])
{

	int choice;
	char continueYesOrNo;
	Doublelinklist<int> L;
	L.insert(1,1);
	L.insert(2,2);
	L.insert(3,3);
	L.insert(4,4);
	L.insert(5,5);
	L.insert(6,6);
	L.insert(7,7);
	while(1)
	{
		cout << "*********测试循环单链表的操作**********"
		cout << "1. 判断循环双链表是否为空" << endl;
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
		cout << "当前循环双链表为：" << endl;
		L.show();
		cout << "//////////////////////////////////" << endl;

		(choice)
		{

		}


	}	
	
	return 0;
}