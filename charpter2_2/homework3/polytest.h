/*************************************************************************
    > File Name: polytest.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月16日 星期五 11时43分48秒
 ************************************************************************/

#ifndef _POLYTEST_H
#define _POLYTEST_H

template <typename ElemType>
void ex3_2_1(MyPolynomialLinklist<ElemType> &P)
{
	cout << "****判断多项式是否为空*****" << endl;
	if(P.isEmpty())
		cout << "多项式为空" << endl;
	else
		cout << "多项式不为空" << endl;
	cout << "**************************" << endl;
}

template <typename ElemType>
void ex3_2_2(MyPolynomialLinklist<ElemType> &P)
{
	cout << "***把一个多项式赋值给另一个多项式******" << endl;
	MyPolynomialLinklist<MyTerm> P1;
	P1.randomInitalFill();
	cout << "另一个多项式赋值给当前多项式为:" << endl;
	P = P1;
	cout << P;
	cout << "**************************" << endl;
}


template <typename ElemType>
void ex3_2_3(MyPolynomialLinklist<ElemType> &P)
{
	cout << "****俩个多项式的加法*****" << endl;
	cout << "另一个多项式为:" << endl;
	MyPolynomialLinklist<MyTerm> P1;
	P1.randomInitalFill();
	cout << P1 << endl;
	cout << "以上两个多项式相加和为:" << endl;
	cout << P1 + P << endl; 
	cout << "**************************" << endl;
}


template <typename ElemType>
void ex3_2_4(MyPolynomialLinklist<ElemType> &P)
{
	cout << "*****两个多项式的减法****" << endl;
	cout << "另一个多项式为:" << endl;
	MyPolynomialLinklist<MyTerm> P1;
	P1.randomInitalFill();
	cout << P1 << endl;
	cout << "以上两个多项式相减为:" << endl;
	cout << P1 - P << endl; 
	cout << "**************************" << endl;
}


template <typename ElemType>
void ex3_2_5(MyPolynomialLinklist<ElemType> &P)
{
	cout << "*****设置多项式为空多项式****" << endl;
	P.clear();
	cout << "当前多项式共" << P.getLength() << "项" << endl;
	cout << "**************************" << endl;
}


template <typename ElemType>
void ex3_2_6(MyPolynomialLinklist<ElemType> &P)
{
	cout << "*****随机生成多项式****" << endl;
	P.clear();
	P.randomInitalFill();
	cout << "随机生成多项式为:" << endl;
	cout << P;
	cout << "**************************" << endl;
}

template <typename ElemType>
void ex3_2_7(MyPolynomialLinklist<ElemType> &P)
{
	cout << "*****用已有的多项式初始化另一个多项式****" << endl;
	MyPolynomialLinklist<MyTerm> P1(P);
	cout << "当前多项式初始化另一个多项式为:" << endl;
	cout << P1 << endl;
	cout << "**************************" << endl;
}


template <typename ElemType>
void ex3_2_8(MyPolynomialLinklist<ElemType> &P)
{
	cout << "****输入多项式*****" << endl;
	cin >> P;
	cout << "输入多项式为:" << endl;
	cout << P;
	cout << "**************************" << endl;
}
#endif
