#ifndef GENERALIZEDLIST_H_INCLUDE
#define GENERALIZEDLIST_H_INCLUDE

/*广义表的数据结构（基类）*/

#ifndef MYHEAD_H
#define MYHEAD_H
#include "myhead.h"
#endif

/*循环队列*/
#ifndef SQQUEUE_H
#define SQQUEUE_H
#include "SqQueue.h"
#endif

/*顺序串*/
#ifndef SQSTRING_H
#define SQSTRING_H
#include "SqString.h"
#endif


/*枚举类型，标记*/
typedef enum { ATOM, LIST } NodeTag;		//标记为ATOM为原子节点， LIST为表结点

/*将非空串str分成表头和表尾两部分, hStr存表头， tStr存表尾*/
void separate(SqString& hStr, SqString& tStr);




class GList
{
	/*输入输出广义表的友元函数*/
	friend istream& operator >> (istream& in, GList& item);
	friend ostream& operator << (ostream& out, GList& item);

public:
	/*广义表（采用头尾链表存储）的结点数据结构*/
	class GLNode
	{
	public:
		NodeTag tag;
		union
		{
			char atom;		//原子节点的值域
			struct
			{
				GLNode *hp;			//表结点的头结点
				GLNode *tp;			//表结点的尾节点
			}ptr;
		};

	};
	typedef GLNode* GListNodePointer;				//结点指针


	/*判断广义表是否为空*/
	bool isEmpty();

	/*求广义表表头加表尾的总长度*/
	int getLengthOfTailHead(GList::GListNodePointer GL);

	/*把字符串转换成广义表的形式*/
	void createGList(SqString S);

	/*删除广义表的表头*/
	Status deleteHead(GList& secondGL);

	/*求广义表的深度*/
	int depth();

	/*求广义表的长度*/
	int length();

	/*取广义表的表头*/
	Status getHead(GList& headGL);

	/*取广义表的根指针*/
	GListNodePointer getRoot()
	{
		return root;
	}

	/*取广义表的表尾*/
	Status getTail(GList& tailGL);

	/*插入一个广义表作为当前广义表的表头*/
	void insertHead(GList& secondGL);

	/*重载赋值运算符的定义*/
	GList operator = (const GList& rightGL);

	/*改变根指针所指向的广义表*/
	void setRoot(GListNodePointer p);

private:
	/*部分成员函数的内部辅助实现函数*/

	/*复制广义表的辅助函数*/
	void copyGList_aux(GListNodePointer& s, GListNodePointer p);

	/*将字符串转换成广义表的辅助函数*/
	void createGList_aux(GListNodePointer& L, SqString& s);

	/*求广义表深度的辅助函数*/
	int depth_aux(GListNodePointer s);

	/*析构函数的辅助函数*/
	void destruction_aux(GListNodePointer& p);

public:
	/*构造函数*/
	GList();

	/*析构函数*/
	virtual ~GList();

	/*拷贝构造函数*/
	GList(const GList& s);


private:
	GListNodePointer root;			//根指针

};

/*判断广义表是否为空*/
bool GList::isEmpty()
{
	return root == NULL;
}

/*析构函数的辅助函数*/
void GList::destruction_aux(GListNodePointer& p)
{
	if (!p)
		return;
	if (p->tag == LIST)
	{
		destruction_aux(p->ptr.hp);
		destruction_aux(p->ptr.tp);
	}

	delete p;

}

/*把字符串转换成广义表的形式*/
void GList::createGList(SqString S)
{
	/*回收广义表原有的空间，以便接收字符串转换而来的广义表*/
	destruction_aux(root);

	/*调用将字符串转换成广义表的辅助函数*/
	createGList_aux(root, S);

}

/*将字符串转换成广义表的辅助函数*/
void GList::createGList_aux(GListNodePointer& L, SqString& s)
{

	char c;
	SqString hS;

	if (!(s == "()"))		//如果S为空，说明这个表为空表, ==运算符满足是返回0
	{
		L = NULL;
		return;
	}

	L = new GLNode;
	assert(L != NULL);

	if (s.getLength() == 1)		//如果S的长度为1,说明S是原子节点，直接创建和赋值即可
	{
		s.getChar(1, c);
		L->tag = ATOM;
		L->atom = c;
		return;
	}

	/*如果长度不为1，则说明S是一个表结点， 将S分成表头和表尾两个串*/
	separate(hS, s);
	L->tag = LIST;
	createGList_aux(L->ptr.hp, hS);
	createGList_aux(L->ptr.tp, s);

}

