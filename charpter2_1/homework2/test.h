/*************************************************************************
    > File Name: test.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月09日 星期五 10时21分55秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

template<typename ElemType>
void ex3_1_1(Sqlist<ElemType> &S)
{
	cout << "***********在第i个元素之前插入一个元素****************\n";
	int i;
	ElemType e;
	cout<<"请你输入要在第几个元素前插入元素:";
	cin >> i;
	cout << "请输入元素的值:";
	cin >> e;
	cout << "你要在第" << i << " 个元素前插入 " << e << endl;
	S.ListInsert_Sq(i, e);

	cout << "插入后的顺序表为:"<< endl;
	show(S);
	cout << "**********************************" << endl;

}


template<typename ElemType>
void ex3_1_2(Sqlist<ElemType> &S)
{
	cout << "***************判断顺序表是否为空*******************" << endl;
	cout << "当前顺序表";
	if(! S.isEmpty())
		cout<<"不";
	cout<<"为空" << endl;
	cout << "**********************************" << endl;
}

template<typename ElemType>
void ex3_1_3(Sqlist<ElemType> &S)
{
	cout << "****************求顺序表中元素的个数******************" << endl;
	cout << "顺序表元素个数为:" << S.getLength() << endl;
	cout << "**********************************" << endl;
}

template<typename ElemType>
void ex3_1_4(Sqlist<ElemType> &S)
{
	int i;
	ElemType e = 0;
	cout << "*******************取第i个元素***************" << endl;
	cout << "请输入你想取元素的序号(1-"<<S.getLength()<<"):";
	cin >> i;
	S.getElem(i, e);
	cout << "你想取的第" << i << "个元素的数值为:" << e<< endl;
	cout << "**********************************" << endl;
}

template<typename ElemType>
void ex3_1_5(Sqlist<ElemType> &S)
{
	ElemType e;
	cout << "*****************查找第1个与某元素满足相等关系元素的序号*****************" << endl;
	cout << "查找等于某个元素的操作" << endl;
	cout << "其输入你想查找的元素:";
	cin >> e;
	cout << "你想查找的第一个等于" << e << "的元素序号为:" << S.LocateElem_Sq(e, equal) << endl;

	cout << "*****************查找第1个与某元素满足大于关系元素的序号*****************" << endl;
	cout << "查找大于某个元素的操作" << endl;
	cout << "其输入你想查找的元素:";
	cin >> e;
	cout << "你想查找的第一个大于" << e << "的元素序号为:" << S.LocateElem_Sq(e, bigger) << endl;

	cout << "*****************查找第1个与某元素满足小于关系元素的序号*****************" << endl;
	cout << "查找小于某个元素的操作" << endl;
	cout << "其输入你想查找的元素:";
	cin >> e;
	cout << "你想查找的第一个小于" << e << "的元素序号为:" << S.LocateElem_Sq(e, lesser) << endl;

	cout << "**********************************" << endl;
}

template<typename ElemType>
void ex3_1_6(Sqlist<ElemType> &S)
{
	ElemType  prior_e = 0;
	ElemType e;
	int i;
	cout << "*****************返回某元素的前驱*****************" << endl;
	cout << "你想查找其前躯的元素为:";
	cin >> e;
	i = S.PriorElem(e, prior_e);
	if(i)
		cout << "你想查找的" << e << "元素的前躯为" << prior_e << endl; 
	else
		cout << "你想查找的" << e << "元素的前躯" << "不存在" << endl;
	cout << "**********************************" << endl;
}

template<typename ElemType>
void ex3_1_7(Sqlist<ElemType> &S)
{
	cout << "****************返回某元素的后继******************" << endl;
	ElemType  next_e = 0;
	ElemType e;
	int i;
	cout << "你想查找其后继的元素为:";
	cin >> e;
	i = S.nextElem(e, next_e);
	if(i)
		cout << "你想查找的" << e << "元素的后继为" << next_e << endl; 
	else
		cout << "你想查找的" << e << "元素的后继" << "不存在" << endl;
	cout << "**********************************" << endl;
}

template<typename ElemType>
void ex3_1_8(Sqlist<ElemType> &S)
{
	cout << "****************删除第i个元素******************" << endl;
	int i;
	ElemType e;
	cout<<"请你输入要删除元素序号(1-"<< S.getLength()<< "):";
	cin >> i;
	S.ListDelete_Sq(i, e);
	cout << "你要删除的第" << i << " 个元素数值为 " << e << endl;
	cout << "删除后的顺序表为:"<< endl;
	show(S);
	cout << "**********************************" << endl;
}

template<typename ElemType>
void ex3_1_9(Sqlist<ElemType> &S)
{
	cout << "****************把一个顺序表赋值给另一个顺序表******************" << endl;
	Sqlist<int> S1;
	S1.ListInsert_Sq(1, 41);
	S1.ListInsert_Sq(1, 42);
	cout << "赋值顺序表S1为:" << endl;
	show(S1);
	S = S1;
	cout << "被赋值顺序表为S:" << endl;
	show(S);
	cout << "**********************************" << endl;
}

template<typename ElemType>
void ex3_1_10(Sqlist<ElemType> &S)
{
	cout << "******************把顺序表置空****************" << endl;
	S.clear();
	cout << "把顺序表置空后," <<"元素个数为" << S.getLength()<<endl; 
	cout << "**********************************" << endl;
}

template<typename ElemType>
void ex3_1_11(Sqlist<ElemType> &S)
{
	S.clear();
	cout << "***************随机生成顺序表（元素值为0到99之间的整数）*******************" << endl;
	int i;
	i = rand()%20 + 1;
	for(int j = 1; j <= i; j++)
	{
		S.ListInsert_Sq(1, rand()%100 + 1);
	}
	cout << "随机生成的顺序表为:" << endl;
	show(S);
	cout << "**********************************" << endl;
}


template<typename ElemType>
void ex3_1_12(Sqlist<ElemType> &S)
{
	cout << "****************用已有的顺序表初始化另一个顺序表******************" << endl;
	cout << "已有的顺序表:" << endl;
	show(S);
	Sqlist<int> S1(S);
	cout << "初始化的一个顺序表:" << endl;
	show(S1);
	cout << "**********************************" << endl;
}


template<typename ElemType>
void ex3_1_13(Sqlist<ElemType> &S)
{
	int n;
	S.clear();
	ElemType e;
	cout << "***************输入顺序表*******************" << endl;
	cout << "请输入顺序表元素个数:";
	cin >> n;
	for(int i=1; i<=n; i++ )
	{
		cout << "请输入第" << i << "个元素数值:";
		cin >> e;
		S.ListInsert_Sq(i, e);
	}
	cout << "输入后顺序表为:"<<endl;
	show(S);
	cout << "**********************************" << endl;
}

void ex3_1_14()
{
	cout << "***************两个顺序表的并交差运算*******************" << endl;
	Sqlist<int> L1;
	L1.ListInsert_Sq(1, 2);
	L1.ListInsert_Sq(2, 12);
	L1.ListInsert_Sq(3, 42);
	L1.ListInsert_Sq(4, 23);
	L1.ListInsert_Sq(5, 11);
	L1.ListInsert_Sq(6, 15);
	cout << "第一个顺序表为:"<<endl;
	show(L1);
	Sqlist<int> L2;
	L2.ListInsert_Sq(1, 7);
	L2.ListInsert_Sq(2, 11);
	L2.ListInsert_Sq(3, 15);
	L2.ListInsert_Sq(4, 42);
	L2.ListInsert_Sq(5, 3);
	L2.ListInsert_Sq(6, 5);
	cout << "第二个顺序表为:"<<endl;
	show(L2);
	Sqlist<int> L3;
	
	cout << "******求交集****"<<endl;
	L3 = intersectionSet(L1, L2);
	cout << "交集为:"<<endl;
	show(L3);

	cout << "******求并集******" << endl;
	L3 = unionSet(L1, L2);
	cout << "并集为:" <<endl;
	show(L3);

	cout << "******补集为*****" << endl;
	L3 = differenceSet(L1, L2);
	cout << "补集为:" <<endl;
	show(L3);
	cout << "**********************************" << endl;
}



void ex3_1_15()
{
	int choose;
	char continueYesNo;
	Sqlist<Student> S;
	Student student1;
	char *p =  "刘必勇";
	char *p1 = "刘必";
	student1.setstu(1, p, 100, 99, 100);
	S.ListInsert_Sq(1, student1);
	Student student2;
	student2.setstu(11, p1, 12, 92, 87);
	S.ListInsert_Sq(2, student2);
	while(1)
	{
		cout << "*************学生信息管理*********************" << endl;
		cout << "14.1 在第i个学生之前插入新学生 " << endl;
		cout << "14.2 判断学生表是否为空" << endl;
		cout << "14.3 求学生表中学生的人" << endl;
		cout << "14.4 返回学生表中第i个学生" << endl;
		cout << "14.5 返回某姓名学生的前驱" << endl; 
		cout << "14.6 返回某姓名学生的后继" << endl;
		cout << "14.7 删除学生表中第i个学生" << endl;
		cout << "14.8 把一个学生表赋值给另一个学生表" << endl;
		cout << "14.9 设置学生表为空表" << endl;
		cout << "14.10 随机生成学生表" << endl;
		cout << "14.11 用已经有的学生表初始话另一个学生表" << endl;
		cout << "14.12 输入学生表" << endl;
		cout << "其他 结束" << endl;
		cout << "**********************************" << endl;
		cout << "The student table have(squence table)" << S.getLength() <<"students" <<endl;
		showS(S);
		cout<<"************************************"<<endl;
		cout<<"Please enter your operate code(1-12):";
		cin >> choose;
		
		switch(choose)
		{

			case 1: ex3_2_1(S);
			break;
			case 2: ex3_2_2(S);
			break;
			case 3: ex3_2_3(S);
			break;
			case 4: ex3_2_4(S);
			break;
			case 5: ex3_2_5(S);
			break;
			case 6: ex3_2_6(S);
			break;
			case 7: ex3_2_7(S);
			break;
			case 8: ex3_2_8(S);
			break;
			case 9: ex3_2_9(S);
			break;
			case 10: ex3_2_10(S);
			break;
			case 11: ex3_2_11(S);
			break;
			case 12: ex3_2_12(S);
			break;
			default: cout<<"\n you choice have ended"<<endl<<endl;
				return ;
		}
		
		cout<<"continue?(Y.continue\tN.end)";
		cin >> continueYesNo;
		if(continueYesNo == 'N' || continueYesNo == 'n')
			break;		
	}
}

#endif
