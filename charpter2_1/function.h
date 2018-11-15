/*************************************************************************
    > File Name: function.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年10月31日 星期三 18时21分16秒
 ************************************************************************/

#ifndef _FUNCTION_H
#define _FUNCTION_H


template<class ElemType> 
void show(Sqlist<ElemType>& L);
//show elem 
template<class ElemType>
void show(Sqlist<ElemType>& L)
{	
	ElemType e = 0;
	for(int i = 1;i <= L.getLength();i++)
		cout << "[ " << i << " ]" << " ";
	cout << endl;
	for(int i = 1;i <= L.getLength();i++)
	{
		L.getElem(i, e);
		cout.setf(ios::left);
		cout << ' ';
		cout << setw(5) << e; 
	}
	cout << endl;
}

//******************student class**********88

template<typename ElemType>
void showS(Sqlist<ElemType>& L)
{
	ElemType e;
	cout << setw(8) << "Number";	
	cout << setw(8) << "Name";
	cout << setw(8) << "Chinese";
	cout << setw(8) << "English";
	cout << setw(8) << "Math";
	cout << setw(8) << "Average";
	cout << setw(8) << "Sum";
	cout << endl;

	for(int i = 1;i <= L.getLength();i++)
	{
		L.getElem(i, e);
		cout.setf(ios::left);
		cout << ' ';
		cout << setw(7) << e.number; 
		cout << ' ';
		cout << setw(7) << e.name;
		cout << ' ';
		cout << setw(7) << e.Chinese;
		cout << ' ';
		cout << setw(7) << e.English;
		cout << ' ';
		cout << setw(7) << e.math;
		cout << ' ';
		cout << setw(7) << e.average;
		cout << ' ';
		cout << setw(7) << e.sum;
		cout << endl;
	}
	
}

void showAS(Student e)
{
	cout << setw(8) << "Number";	
	cout << setw(8) << "Name";
	cout << setw(8) << "Chinese";
	cout << setw(8) << "English";
	cout << setw(8) << "Math";
	cout << setw(8) << "Average";
	cout << setw(8) << "Sum";
	cout << endl;
	cout.setf(ios::left);
	cout << ' ';
	cout << setw(7) << e.number; 
	cout << ' ';
	cout << setw(7) << e.name;
	cout << ' ';
	cout << setw(7) << e.Chinese;
	cout << ' ';
	cout << setw(7) << e.English;
	cout << ' ';
	cout << setw(7) << e.math;
	cout << ' ';
	cout << setw(7) << e.average;
	cout << ' ';
	cout << setw(7) << e.sum;
	cout << endl;
}	
#endif
 