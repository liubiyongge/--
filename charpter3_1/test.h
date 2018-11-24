/*************************************************************************
    > File Name: test.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Fri 23 Nov 2018 01:58:30 PM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
template <typename T>
void ex3_1_1(SqStack<T> &S)
{
	cout << "** 在栈顶压入元素e***\n";
	T e;
	cout << "请输入压到栈顶元素的数值：";
	cin >> e;
	S.push(e);
	cout << "压入元素" << e << "后新的栈为:\n";
	S.show();
	cout << "*******************\n";
}

template <typename T>
void ex3_1_2(SqStack<T> &S)
{
	cout << "**弹出栈顶元素到e***\n";
	T e;
	S.pop(e);
	cout<<"弹出栈顶元素为:"<< e << endl;
	cout << "弹出栈顶元素后，新的栈为：\n";
	S.show(); 
	cout << "*******************\n";
}


template <typename T>
void ex3_1_3(SqStack<T> &S)
{
	cout << "**读栈顶元素***\n";
	T e;
	S.getTop(e);
	cout << "栈顶元素为:" << e << endl;
	cout << "*******************\n";
}


template <typename T>
void ex3_1_4(SqStack<T> &S)
{
	cout << "**判读顺序栈是否为空***\n";
	if(S.isEmpty())
		cout << "顺序栈为空\n";
	else
		cout << "顺序栈不为空'\n";

	cout << "*******************\n";
}


template <typename T>
void ex3_1_5(SqStack<T> &S)
{
	cout << "**求顺序栈中元素的个数***\n";
	cout << "顺序栈中元素的个数为" << S.getLength() << endl;
	cout << "*******************\n";
}

template <typename T>
void ex3_1_6(SqStack<T> &S)
{
	cout << "***把一个顺序栈赋值给另一个顺序栈**\n";
	SqStack<int> S1;
	S1 = S;
	cout << "当前顺序栈赋值给另一个顺序栈为:\n";
	S1.show();
	cout << "*******************\n";
}


template <typename T>
void ex3_1_7(SqStack<T> &S)
{
	cout << "**把顺序栈置空***\n";
	S.clear();
	cout << "当前顺序栈元素个数为:" << S.getLength() << endl ;
	cout << "*******************\n";
}

template <typename T>
void ex3_1_8(SqStack<T> &S)
{
	cout << "**随机生成顺序栈***\n";
	S.clear();
	int i = rand()%20; //结点个数
	T e;
	for(int j=1; j <= i; j++)
	{
		e = rand()%500 + 1;
		S.push(e);
	}
	cout << "随机生成顺序栈为:" << endl;
	S.show();
	cout << "*******************\n";
}



template <typename T>
void ex3_1_9(SqStack<T> &S)
{
	cout << "**用已有的顺序栈初始化另一个顺序栈***\n";
	SqStack<int> S1(S);
	cout << "当前顺序栈初始化另一个顺序栈为:\n";
	S1.show();
	cout << "*******************\n";
}


void ex3_1_10()
{
	
	int choose;
	char continueYesNo;
	char expresion[30] = "23-((34-13)*7+6/2)";
	char suffixS[50];
	transform(expresion, suffixS);
	while(1)
	{

		cout << "18.1 \t 中缀表达式变为后缀表达式\n";
		cout << "18.2 \t 后缀表达式的的计算\n";
		cout << "18.3 \t　输入后缀表达式'\n";
		cout << "其他结束\n";
		cout << "当前中缀表达式为:\n";
		cout << expresion << endl;
		cout << "Please enter your operate code(1-3):";
		cin >> choose;

		switch(choose)
		{
			case 1: test1(expresion, suffixS);
			break;
			case 2: test2(suffixS);
			break;
			case 3:test3(expresion);
			break;
			default: cout<<"\n you choice have ended"<<endl<<endl;
				return;
		}
		cout<<"continue?(Y.continue\tN.end)";
		cin >> continueYesNo;
		if(continueYesNo == 'N' || continueYesNo == 'n')
			break;		
	}
	cout << "*******************\n";
}


void ex3_1_11()
{
	cout << "**迷宫求解***\n";
	int choose;
	char continueYesNo;
	MapType maze = {
	{ 1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,1,0,0,0,1,0,1 },
	{ 1,0,0,1,0,0,0,1,0,1 },
	{ 1,0,0,0,0,1,1,0,0,1 },
	{ 1,0,1,1,1,0,0,0,0,1 },
	{ 1,0,0,0,1,0,0,0,0,1 },
	{ 1,0,1,0,0,0,1,0,0,1 },
	{ 1,0,1,1,1,0,1,1,0,1 },
	{ 1,1,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1 },
	};
	while(1)
	{

		cout << "11.1 \t 走迷宫\n";
		cout << "1１.2 \t 把一个迷宫赋值给另一个迷宫\n";
		cout << "11.3 \t　随机生成迷宫\n";
		cout << "11.4 \t 输入迷宫\n";
		cout << "其他结束\n";

		cout << "当前迷宫为:\n";
		printMaze(maze);
		cout << "Please enter your operate code(1-4):";
		cin >> choose;
		switch(choose)
		{
			case 1: test1_1(maze);
			break;
			case 2: test2_1(maze);
			break;
			case 3: test3_1(maze);
			break;
			case 4: test4_1(maze);
			break;
			default: cout<<"\n you choice have ended"<<endl<<endl;
				return;
		}
		cout<<"continue?(Y.continue\tN.end)";
		cin >> continueYesNo;
		if(continueYesNo == 'N' || continueYesNo == 'n')
			break;		
	}
	cout << "*******************\n";
}
#endif
