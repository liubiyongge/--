/*************************************************************************
    > File Name: MyExampleClass.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年10月19日 星期五 11时00分54秒
 ************************************************************************/
//派生类

#include "ExampleClass.h"

#ifndef MYEXAMPLECLASS_H
#define MYEXAMPLECLASS_H

//派生类声明

template <class ElemType>
class MyRectangle: public Rectangle<ElemType>
{
public:
	//********类对象输入输出函数
	//输入长方形
	void read(istream& in);
	//输出长方形
	void display(ostream& out) const;
	//>>
	//istream & operator >>(istream& in, MyRectangle<ElemType>& iD);
	//<<
	//ostream& operator << (ostream& out, const MyRectangle<ElemType>& oD);
};

//////////////////////////////////////////////////////
//派生类实现

//功能：输入长方形
//说明：输入长方形的长和宽
template <class ElemType>
void MyRectangle<ElemType>::read(istream &in)
{
	cout << "请输入第" << this->myNo.no << "个长方形对象" << endl;
	cout << "长方形的长";
	in >> this->length;
	cout << "长方形的宽";
	in >> this->width;
}

//功能：重载输入运算符
template <class ElemType>
istream & operator>>(istream& in, MyRectangle<ElemType>& iD)
{
	iD.read(in);
	return in;
}

template <class ElemType>
void MyRectangle<ElemType>::display(ostream& out) const
{
	out << "第" << this->myNo.no << "个长方形对象(" << this->length << "," << this->width<<")" << endl;
}

template <class ElemType>
ostream& operator << (ostream& out, const MyRectangle<ElemType>& oD)
{
	oD.display(out);
	return out;
}

#endif