/*复制广义表的辅助函数*/
void GList::copyGList_aux(GListNodePointer& s, GListNodePointer p)
{
	if (!p)
		s = NULL;
	else
	{
		s = new GLNode;
		assert(s != NULL);

		s->tag = p->tag;
		if (p->tag == ATOM)			//如果是原子节点，直接复制即可
			s->atom = p->atom;

		else				//如果是表结点，则需递归将表结点赋值
		{

			/*递归赋值表头部分*/
			copyGList_aux(s->ptr.hp, p->ptr.hp);

			/*递归复制表尾部分*/
			copyGList_aux(s->ptr.tp, p->ptr.tp);
		}
	}

}

/*删除广义表的表头,其实是将表头保存在secondGL中，而原来的root指针则指向表尾*/
Status GList::deleteHead(GList& secondGL)
{
	GListNodePointer p = root;

	if (!root)
		return ERROR;
	root = root->ptr.tp;
	p->ptr.tp = NULL;
	secondGL.setRoot(p);
	return OK;
}

/*求广义表的深度*/
int GList::depth()
{
	return depth_aux(root);
}

/*求广义表深度的辅助函数*/
int GList::depth_aux(GListNodePointer s)
{
	int dep, maxDep = 0;
	if (!s || s->tag == ATOM)
		return 0;

	/*让指针p从带求结点开始，沿着其表尾链表滑动，直到结束*/
	/*求该链表下层结点的最大深度*/
	for (GListNodePointer p = s; p; p = p->ptr.tp)
	{
		dep = depth_aux(p->ptr.hp);
		if (dep > maxDep)
			maxDep = dep;		//更新当前深度的最大值
	}

	return maxDep + 1;
}

/*求广义表的长度*/
int GList::length()
{
	int length = 0;
	if (!root)
		return 0;
	for (GListNodePointer p = root; p; p = p->ptr.tp, ++length);
	return length;

}

/*取广义表的表头*/
Status GList::getHead(GList& headGL)
{
	GListNodePointer p;
	if (!root)
		return ERROR;
	p = root->ptr.hp;
	copyGList_aux(headGL.root, p);

	return OK;
}

/*取广义表的表尾*/
Status GList::getTail(GList& tailGL)
{
	GListNodePointer p;
	if (!root)
		return ERROR;
	p = root->ptr.tp;
	copyGList_aux(tailGL.root, p);

	return OK;
}

/*插入一个广义表作为当前广义表的表头*/
void GList::insertHead(GList& secondGL)
{
	GListNodePointer p = secondGL.root;

	if (secondGL.isEmpty())
		return;
	if (!root)
		root = secondGL.root;
	else
	{
		for (p = secondGL.root; p->ptr.tp; p = p->ptr.tp);
		p->ptr.tp = root;
		/*for (p = secondGL.root; p; p = p->ptr.tp);			//此法错误在于指针p只是一个指向最终表尾的指针，
		p = root; */											//是最终表尾指针的拷贝，修改它的值并不会对原对象造成任何影响
		root = secondGL.root;
	}
	
}

/*重载赋值运算符的定义*/
GList GList::operator = (const GList& rightGL)
{
	/*将原广义表空间释放*/
	destruction_aux(root);

	/*调用拷贝辅助函数，将rightGL拷贝到当前对象*/
	copyGList_aux(root, rightGL.root);
	return *this;

}

/*改变根指针所指向的广义表*/
void GList::setRoot(GListNodePointer p)
{
	/*如果原对象root不为空，则需先将原对象释放，再改变root指向*/
	if (root)
		destruction_aux(root);
	root = p;

}

/*构造函数*/
GList::GList()
{
	root = NULL;

}

/*析构函数*/
GList::~GList()
{
	destruction_aux(root);

}

/*拷贝构造函数*/
GList::GList(const GList& s)
{
	root = NULL;
	copyGList_aux(root, s.root);
}

/*将非空串str分成表头和表尾两部分, hStr存表头， tStr存表尾*/
void separate(SqString& hStr, SqString& tStr)
{

	char c;
	int k = 0, i = 1;			//i预存字符的序号， k存左括号的个数

	int n = tStr.getLength() - 2;		//先去除最外层的括号

	SqString tS;			//临时字符串
	tStr.subString(tS, 2, n);

	while (i <= n)
	{
		tS.getChar(i, c);		//取tS字符串的第i个字符到c

		if (c == ',' && k == 0)		//找到表头部分，退出循环
			break;

		if (c == '(')
			k++;
		else if (c == ')')
			k--;

		i++;
	}

	if (i <= n)
	{
		/*将tS的前i- 1个字符作为表头，第i个字符是','， 从第i + 1个字符起为表尾*/
		tS.subString(hStr, 1, i - 1);
		tS.subString(tStr, i + 1, n - i);
		tStr.insert(1, "(");
		tStr.insert(tStr.getLength() + 1, ")");
	}

	else		//如果while循环没有因为break而退出循环，那么tS这个串只有表头，没有表尾
	{
		hStr = tS;
		tStr = "()";
	}
}

