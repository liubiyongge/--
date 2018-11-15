/*************************************************************************
    > File Name: test_Student.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月12日 星期一 22时21分58秒
 ************************************************************************/

#ifndef _TEST_STUDENT_H
#define _TEST_STUDENT_H

template<typename ElemType>
void ex3_2_1(Sqlist<ElemType> &stu)
{
	cout << "**********Insert new student before i th student*************\n";
	int i;
	ElemType e;
	cout<<"请你输入要在第几个元素前插入元素:";
	cin >> i;
	cout << "Please enter student's information:" <<endl;
	e.inputStudent();
	cout << e.name;
	cout << "你要在第" << i << " 个学生前插入新学生 " << endl ;
	showAS(e);
	stu.ListInsert_Sq(i, e);
	cout << "插入后的顺序表为:"<< endl;
	showS(stu);
	cout << "**********************************" << endl;
}


template<typename ElemType>
void ex3_2_2(Sqlist<ElemType> &stu)
{	
	cout << "********** 判断学生表是否为空*************\n";
	if(stu.isEmpty())
		cout << "学生表为空" << endl;
	else
		cout << "学生表不为空" <<endl;
	cout << "**********************************" << endl;
}

template<typename ElemType>
void ex3_2_3(Sqlist<ElemType> &stu)
{	
	cout << "****求学生表中学生的人数****" << endl;
	cout << "学生表中有" << stu.getLength() << "人" << endl;
	cout << "**********************************" << endl;
	
}
template<typename ElemType>
void ex3_2_4(Sqlist<ElemType> &stu)
{
	int i;
	ElemType e;
	cout << "***返回学生表中第i个学生*****" << endl;
	cout << "你要获取的学生序号(1-" << stu.getLength() << "):";
	cin >> i;
	cout << "你要获取的第" << i << "个学生信息为:" << endl;
	stu.getElem(i, e);
	showAS(e);
	cout << "**********************************" << endl;
	
}

template<typename ElemType>
void ex3_2_5(Sqlist<ElemType> &stu)
{
	int i;
	cout << "*****返回某姓名学生的前驱***" << endl;
	cout << "请输入你想要查找其前驱学生的姓名:";
	ElemType e;
	char *p;
	p = (char *)malloc(sizeof(char)*13);
	cin >> p;
	for( i = 1;i <= stu.getLength(); i++)
	{	
		stu.getElem(i, e);
		if(strlen(p) != strlen(e.name))
			continue;
		if(!strcmp(e.name, p))
			break;
	}

	if(i == 1 || i > stu.getLength())
		cout << "没有找到前驱" << endl;
	else
	{		
		cout << "你想要查找姓名为" << p << "的学生的前驱为：" << endl;
		stu.getElem(i-1, e);
		showAS(e);
	}
	cout << "**********************************" << endl;
}


template<typename ElemType>
void ex3_2_6(Sqlist<ElemType> &stu)
{
	int i;
	cout << "********" << endl;
	cout << "请输入你想要查找其后继学生的姓名:";
	ElemType e;
	char *p;
	p = (char *)malloc(sizeof(char)*13);
	cin >> p;
	for( i = 1;i <= stu.getLength(); i++)
	{
		stu.getElem(i, e);
		if(strlen(p) != strlen(e.name))//avoid outflow
			continue;
		if(!strcmp(e.name, p))
			break;
	}

	if(i >= stu.getLength())
		cout << "没有找到后继" << endl;
	else
	{		
		cout << "你想要查找姓名为" << p << "的学生的后继为：";
		stu.getElem(i+1, e);
		showAS(e);
	}
	
	
	cout << "**********************************" << endl;
}


template<typename ElemType>
void ex3_2_7(Sqlist<ElemType> &stu)
{
	cout << "****删除学生表中第i个学生****" << endl;
	int i;
	ElemType e;
	cout << "请你输入要删除学生序号(1 -" << stu.getLength() << "):";
	cin >> i;
	stu.ListDelete_Sq(i, e);
	cout << "你要删除的第" << i << "学生的信息为:" <<endl;
	showAS(e);
	cout << "删除后的顺序表为:"<< endl;
	showS(stu);
	cout << "**********************************" << endl;
}


template<typename ElemType>
void ex3_2_8(Sqlist<ElemType> &stu)
{
	cout << "****把一个学生表赋值给另一个学生表****" << endl;
	Sqlist<Student> stu1;
	Student student1, student2;
	char *p = "liu";
	student1.setstu(5, p, 88, 8, 88);
	p = "liubi";
	student2.setstu(6, p, 77, 77, 77);
	stu1.ListInsert_Sq(1, student1);
	stu1.ListInsert_Sq(2, student2);
	stu = stu1;
	cout << "把另外一个学生表赋值给当前学生表为:" << endl;
	showS(stu);
	cout << "**********************************" << endl;
}

template<typename ElemType>
void ex3_2_9(Sqlist<ElemType> &stu)
{
	cout << "****设置学生表为空表****" << endl;
	stu.clear();
	cout << "当前学生表为空后，学生人数为：" << stu.getLength() << endl;
	cout << "**********************************" << endl;
}


template<typename ElemType>
void ex3_2_10(Sqlist<ElemType> &stu)
{

	cout << "*****随机生成学生表***" << endl;
	//499个   0-498，百家姓
  	char NameHead[5][4] = {"赵","钱","孙","李","刘"};
  	//322个，词语
  	char Name2[4][7]= {"骄奢","荫庇","芳馨", "必勇"};
	stu.clear();
	int i;
	i = rand()%20 + 1;
	Student * p;
	char *q;
	
	
	
	for(int j = 1; j <= i; j++)
	{
		p = new Student;// 
		q = (char *)malloc(sizeof(char)*13);
		strcpy(q,NameHead[rand()%4]);
		strcat(q, Name2[rand()%3]);
		p->setstu(rand()%100 + 1, q, rand()%100, rand()%100, rand()%100);
		stu.ListInsert_Sq( 1, *p);
	}
	showS(stu);
	cout << "**********************************" << endl;
}


template<typename ElemType>
void ex3_2_11(Sqlist<ElemType> &stu)
{
	cout << "****用已经有的学生表初始话另一个学生表****" << endl;
	Sqlist<Student> stu1(stu);
	showS(stu1);
	cout << "**********************************" << endl;
}

template<typename ElemType>
void ex3_2_12(Sqlist<ElemType> &stu)
{
	cout << "****输入学生表****" << endl;
	int n;
	Student *p;
	stu.clear();
	cout << "请输入顺序表元素个数:";
	cin >> n;
	for(int i=1; i<=n; i++ )
	{
		p = new Student;
		cout << "请输入第" << i << "个元素数值:"<< endl;
		(*p).inputStudent();
		stu.ListInsert_Sq(i, *p);
	}
	cout << "输入后学生表为:"<<endl;
	showS(stu);
	cout << "**********************************" << endl;
}
	

#endif
