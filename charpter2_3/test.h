/*************************************************************************
    > File Name: test.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Tue 20 Nov 2018 10:10:51 PM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
template<typename ElemType>
void ex3_1_1(CircularLinklist<ElemType> &S)
{
	cout << "**判断循环单链表是否为空**\n:";
	if(S.isEmpty())
		cout << "循环单链表为空\n";
	else
		cout << "循环单链表不为空\n";
	cout << "***************" << endl;
}

template<typename ElemType>
void ex3_1_2(CircularLinklist<ElemType> &S)
{
	cout << "**把循环单链表的指针移动到第i个结点***\n";
	int i;
	cout << "请输入头指针移动到的节点序号(1-10):";
	cin >> i;
	S.moveHead(i);
	cout << "移动后头指针数据域为:";
	int e;
	S.getHeadElem(e);
	cout << e << endl;
	cout << "***************" << endl;
}




template<typename ElemType>
void ex3_1_3(CircularLinklist<ElemType> &S)
{
	cout << "*删除第i个结点头指针移动到下一个结点**\n";
	int i;
	int e;
	cout << "请输入删除节点序号(1-10):";
	cin >> i;
	S.deleteElem(i, e);
	cout << "删除第" << i << "个节点，数据为" << e << ",删除后循环单链表为:\n";
	S.show();
	cout << "***************" << endl;
}

template<typename ElemType>
void ex3_1_4(CircularLinklist<ElemType> &S)
{
	cout << "**把一个循环单链表赋值给另外一个循环单链表**\n";
	CircularLinklist<int> S1;
	S1 = S;
	cout << "被赋值的循环单链表为:\n";
	S1.show();
	cout << "***************" << endl;
}

template<typename ElemType>
void ex3_1_5(CircularLinklist<ElemType> &S)
{	
	cout << "把循环单链表置空\n";
	S.clear();
	cout << "当前循环单链表为:\n";
	S.show();
	cout << "***************" << endl;
}

template<typename ElemType>
void ex3_1_6(CircularLinklist<ElemType> &S)
{
	cout << "**随机生成循环单链表**\n";
	S.setCir();
	cout << "生成的循环单链表为：\n";
	S.show();
	cout << "******************8\n";
}

template<typename ElemType>
void ex3_1_7(CircularLinklist<ElemType> &S)
{
	cout << "**用一个已有循环单链表初始化另外一个循环单链表**\n";
	CircularLinklist<int> S1(S);
	cout << "被初始化的循环单链表为:\n";
	S1.show();
	cout << "******************8\n";
}

template<typename ElemType>
void ex3_1_8(CircularLinklist<ElemType> &S)
{
	
	cout << "*输入循环单链表*** \n";
	S.inputCir();
	cout << "输入后循环单链表为:\n";
	S.show();
	cout << "******************8\n";
}

template<typename ElemType>
void ex3_1_9(CircularLinklist<ElemType> &S)
{

	cout << "**** \n";;
	int i, j;
	cout << "当前约瑟夫环为当前约瑟夫环为:" << endl;
	S.show();
	cout << "请输入起始序号:" ;
	cin >> i;
	cout << "其输入间隔结点数";
	cin >> j;
	Josephus(S, i, j);
	cout << "******************8\n";
}

#endif
