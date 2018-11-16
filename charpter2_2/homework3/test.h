/*************************************************************************
    > File Name: test.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月16日 星期五 09时57分18秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

template <typename ElemType>
void ex3_1_1(Linklist<ElemType> &S)
{
	cout << "*****取非循环单链表的第i个结点******" << endl;
	int i;
	ElemType e;
	cout << "Please enter number of node(1-" << S.getLength() << "):";
	cin >> i;
	cout << "你要取的第" << i << "个节点非循环单链表的数据域为:";
	S.getElem(i, e);
	cout << e; 
	cout << "**********************************" << endl;
}


template <typename ElemType>
void ex3_1_2(Linklist<ElemType> &S)
{
	
	cout << "*****在第i个结点之前插入一个数据域为e的结点******" << endl;
	int i;
	ElemType e;
	cout << "请输入你要在它之前插入节点的序号:";
	cin >> i;
	cout << "请输入你要插入的数据域:";
	cin >> e;
	S.insert(i, e);
	cout << "你已经在第" << i << "个节点之前插入一个数据域为" << e << "的元素" << endl;
	show(S);
	cout << "**********************************" << endl;
}


template <typename ElemType>
void ex3_1_3(Linklist<ElemType> &S)
{
	
	cout << "*****判断非循环单链表是否为空******" << endl;
	if(S.isEmpty())
		cout << "非循环单链表为空" << endl;
	else
		cout << "非循环单链表不为空" << endl;
	cout << "**********************************" << endl;
}


template <typename ElemType>
void ex3_1_4(Linklist<ElemType> &S)
{
	
	cout << "******求非循环单链表中结点的个数*****" << endl;
	cout << "非循环单链表中结点的个数为:" << S.getLength() << endl;
	cout << "**********************************" << endl;
}


template <typename ElemType>
void ex3_1_5(Linklist<ElemType> &S)
{
	
	cout << "*****查我第1个与e满足compare()关系的结点******" << endl;
	
	ElemType e;
	int i;
	cout << "*****************查找第1个与某元素满足相等关系元素的序号*****************" << endl;
	cout << "查找等于某个元素的操作" << endl;
	cout << "其输入你想查找的元素:";
	cin >> e;
	S.locateElem(e, equal, i);
	cout << "你想查找的第一个等于" << e << "的元素序号为:" << i << endl;

	cout << "*****************查找第1个与某元素满足大于关系元素的序号*****************" << endl;
	cout << "查找大于某个元素的操作" << endl;
	cout << "其输入你想查找的元素:";
	cin >> e;
	S.locateElem(e, bigger, i);
	cout << "你想查找的第一个大于" << e << "的元素序号为:" << i << endl;

	cout << "*****************查找第1个与某元素满足小于关系元素的序号*****************" << endl;
	cout << "查找小于某个元素的操作" << endl;
	cout << "其输入你想查找的元素:";
	cin >> e;
	S.locateElem(e, lesser, i);
	cout << "你想查找的第一个小于" << e << "的元素序号为:" << i << endl;

	cout << "**********************************" << endl;
}


template <typename ElemType>
void ex3_1_6(Linklist<ElemType> &S)
{
	
	cout << "*****返回某结点前驱的数据域******" << endl;
	ElemType e, prior_e;
	cout << "请输入你要查找的结点的数据域:";
	cin >> e;
	S.priorElem(e, prior_e);
	cout << "你要查找的前驱结点的数据域为:" << prior_e << endl;
	cout << "**********************************" << endl;
}

template <typename ElemType>
void ex3_1_7(Linklist<ElemType> &S)
{
	
	cout << "*****返回某结点后继的数据域******" << endl;
	ElemType e, next_e;
	cout << "请输入你要查找的结点的数据域:";
	cin >> e;
	S.nextElem(e, next_e);
	cout << "你要查找的后继结点的数据域为:" << next_e << endl;
	cout << "**********************************" << endl;
}


template <typename ElemType>
void ex3_1_8(Linklist<ElemType> &S)
{
	
	cout << "*****删除非循环单链表中数据域为e的第一个结点******" << endl;
	ElemType e;
	cout << "请输入你要删除的结点的数据域:";
	cin >> e;
	S.deleteElem(e);
	cout << "删除后的非循环单链表为:" <<endl;
	show(S);
	cout << "**********************************" << endl;
}


template <typename ElemType>
void ex3_1_9(Linklist<ElemType> &S)
{
	
	cout << "****删除非循环单链表中重复的取数值*******" << endl;
	S.deleteRepeat();
	show(S);
	cout << "**********************************" << endl;
}


template <typename ElemType>
void ex3_1_10(Linklist<ElemType> &S)
{
	
	cout << "****非循环单链表逆转*******" << endl;
	S.adverse();
	show(S);
	cout << "**********************************" << endl;
}


template <typename ElemType>
void ex3_1_11(Linklist<ElemType> &S)
{
	
	cout << "*****把一个非循环单链表赋值给另外一个非循环单链表******" << endl;
	
	Linklist<int> S1;
	S1.insert(1, 1);
	S1.insert(2, 2);
	S1.insert(3, 3);
	S1.insert(4, 4);
	S1.insert(5, 5);
	S1.insert(6, 6);
	S1.insert(7, 7);
	S1.insert(8, 8);
	S = S1;
	cout << "把另外一个非循环单链表赋值给当前非循环单链表为:";
	show(S);
	cout << "**********************************" << endl;
}


template <typename ElemType>
void ex3_1_12(Linklist<ElemType> &S)
{
	
	cout << "******把非循环单链表置空*****" << endl;
	S.clear();
	cout << "当前非循环单链表的置空，节点个数为:" << S.getLength() << endl;
	cout << "**********************************" << endl;
}



template <typename ElemType>
void ex3_1_13(Linklist<ElemType> &S)
{
	
	cout << "****随机生成非循环单链表*******" << endl;
	S.clear();
	int i = rand()%20; //结点个数
	ElemType e;
	for(int j=1; j <= i; j++)
	{
		e = rand()%500 + 1;
		S.insert(j, e);
	}
	cout << "随机生成非循环单链表为:" << endl;
	show(S);
	cout << "**********************************" << endl;
}


template <typename ElemType>
void ex3_1_14(Linklist<ElemType> &S)
{
	cout << "*****用已有的非循环单链表初始化另一个非循环单链表******" << endl;
	Linklist<int> S1(S);
	cout << "用当前非循环单链表初始化另一个非循环单链表为:" << endl;
	show(S1);
	cout << "**********************************" << endl;
	
}


template <typename ElemType>
void ex3_1_15(Linklist<ElemType> &S)
{
	
	cout << "*****输入非循环单链表******" << endl;
	S.clear();
	int i;
	ElemType e;
	cout << "请输入结点个数:" ;
	cin >> i;
	for(int j = 1; j <= i; j++)
	{
		cout << "请输入第" << j << "个节点数据域:";
		cin >> e;
		S.insert(j, e);
	}
	cout << "输入非循环单链表为:"<< endl;
	show(S);
	cout << "**********************************" << endl;
}


void ex3_1_16()
{
	
	cout << "****多项式运算*******" << endl;

	int choice;
	char coutinueyesno;
	MyPolynomialLinklist<MyTerm> P;
	P.randomInitalFill();
	while(1)
	{

		cout << "\t16.1 判断多项式是否为空" << endl;
		cout << "\t16.2 把一个多项式赋值给另一个多项式" << endl;
		cout << "\t16.3 俩个多项式的加法" << endl;
		cout << "\t16.4 两个多项式的减法" << endl;
		cout << "\t16.5 设置多项式为空多项式" << endl;
		cout << "\t16.6 随机生成多项式" << endl;
		cout << "\t16.7 用已有的多项式初始化另一个多项式" << endl;
		cout << "\t16.8 输入多项式" << endl;
		cout << "\t其他结束" << endl;
		cout << "/////////////////////////////" << endl;
		cout << "当前多项式为（采用非循环单链表）" << endl;
		cout << P << endl;
		cout << "//////////////////////////////" << endl;
		cout << "请输入你的操作代码(1-8):" ;
		cin >> choice;
		switch(choice)
		{
			case 1: ex3_2_1(P);
			break;
			case 2: ex3_2_2(P);
			break;
			case 3: ex3_2_3(P);
			break;
			case 4: ex3_2_4(P);
			break;
			case 5: ex3_2_5(P);
			break;
			case 6: ex3_2_6(P);
			break;
			case 7: ex3_2_7(P);
			break;
			case 8: ex3_2_8(P);
			break;
			default:cout << "you choice is end" << endl;
			break;
		}
		cout << "coutinue Yes(Y) or No(N):";
		cin >> coutinueyesno;
		if(coutinueyesno == 'N' || coutinueyesno == 'n')
			break;
	}
	cout << "**********************************" << endl;
}

#endif
