/*************************************************************************
    > File Name: main.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月02日 星期五 11时52分30秒
 ************************************************************************/
#include "../header.h" // head file in

#include "../const.h" // const type in 

#include "../class_outfunction.h" 
#include "../class_function.h" //class 
#include "Student.h" //class

#include "../function.h"
#include "../mySetSqlist.h"
#include "test_Student.h"
#include "test.h"

int main()
{
	std::locale::global(std::locale("zh_CN.UTF-8"));
	srand((unsigned)time(NULL));
	Sqlist<int> S;
	int choose; //存放操作代码
	char contiueYesNO;
	S.ListInsert_Sq(1, 20);
	S.ListInsert_Sq(2, 85);
	S.ListInsert_Sq(3, 45);
	S.ListInsert_Sq(4, 51);
	S.ListInsert_Sq(5, 15);
	S.ListInsert_Sq(6, 95);
	S.ListInsert_Sq(7, 66);
	S.ListInsert_Sq(8, 62);
	while(1)
	{

		cout << "*************test sequence table operate*********" << endl;
		cout<< "********** 测试顺序表的操作 **********"<<endl<< endl;
        cout<< "\t 1.在第i个元素之前插入一个元素"<< endl;
        cout<< "\t 2.判断顺序表是否为空"<< endl;
        cout<< "\t 3.求顺序表中元素的个数"<< endl;
        cout<< "\t 4.取第i个元素"<< endl;
        cout<< "\t 5.查找第1个与某元素满足相等关系元素的序号"<< endl;
        cout<< "\t 6.返回某元素的前驱"<< endl;
        cout<< "\t 7.返回某元素的后继"<< endl;
        cout<< "\t 8.删除第i个元素"<< endl;
        cout<< "\t 9.把一个顺序表赋值给另一个顺序表"<< endl;
        cout<< "\t10.把顺序表置空"<< endl;
        cout<< "\t11.随机生成顺序表（元素值为0到99之间的整数）"<< endl;
        cout<< "\t12.用已有的顺序表初始化另一个顺序表"<< endl;
        cout<< "\t13.输入顺序表"<< endl;
        cout<< "\t14.两个顺序表的并交差运算"<< endl;
        cout<< "\t15.学生信息管理"<< endl;
        cout<< "  其他.结束"<< endl;
        cout<< "////////////////////////////////////////"<<endl;
        cout<< "the sequence have " << S.getLength() <<":"<<endl;
        show(S);
        cout<<"//////////////////////////////////////////"<<endl;
		cout<<"Please enter your operate code(1-15):";
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
			case 14: ex3_1_14();
			break;
			case 15: ex3_1_15();
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