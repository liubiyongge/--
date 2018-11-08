/*************************************************************************
    > File Name: ex2_1_Test.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月02日 星期五 11时19分13秒
 ************************************************************************/

#ifndef _EX2_1_TEST_H
#define _EX2_1_TEST_H

//show rectangle
template<typename ElemType>
void displayCurrentObject(MyRectangle<ElemType> rec)
{
	cout<< endl;
	cout<<rec<<endl;
}

//set No
template<typename ElemType>
void ex2_1_1(MyRectangle<ElemType> &rec, char &continueYesNo)
{
	int no;
	cout<<"***********$set No of rectangle$**************"<<endl<<endl;
	cout<<"please enter No:";
	cin >> no;
	rec.setNo(no);
	cout << rec;
	cout <<  "********************************************"<<endl<<endl;
	cout<<"continue?(Y.continue\tN.end)";
	cin>>continueYesNo;
}

//set length
template<typename ElemType>
void ex2_1_2(MyRectangle<ElemType>&rec, char& continueYesNo)
{
	int aL;
	cout<<"***********$set length of rectangle$**************"<<endl<<endl;
	cout<<"please enter length:";
	cin >> aL;
	rec.setLength(aL);
	cout << rec;
	cout <<  "********************************************"<<endl<<endl;
	cout<<"continue?(Y.continue\tN.end)";
	cin>>continueYesNo;
}

//test =
template <typename ElemType>
void ex2_1_3(MyRectangle<ElemType>  rec, char& continueYesNo)
{
	MyRectangle<float> recOther;
	cout<<"***********$==========$**************"<<endl<<endl;
	cout<<"Assign the current rectangle object to other"<<endl;
	recOther = rec;
	cout<<"\n show other rectangle:"<<endl;
	cout<<recOther;
	cout <<  "********************************************"<<endl<<endl;
	cout<<"continue?(Y.continue\tN.end)";
	cin>>continueYesNo;
}

#endif
