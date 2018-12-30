#ifndef MYHEAD_H
	#define MYHEAD_H
	#include "myhead.h"
#endif

#include <iostream>
#include <assert.h>
#include <iomanip>
//using namespace std;
using std::cout; using std::cin; using std::endl;
#ifndef SQSTRING_H_INCLUDE
#define SQSTRING_H_INCLUDE

/*顺序串数据结构的定义， 基类, 没有用到模板*/
class SqString
{
public:
	/*把顺序串置空*/
	void clear();

	/*取第i个字符*/
	Status getChar(int i, char& c);

	/*求顺序串的长度*/
	int getLength();

	/*求模式串的next数组*/
	void get_next(int* next, int display = 0);			//为KMP算法做好准备

	/*串的朴素匹配，有回溯查找*/
	int index(SqString& p, int pos);

	/*模式匹配（无回溯的KMP)方法查找*/
	int index_KMP(SqString& p, int pos);

	/*在第i个字符前插入另一个顺序串*/
	Status insert(int i,const SqString& t);

	/*判断顺序串是否为空*/
	bool IsEmpty() const;

	/*重载赋值运算符的定义， SqString顺序串和=C++string字符串*/
	SqString operator = (const char *s);

	/*重载赋值运算符的定义，SqString顺序串=SqString顺序串*/
	SqString  operator = (const SqString& s);

	/*重载加法运算符的定义，SqString顺序串+C++String字符串*/
	SqString operator + (char *s);

	/*重载赋值运算符的定义，SqString顺序串+SqString顺序串*/
	SqString  operator + (SqString& s);

	/*重载是否小于运算符的定义， SqString < SqString*/
	Status operator < (SqString& s);

	/*重载相等运算符的定义， SqString == C++String*/
	int operator == (char* s);

	int operator == (SqString& s);

protected:
	/*把C++字符串赋值给当前顺序串的辅助函数，只允许基类和派生类内部使用，不允许外部调用*/
	void strAssign_aux(const char *s);

public:

	/*删除从第i个字符起长度为len的子串*/
	Status strDelete(int i, int len);

	/*取顺序串从序号为i开始的len个子串，存放在sub中， 返回是否操作成功*/
	Status subString(SqString& sub, int i, int len);

	/*下面是系统自动调用的构造函数及析构函数声明*/
	/*构造函数*/
	SqString();

	/*析构函数*/
	virtual ~SqString();

	/*用C风格字符串拷贝构造一个顺序串*/
	SqString(const char *s);				//char *s中s隐式为const的，所以无需加const

	SqString(const SqString &s);

	/*输入顺序串*/
	void read(std::istream& in);

	/*输出顺序串*/
	void display(std::ostream& out);


protected:
	int length;			//存放顺序串的长度
	char *ch;			//顺序串动态存储空间的首地址
};

/*把顺序串置空*/
void SqString::clear()
{
	if (ch)
	{
		delete[] ch;
		ch = NULL;
		length = 0;
	}
}

/*取第i个字符*/
Status SqString::getChar(int i, char& c)
{
	if (i < 1 || i > length)
		return ERROR;
	else
		c = ch[i - 1];
	return OK;
}

/*求顺序串的长度*/
int SqString::getLength()
{
	return length;
}

/*求模式串的next数组*/
void SqString::get_next(int* next, int display)			//为KMP算法做好准备
{
	int j = -1, i = 0;
	int first_i;			//当前组第一个元素的下标
	char no[7] = "[  i ]";

	next[0] = -1;		///-1为终止值
	while (i < length)
	{
		if (j == -1 || ch[j] == ch[i])
		{
			++i;
			++j;
			if (ch[i] != ch[j])
				next[i] = j;
			else
				next[i] = next[j];

		}
		else
			j = next[j];
	}

	if (display == 1)
	{
		cout << "\t当前模式串的next[]数组为：" << endl;
		first_i = 0;
		while (first_i < length)
		{
			i = first_i;
			cout << "\t";
			do
			{
				/*修正元素下标的字符表示*/
				if (i < 10)
					no[3] = i + '0';
				else
				{
					no[2] = i / 10 + '0';
					no[3] = i % 10 + '0';
				}
				cout.width(7);
				cout.fill(' ');
				std::setiosflags(std::ios::right);
				cout << no;
				++i;
			} while (i % 10 && i < length);
			cout << endl;

			/*显示模式串中的字符*/
			cout << "\t";
			i = first_i;
			do
			{
				cout.width(7);
				cout.fill(' ');
				//cout.setf(ios::right, ios::adjustfield);
				std::setiosflags(std::ios::right);
				cout << ch[i];
				++i;
			} while (i % 10 && i < length);
			cout << endl;

			/*显示next[]数组中的元素值*/
			cout << "\t";
			i = first_i;
			do
			{
				cout.width(7);
				cout.fill(' ');
				std::setiosflags(std::ios::right);
				cout << next[i];
				++i;
			} while (i % 10 && i < length);

			first_i = i;
			cout << endl << endl;
		}
	}
}

