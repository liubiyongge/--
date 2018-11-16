/*************************************************************************
    > File Name: main.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月15日 星期四 23时16分17秒
 ************************************************************************/

#include "../header.h"
#include "../const.h"
#include "../class_function.h"
#include "../Linklist.h"
#include "../MyTerm.h"
#include "../MyPolynomialLinklist.h"
#include "../function.h"
#include "polytest.h"
#include "test.h"

int main()
{
	srand((unsigned)time(NULL));
	Linklist<int> S;
	int choose; //存放操作代码
	char contiueYesNO;
	S.insert(1, 20);
	S.insert(2, 21);
	S.insert(3, 33);
	S.insert(4, 34);
	S.insert(5, 35);
	S.insert(6, 20);
	S.insert(7, 22);
	S.insert(8, 21);
	while(1)
	{

		cout<< "********** 测试非循环单链表的操作 **********"<<endl<< endl;
        cout<< "\t 1.取非循环单链表的第i个结点"<< endl;
        cout<< "\t 2.在第i个结点之前插入一个数据域为e的结点"<< endl;
        cout<< "\t 3.判断非循环单链表是否为空"<< endl;
        cout<< "\t 4.求非循环单链表中结点的个数"<< endl;
        cout<< "\t 5.查我第1个与e满足compare()关系的结点"<< endl;
        cout<< "\t 6.返回某结点前驱的数据域"<< endl;
        cout<< "\t 7.返回某结点后继的数据域"<< endl;
        cout<< "\t 8.删除非循环单链表中数据域为e的第一个结点"<< endl;
        cout<< "\t 9.删除非循环单链表中重复的取数值"<< endl;
        cout<< "\t10.非循环单链表逆转"<< endl;
        cout<< "\t11.把一个非循环单链表赋值给另外一个非循环单链表"<< endl;
        cout<< "\t12.把非循环单链表置空"<< endl;
        cout<< "\t13.随机生成非循环单链表"<< endl;
        cout<< "\t14.用已有的非循环单链表初始化里一个非循环单链表"<< endl;
        cout<< "\t15.输入非循环单链表"<< endl;
        cout<< "\t16.多项式运算"<< endl;
        cout<< "  其他.结束"<< endl;
        cout<< "////////////////////////////////////////"<<endl;
        cout<< "the sequence as follow: " << endl;
        show(S); // show S when data type is int
        cout<<"//////////////////////////////////////////"<<endl;
		cout<<"Please enter your operate code(1-16):";
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
			case 14: ex3_1_14(S);
			break;
			case 15: ex3_1_15(S);
			break;
			case 16: ex3_1_16();
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