/*求广义表表头加表尾的总长度*/
int GList::getLengthOfTailHead(GList::GListNodePointer GL)
{
	int HLength, TLength;

	if (!GL)			//如果指针为空，返回0
		return 0;

	if (GL->tag == ATOM)		//如果是原子节点，返回1
		return 1;
	else				//GL不为空且不是原子节点，那么一定是表结点
	{
		if (!GL->ptr.hp)			//如果表头为空，则表头长度为1
			HLength = 1;
		else
		HLength = getLengthOfTailHead(GL->ptr.hp);

		TLength = getLengthOfTailHead(GL->ptr.tp);
		return HLength + TLength;
	}
}

/*输入输出广义表的友元函数*/
istream& operator >> (istream& in, GList& item)
{
	cout << "\t义字符串形式输入一个广义表：" << endl;
	SqString S = "((a,b),c,((d)))";
	//in >> S;

	item.createGList(S);

	return in;
}

ostream& operator << (ostream& out, GList& item)
{
	//Q1存本次需打印的结点， Q2存下层结点，Q3也存下层结点，判断是否输出“↓”
	SqQueue<GList::GListNodePointer> Q1(20), Q2(20), Q3(20);
	if (!item.root)
	{
		out << "\t当前广义表为空！" << endl;
		return out;
	}
	GList::GListNodePointer p = item.root, Null = NULL;
	int lowerLength = 0;			//下层广义表的长度
	Q1.enQueue(p);
	//Q3.enQueue(p);
	int dep = item.depth();
	dep = dep * 2 + 1;				//当dep为奇数时打印结点，偶数时打印“↓”
	while (dep)
	{
		cout << "\t";
		if (dep % 2 != 0)
		{
			while (!Q1.IsEmpty())
			{
				Q1.deQueue(p);
				Q3.enQueue(p);

				if (p == Null)
				{
					cout << setw(12) << setfill(' ') << " ";
					Q2.enQueue(Null);
					

				}
				else if (p->tag == ATOM)
				{
					cout << "  (0  " << p->atom << ")    ";
					Q2.enQueue(Null);			//输出的同时要进队列一个Null,方便待会输出空格
				}

				else if (p->tag == LIST)
				{
					while (p)
					{
						if (p->ptr.hp)
						{
							Q2.enQueue(p->ptr.hp);		//如果hp不为空，存入相应指针，否则存入Null，方便待会输出空格
							cout << "(1  ∣ ";
						}

						else
						{
							Q2.enQueue(Null);
							cout << "(1∧∣ ";
						}


						if (p->ptr.tp)		//如果tp不为空
						{
							cout << " -)";
							lowerLength = item.getLengthOfTailHead(p->ptr.hp);
							
							for (int i = 1; i < lowerLength; ++i)
								cout << setw(12) << setfill('-') << "-";
							cout << setw(2) << "→";
							//Q3.enQueue(p->ptr.tp);
							
						}

						else
						{
							cout << "∧)  ";
							//cout << endl;			//如果tp为空，说明应该换行
						}
						p = p->ptr.tp;
						if (p)
							Q3.enQueue(p);
					}

				}
				
			}
			cout << endl;
			dep--;
		}


		else
		{
			
			while (!Q3.IsEmpty())		//输出“↓”
			{
				Q3.deQueue(p);
				if (p == Null)
					cout << setw(12) << setfill(' ') << " ";
				else if (p->tag == ATOM)
				{

					cout << setw(12) << setfill(' ') << " ";
				}
				else if (p->tag == LIST)
				{
					if (p->ptr.hp)
					cout << setw(12) << setfill(' ')  << setiosflags(ios::left) << "    ↓    ";
					else			//如果hp为空，则不能输出↓
						cout << setw(12) << setfill(' ') << setiosflags(ios::left) << "        ";

					if (p->ptr.tp)		//如果tp不为空
					{
						
						lowerLength = item.getLengthOfTailHead(p->ptr.hp);
						
						for (int i = 1; i < lowerLength; ++i)
							cout << setw(12) << setfill(' ') << " ";
						//cout << setw(2) << setfill(' ') << " ";
					}
				//	else
						//cout << endl;			//如果tp为空，说明应该换行
				}
				
			}
			cout << endl;
			dep--;
			Q1 = Q2;
			Q2.clear();
		}

	}



return out;

}



#endif