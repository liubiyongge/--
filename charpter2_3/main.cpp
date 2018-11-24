/*************************************************************************
    > File Name: main.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月08日 星期四 19时41分13秒
 ************************************************************************/

#include "const.h"
#include "header.h"
#include "CircularLinklist.h"
#include "test.h"
#include "MyJosephus.h"
int main()
{

	srand((unsigned)time(NULL));
	int choose; //存放操作代码
	char contiueYesNO;
	CircularLinklist<int> S;
	S.setCir();
	while(1)
	{

		cout<< "********** 测试循环单链表的操作 **********"<<endl<< endl;
        cout<< "\t 1.判断循环单链表是否为空"<< endl;
        cout<< "\t 2.把循环单链表的指针移动到第i个结点"<< endl;
        cout<< "\t 3.删除第i个结点头指针移动到下一个结点"<< endl;
        cout<< "\t 4.把一个循环单链表赋值给另外一个循环单链表"<< endl;
        cout<< "\t 5.把循环单链表置空"<< endl;
        cout<< "\t 6.随机生成循环单链表"<< endl;
        cout<< "\t 7.用一个已有循环单链表初始化另外一个循环单链表"<< endl;
        cout<< "\t 8.输入循环单链表"<< endl;
        cout<< "\t 9.约瑟夫出列"<< endl;
        cout<< "  其他.结束"<< endl;
        cout<< "////////////////////////////////////////"<<endl;
        cout<< "the sequence as follow: " << endl;
        S.show(); // show S when data type is int
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

}


