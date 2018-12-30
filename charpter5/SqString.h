/*************************************************************************
    > File Name: SqString.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Thu 29 Nov 2018 09:39:10 PM CST
 ************************************************************************/

#ifndef _SQSTRING_H
#define _SQSTRING_H
///////////////////////////////////////////
////顺序字符串Ｃ＋＋类定义 
//内部0--->length-1
//表现是1-->length
///////////////////////


class SqString
{
public:
	////tmp///
	void show();
	void clear();
	Status getChar(int i, char &c);
	int getLength();
	void get_next(int* next);
	int index_KMP(SqString p, int pos);
	bool isEmpty();
	Status insert(int i, SqString t);

	Status strDelete(int i, int len);
	Status subString(SqString &sub ,int i, int len);
	//运算重载
	SqString operator = (char *s);
	SqString operator = (SqString otherL);
	SqString operator + (char *s);
	SqString operator + (SqString otherL);
	Status operator < (SqString otherL);
	int operator == (char *s);
	int operator == (SqString s);
	////////////自动调用函数
	SqString();
	SqString(char *s);
	~SqString();
	SqString(const SqString& otherL);
protected:
	void strAssign_aux(char *s);

protected:
	int length;
	char *ch;
};
void SqString::show()
{
	for(int i = 0; i < length; i++)
		cout << ch[i];
	cout << endl;
}

void SqString::clear()
{
	if(length != 0)
	{
		delete []ch;
		length = 0;
	}
}

Status SqString::getChar(int i, char &c)
{
	if(i < 1 || i > length)
		return ERROR;
	c = ch[i-1];
	return OK;
}

int SqString::getLength()
{
	return length;
}

void SqString::get_next(int * next)
{
	int j = -1, i=0;
	//char no[5]
	next[0] = -1;
	while(i<length)
	{
		if(j==-1 || ch[j] == ch[i])
		{
			++j;
			++i;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

int SqString::index_KMP(SqString p, int pos)
{
	int i = pos-1;
	int j = -1;
	int *next;
	next = new int[p.length];
	assert(next != 0);
	p.get_next(next);
	while(i<length && j < p.length)
	{
		if(j==-1 || ch[i] == p.ch[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if(j==p.length)
		return i-p.length+1;
	else
		return 0;
}


bool SqString::isEmpty()
{
	return length?0:1;
}


Status SqString::insert(int i, SqString t)
{
	if(i <= 0 || i > length+1 || t.isEmpty())
		return ERROR;
	char *ch1 = (char *)malloc(sizeof(char)*(length+t.length));
	assert(ch1 != NULL);
	length = length+t.length;
	int j = 0;// ch1
	int m = 0;//ch
	int n = 0;//t.ch
	for(;j < i-1; j++, m++)
		ch1[j] = ch[m];
	
	for(;n < t.length;n++,j++)
		ch1[j] = t.ch[n];

	for(; j < length; j++, m++)
		ch1[j] = ch[m];

	char *tmp = ch;
	ch = ch1;
	delete tmp; 
	return OK;
	

}


Status SqString::strDelete(int i, int len)
{
	if(i < 1 && i+len-1 > length)
		return ERROR;
	
	for(int j = i+len-1, k = i-1; j < length; j++, k++)
		ch[k] = ch[j];
	length = length -len;
	ch = (char *)realloc(ch, sizeof(char)*(length));
	return OK;
}

Status  SqString::subString(SqString &sub,int i, int len)
{
	if(i < 1 && i+len-1 > length)
		return ERROR;
	sub.ch =(char *)malloc((len)*sizeof(char));
	sub.length = len;
	for(int j=i-1, m=0; m < len; j++, m++)
		sub.ch[m] = ch[j];
	return OK;
}
//////////////////////////运算重载
SqString SqString::operator = (char *s)
{
	strAssign_aux(s);	
}

SqString SqString::operator = (SqString otherL)
{
	clear();
	if(this != &otherL)
	{
		length = otherL.length;
		ch = new char[length];
		assert(ch != 0);
		for(int i=0; i < length; i++)
			ch[i] = otherL.ch[i];
	}
	return *this;
}

SqString SqString::operator + (char *s)
{
	int i;
	for(i=0;s[i];i++);
	ch = (char *)realloc(ch, sizeof(char)*(length+i));
	assert(ch != NULL);
	for(int j=length, m=0; j < length+i; j++, m++)
		ch[j] = s[m];
	length = length+i;
	return *this;
}

SqString SqString::operator + (SqString otherL)
{
	ch = (char *)realloc(ch, sizeof(char)*(length+otherL.length));
	assert(ch != NULL);
	for(int j=length, m=0; j < length+otherL.length; j++, m++)
		ch[j] = otherL.ch[m];
	length = length + otherL.length;
	return *this;
}

Status SqString::operator < (SqString otherL)
{
	int i = 0;
	while(i < length && i < otherL.length)
	{
		if(ch[i] < otherL.ch[i])
			return TRUE;
		if(ch[i] > otherL.ch[i])
			return FALSE;
		i++;
	}
	if(i < otherL.length)
		return TRUE;
	else
		return FALSE;
}

//if equal  return 0
int SqString::operator == (char *s)
{
	int s_length, i;
	for(i=0; s[i];++i);
	s_length = i;
	for(i=0;i < length && i <s_length; ++i)
		if(ch[i] != s[i])
			return ch[i] - s[i];
	return length - s_length;
}

int SqString::operator == (SqString s)
{
	for(int i=0;i < length && i < s.length; i++)
		if(ch[i] != s.ch[i])
			return ch[i] - s.ch[i];
	return length - s.length;
}
///////protected function
void SqString::strAssign_aux(char *s)
{
	clear();
	int i;
	for(i=0;s[i];i++);
	length = i;
	ch = new char[length];
	for(i = 0; i < length; ++i)
		ch[i] = s[i];
}

////////////

////////////自动调用函数
SqString::SqString(char *s)
{
	length = 0;
	ch = NULL;
	strAssign_aux(s);
}

SqString::SqString()
{
	length = 0;
	ch = NULL;
}

SqString::~SqString()
{
	delete ch;
	ch = NULL;
}

SqString::SqString(const SqString& otherL)
{
	length = otherL.length;
	ch = new char[length];
	assert(ch != 0);
	for(int i=0; i < length; i++)
		ch[i] = otherL.ch[i];
}
#endif
