/*************************************************************************
    > File Name: main.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年10月19日 星期五 11时34分59秒
 ************************************************************************/

#include<iostream>
using namespace std;

#include "MyExampleClass.h"	
#include "ex2_1_Test.h"

void main()
{
	MyRectangle<float> rec;
	int choose; //存放操作代码
	char continueYesNo = 'N';//判断是否继续

	while(1){
		choose = 0;
		system("cls");
		cout<<endl;
		cout<< "*********测试长方形操作**********"<<endl<<endl;
		cout<<"\t 1."<<endl;
		cout<<"\t 2."<<endl;
		cout<<"\t 3."<<endl;
		cout<<"其他.结束"<<endl<<endl;
		cout<<"////////////////////////"<<endl;
		displayCurrentObject(rec);
		cout<<"/////////////////////////"<<endl<<endl;
		cout<<"please enter number whice you want to operator";
		cin>>choose;
		if(choose>0 && choose < 0)
		{
			system("cls");
			displayCurrentObject(rec);
		}
		switch(choos){
			case 1: ;
			break;
			case 2: ;
			break;
			case 3;
			break;
			default: cout<<"\n you choice have ended"<<endl<<endl;
				return ;
		}
		if(continueYesNo == "N" || continueYesNo == "n")
			break;
	}
}