/*串的朴素匹配，有回溯查找,从主串的第pos个字符开始查找*/
int SqString::index(SqString& p, int pos)
{
	int j = 0, i = pos -1;
	while ((i < length - p.length + 1) && j < p.length)
	{
		if (ch[i] == p.ch[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;			//i回到初始位置加一
			j = 0;
		}
	}

	if (j == p.length)
		return i - j + 1;
	else
		return 0;
}

/*模式匹配（无回溯的KMP)方法查找*/
int SqString::index_KMP(SqString& p, int pos)
{
	int i = pos - 1;
	int j = -1;

	int *next;
	next = new int[p.length];
	assert(next != 0);

	p.get_next(next, 0);

	while (i < length && j < p.length)
	{
		if (j == -1 || ch[i] == p.ch[j])
		{
			++j;
			++i;
		}
		else
			j = next[j];
	}
	if (j == p.length)
		return i - p.length + 1;		//返回起始位置的下标
	else
		return 0;
}

/*在第i个字符前插入另一个顺序串*/
Status SqString::insert(int i, const SqString& t)
{
	char* temp;
	if (i < 1 || i > length + 1 || t.IsEmpty())
		return ERROR;
	temp = new char[length + t.length];
	 
	int j = 0;
	for (j = 0; j < i- 1; ++j)				//在第i个字符之前就是在下下标为i - 1的字符之前
		temp[j] = ch[j];
	for (; j < t.length + i - 1; ++j)
		temp[j] = t.ch[j - i + 1];
	for (; j < t.length + length; ++j)
		temp[j] = ch[j - t.length];

	delete[] ch;
	length = j;
	ch = new char[length];
	
	for (j = 0; j < length; j++)
		ch[j] = temp[j];
	return OK;
}

/*判断顺序串是否为空*/
bool SqString::IsEmpty() const
{

	return length == 0;
}

/*重载赋值运算符的定义， SqString顺序串和=C++string字符串*/
SqString SqString::operator = (const char *s)
{

	strAssign_aux(s);
	return *this;
}

/*重载赋值运算符的定义，SqString顺序串=SqString顺序串*/
SqString  SqString::operator = (const SqString& s)
{
	if (this != &s)
	{
		clear();
		ch = new char[s.length];
		for (int i = 0; i < s.length; i++)
			ch[i] = s.ch[i];
		length = s.length;
		
	}
	return *this;

}

/*重载加法运算符的定义，SqString顺序串+C++String字符串*/
SqString SqString::operator + (char *s)
{
	insert(length + 1, s);
	return *this;
}

/*重载赋值运算符的定义，SqString顺序串+SqString顺序串*/
SqString  SqString::operator + (SqString& s)
{
	insert(length + 1, s);
	return *this;
}

/*重载是否小于运算符的定义， SqString < SqString*/
Status SqString::operator < (SqString& s)
{
	int i = 0;
	for (i = 0; i < length && i < s.length; ++i)
	if (ch[i] < s.ch[i])
		return true;
	if (i < s.length)		//i < s.length代表s串更长
		return true;
	else
		return false;

}

/*重载相等运算符的定义， SqString == C++String*/
int SqString::operator == (char* s)
{
	int i = 0;
	int s_length;
	for (i = 0;s[i] != '\0'; ++i);
	s_length = i;

	for (int i = 0; i < length && i < s_length; ++i)
	if (ch[i] != s[i])
		return ch[i] - s[i];

	return length - s_length;
}

int SqString::operator == (SqString& s)
{
	for (int i = 0; i < length && i < s.length; ++i)
	if (ch[i] != s.ch[i])
		return ch[i] - s.ch[i];
	return length - s.length;



}

	/*把C++字符串赋值给当前顺序串的辅助函数，只允许基类和派生类内部使用，不允许外部调用*/
void SqString::strAssign_aux(const char *s)
{
	clear();

	int i = 0;
	/*因为要根据s的长度来给ch分配空间，所以必须先求得s的长度*/
	for (i = 0; s[i] != '\0'; ++i);
	length = i;

	ch = new char[length];
	for (i = 0; i < length; i++)
		ch[i] = s[i];

}

	/*删除从第i个字符起长度为len的子串*/
Status SqString::strDelete(int i, int len)
{
	char *temp = new char[length - len];
	
	int j = 0;
	for (j = 0; j < i - 1; ++j)
		temp[j] = ch[j];
	for (;j < length - len; ++j)
		temp[j] = ch[j + len];

	delete[] ch;
	ch = new char[length - len];		//将ch原空间释放之后，需要重新分配空间

	for (j = 0; j < length - len; j++)
		ch[j] = temp[j];
	length -= len;
	return OK;
}

	/*取顺序串从序号为i开始的len个子串，存放在sub中， 返回是否操作成功*/
Status SqString::subString(SqString& sub, int i, int len)
{
	if (i < 1 || len < 0 || len > length - i + 1)
		return ERROR;

	sub.clear();
	sub.ch = new char[len];
	for (int j = i - 1; j < len + i - 1; ++j)
		sub.ch[j - i + 1] = ch[j];

	sub.length = len;
	return OK;
}

	/*下面是系统自动调用的构造函数及析构函数声明*/
	/*构造函数*/
SqString::SqString()
{
	ch = NULL;
	length = 0;

}

	/*析构函数*/
SqString::~SqString()
{
	clear();

}

	/*用C风格字符串拷贝构造一个顺序串*/
SqString::SqString(const char *s)				//char *s中s隐式为const的，所以无需加const
{
	ch = NULL;
	int j = 0;
	for (j = 0; s[j] != '\0'; ++j);
	length = j;
	ch = new char[length];
	assert(ch != NULL);
	for (j = 0; j < length; j++)
		ch[j] = s[j];
}

SqString::SqString(const SqString &s)
{
	ch = new char[s.length];
	assert(ch != NULL);

	length = s.length;
	for (int i = 0; i < length; i++)
		ch[i] = s.ch[i];
}

	/*输入顺序串*/
void SqString::read(std::istream& in)
{
	char s[50];
	in >> s;
	strAssign_aux(s);

}

	/*输出顺序串*/
void SqString::display(std::ostream& out)
{

	for (int i = 0; i < length; i++)
		out << ch[i];
}


std::istream& operator >> (std::istream& in, SqString& S)
{
	S.read(in);
	return in;
}

std::ostream& operator >> (std::ostream& out, SqString& S)
{
	S.display(out);
	return out;
}
#endif