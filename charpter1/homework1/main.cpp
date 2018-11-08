/*************************************************************************
    > File Name: main.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月02日 星期五 11时36分46秒
 ************************************************************************/

#include "../header.h"
#include "../MyExampleClass.h"
#include "ex2_1_Test.h"

int main()
{
	MyRectangle<float> rec;
	int choose; //存放操作代码
	char continueYesNo = 'N';//判断是否继续

	while(1){
		choose = 0;
		system("cls");
		cout<<endl;
		cout<< "*********测试长方形操作**********"<<endl<<endl;
		cout<<"\t 1. set No"<<endl;
		cout<<"\t 2.set length"<<endl;
		cout<<"\t 3.test ="<<endl;
		cout<<"其他.结束"<<endl<<endl;
		cout<<"////////////////////////"<<endl;
		displayCurrentObject(rec);
		cout<<"/////////////////////////"<<endl<<endl;
		cout<<"please enter number(1-3)whice you want to operator:";
		cin>>choose;
		if(choose>0 && choose < 3)
		{
			system("cls");
			displayCurrentObject(rec);
		}
		switch(choose){
			case 1: ex2_1_1(rec, continueYesNo);
			break;
			case 2: ex2_1_2(rec, continueYesNo);
			break;
			case 3: ex2_1_3(rec, continueYesNo);
			break;
			default: cout<<"\n you choice have ended"<<endl<<endl;
				return 0;
		}
		if(continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}
	return 0;
}
