#include "GeneralizedList.h"

void displayGList(GList& item)
{
	cout << "\t当前广义表（采用头尾链表存储）如下：" << endl;
	cout << item << endl;
}

/*求广义表的深度*/
void ex8_1_1(GList& item, char& continueChar)
{
	cout << "\t*****************◆求广义表的深度◆*****************" << endl << endl;
	cout << "\t广义表的深度为：" << item.depth() << endl;



	/*调用ContinueOrNot()函数判断用户是否想继续*/
	ContinueOrNot(continueChar);
}


/*广义表的赋值运算*/
void ex8_1_2(GList& item, char& continueChar)
{
	cout << "\t*****************◆广义表的赋值运算◆*****************" << endl << endl;
	SqString S = "(a,((),b),(((e))))";
	GList otherL;
	otherL.createGList(S);
	cout << "\t另一个广义表为：" << endl << otherL << endl;
	otherL = item;
	cout << "\t把当前的广义表赋值给另一个广义表为：" << endl << otherL << endl;



	/*调用ContinueOrNot()函数判断用户是否想继续*/
	ContinueOrNot(continueChar);
}

/*求广义表的长度*/
void ex8_1_3(GList& item, char& continueChar)
{
	cout << "\t*****************◆求广义表的长度◆*****************" << endl << endl;

	cout << "\t广义表的长度为：" << item.length() << endl;


	/*调用ContinueOrNot()函数判断用户是否想继续*/
	ContinueOrNot(continueChar);
}

/*判断广义表是否为空*/
void ex8_1_4(GList& item, char& continueChar)
{
	cout << "\t*****************◆判断广义表是否为空◆*****************" << endl << endl;

	if (item.isEmpty())
		cout << "\t当前广义表为空" << endl;
	else
		cout << "\t当前广义表不为空" << endl;


	/*调用ContinueOrNot()函数判断用户是否想继续*/
	ContinueOrNot(continueChar);
}

/*取广义表的表头*/
void ex8_1_5(GList& item, char& continueChar)
{
	cout << "\t*****************◆取广义表的表头◆*****************" << endl << endl;
	GList head;
	item.getHead(head);
	cout << "\t广义表的表头为：" << endl << head << endl;



	/*调用ContinueOrNot()函数判断用户是否想继续*/
	ContinueOrNot(continueChar);
}

/*取广义表的表尾*/
void ex8_1_6(GList& item, char& continueChar)
{
	cout << "\t*****************◆取广义表的表尾◆*****************" << endl << endl;
	GList tail;
	item.getTail(tail);
	cout << "\t广义表的表尾为：" << endl << tail << endl;



	/*调用ContinueOrNot()函数判断用户是否想继续*/
	ContinueOrNot(continueChar);
}

/*删除广义表的表头*/
void ex8_1_7(GList& item, char& continueChar, GList& head)
{
	cout << "\t*****************◆删除广义表的表头◆*****************" << endl << endl;
	item.deleteHead(head);
	cout << "\t删除广义表的表头：" << endl <<  head << endl;
	cout << endl << "\t删除后，广义表为：" << endl << item << endl << endl;


	/*调用ContinueOrNot()函数判断用户是否想继续*/
	ContinueOrNot(continueChar);
}

/*插入一个广义表作为广义表的表头*/
void ex8_1_8(GList& item, char& continueChar, GList& head)
{
	cout << "\t*****************◆插入一个广义表作为广义表的表头◆*****************" << endl << endl;
	cout << "\t插入广义表：" << endl << head << endl << endl;
	item.insertHead(head);
	
	cout << "\t插入后，广义表为：" << endl <<  item << endl ;



	/*调用ContinueOrNot()函数判断用户是否想继续*/
	ContinueOrNot(continueChar);
}


/*用已有的广义表初始化另一个广义表*/
void ex8_1_9(GList& item, char& continueChar)
{
	cout << "\t*****************◆用已有的广义表初始化另一个广义表◆*****************" << endl << endl;
	GList otherL = item;
	cout << "\t当前广义表初始化另一个广义表为：" << endl << otherL << endl << endl;

	/*调用ContinueOrNot()函数判断用户是否想继续*/
	ContinueOrNot(continueChar);
}

/*以字符串形式输入广义表*/
void ex8_1_10(GList& item, char& continueChar)
{
	cout << "\t*****************◆以字符串形式输入广义表◆*****************" << endl << endl;
	cin >> item;



	/*调用ContinueOrNot()函数判断用户是否想继续*/
	ContinueOrNot(continueChar);
}

