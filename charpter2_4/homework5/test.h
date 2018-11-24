/*************************************************************************
    > File Name: test.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Fri 23 Nov 2018 12:27:12 PM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
template <typename Elemtype>
void ex3_1_1(Doublelinklist<Elemtype> &S)
{
	cout << "**取循环双链表第i个结点数据**\n";
	int i;
	Elemtype e;
	cout << "Please enter number of node(1-" << S.getLength() << "):";
	cin >> i;
	cout << "你要取的第" << i << "个节点循环双链表的数据域为:";
	S.getElem(i, e);
	cout << e; 
	cout << "**************************88\n";
}


template <typename Elemtype>
void ex3_1_2(Doublelinklist<Elemtype> &S)
{
	cout << "**在第i个结点之前插入一个数据域为e的结点**\n";
	int i;
	Elemtype e;
	cout << "请输入你要在它之前插入节点的序号:";
	cin >> i;
	cout << "请输入你要插入的数据域:";
	cin >> e;
	S.insert(i, e);
	cout << "你已经在第" << i << "个节点之前插入一个数据域为" << e << "的元素" << endl;
	S.show();
	cout << "**************************88\n";
}

template <typename Elemtype>
void ex3_1_3(Doublelinklist<Elemtype> &S)
{
	cout << "**判断循环双链表是否为空**\n";
	if(S.isEmpty())
		cout << "循环双链表为空\n";
	else
		cout << "循环双链表不为空\n";
	cout << "**************************88\n";
}


template <typename Elemtype>
void ex3_1_4(Doublelinklist<Elemtype> &S)
{
	cout << "**求循环双链表中结点的个数**\n";
	cout << "循环双链表中结点的个数为:" << S.getLength() << endl;
	cout << "**************************88\n";
}


template <typename Elemtype>
void ex3_1_5(Doublelinklist<Elemtype> &S)
{
	typename Doublelinklist<Elemtype>::NodePointer p;
	Elemtype e;
	cout << "**返回循环双链表中数据为e的一个结点指针**\n";
	cout << "其输入你想查找的元素:";
	cin >> e;
	S.locateElem(e, p);
	cout << "你想查找的第一个等于" << e << "的元素数值为:" << p->data << endl;
	cout << "**************************88\n";
}

template <typename Elemtype>
void ex3_1_6(Doublelinklist<Elemtype> &S)
{
	cout << "**返回某结点的前驱结点数据**\n";
	Elemtype e, prior_e;
	cout << "请输入你要查找的结点的数据域:";
	cin >> e;
	S.priorElem(e, prior_e);
	cout << "你要查找的前驱结点的数据域为:" << prior_e << endl;
	cout << "**************************88\n";
}

template <typename Elemtype>
void ex3_1_7(Doublelinklist<Elemtype> &S)
{
	cout << "**返回某结点的后继结点数据**\n";
	Elemtype e, next_e;
	cout << "请输入你要查找的结点的数据域:";
	cin >> e;
	S.nextElem(e, next_e);
	cout << "你要查找的后继结点的数据域为:" << next_e << endl;
	cout << "**************************88\n";
}

template <typename Elemtype>
void ex3_1_8(Doublelinklist<Elemtype> &S)
{
	cout << "**删除循环双链表中第一个数据为e的结点**\n";
	Elemtype e;
	cout << "请输入你要删除的结点的数据域:";
	cin >> e;
	S.deleteElem(e);
	cout << "删除后的循环双链表为:" <<endl;
	S.show();
	cout << "**************************88\n";
}

template <typename Elemtype>
void ex3_1_9(Doublelinklist<Elemtype> &S)
{
	cout << "*把一个循环双链表赋值给另一个循环双链表***\n";
	Doublelinklist<int> S1;
	S1.insert(1, 1);
	S1.insert(2, 2);
	S1.insert(3, 3);
	S1.insert(4, 4);
	S1.insert(5, 5);
	S1.insert(6, 6);
	S1.insert(7, 7);
	S1.insert(8, 8);
	S = S1;
	cout << "把另外一个循环双链表赋值给当前循环双链表为:\n";
	S.show();
	cout << "**************************88\n";
}

template <typename Elemtype>
void ex3_1_10(Doublelinklist<Elemtype> &S)
{
	cout << "**把循环双链表置空**\n";
	S.clear();
	cout << "当前非循环单链表的置空，节点个数为:" << S.getLength() << endl;
	cout << "**************************88\n";
}


template <typename Elemtype>
void ex3_1_11(Doublelinklist<Elemtype> &S)
{
	cout << "**随机生成循环双链表**\n";
	S.clear();
	int i = rand()%20; //结点个数
	Elemtype e;
	for(int j=1; j <= i; j++)
	{
		e = rand()%500 + 1;
		S.insert(j, e);
	}
	cout << "随机生成非循环单链表为:" << endl;
	S.show();
	cout << "**************************88\n";
}

template <typename Elemtype>
void ex3_1_12(Doublelinklist<Elemtype> &S)
{
	cout << "**用已有的循环双链表初始化另一个循环双链表**\n";
	Doublelinklist<int> S1(S);
	cout << "用当前非循环单链表初始化另一个非循环单链表为:" << endl;
	S1.show();
	cout << "**************************88\n";
}

template <typename Elemtype>
void ex3_1_13(Doublelinklist<Elemtype> &S)
{
	cout << "**输入循环双链表**\n";
	S.clear();
	int i;
	Elemtype e;
	cout << "请输入结点个数:" ;
	cin >> i;
	for(int j = 1; j <= i; j++)
	{
		cout << "请输入第" << j << "个节点数据域:";
		cin >> e;
		S.insert(j, e);
	}
	cout << "输入循环双链表为:"<< endl;
	S.show();
	cout << "**************************88\n";
}

#endif
