/*************************************************************************
    > File Name: MyTerm.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月07日 星期三 21时17分02秒
 	> function:poly 
 ************************************************************************/

#ifndef _MYTERM_H
#define _MYTERM_H

class MyTerm
{
public:
	void read(istream &in);
	void display(ostream &out);
public:
	float coef;//coefficient
	int expn;//exponential
};
///////////////////////////////////////////

//function:input poly
void MyTerm::read(istream &in)
{
	cout<<"coefficient:";
	while(!(in>>coef))
		cout << "0 is not a reasonable coefficient, input again!"<<endl;
	cout<<"\t exponential:";
	in >> expn;
	cout<<endl;
}

istream & operator >>(istream &in, MyTerm& s)
{
	s.read(in);
	return in;
}

//function:output
void MyTerm::display(ostream &out)
{
	if(coef !=  1)
		out<<coef;
	if(expn)
		out<<"x"<<expn;
}

ostream &operator <<(ostream &out, MyTerm &s)
{
	s.display(out);
	return out;
}
#endif
