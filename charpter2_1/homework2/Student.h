/*************************************************************************
    > File Name: Student.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年11月15日 星期四 18时30分48秒
 ************************************************************************/

#ifndef _STUDENT_H
#define _STUDENT_H
class Student
{
public:
	void setstu(int number, char* name, int Chinese, int English, int math);
	void inputStudent();

	Student operator = (const Student &L);
	//***********************************888
	Student();
	Student(const Student &L);
public:
	int number;
	char *name;
	int Chinese;
	int English;
	int math;
	float average;
	int sum;

};


void Student::setstu(int number1, char* name1, int Chinese1, int English1, int math1)
{
	number = number1;
	
	//name = (char *)malloc(sizeof(char)*13);
	name = name1;
	Chinese = Chinese1;
	English = English1;
	math = math1;
	sum = math+Chinese+English;
	average = (sum)/3.0;
}

void Student::inputStudent()
{
	cout << "Student number:";
	cin >> number; 
	cout << "student name:";
	name = (char *)malloc(sizeof(char)*13);
	cin >> name;
	cout << "Chinese scores:";
	cin >> Chinese;
	cout << "English scores:";
	cin >> English;
	cout << "math scores:";
	cin >> math;
	sum = math+Chinese+English;
	average = (sum)/3.0;
}

Student Student::operator = (const Student &L)
{
	number = L.number;
	name   = L.name;
	Chinese = L.Chinese;
	English = L.English;
	math = L.math;
	average = L.average;
	sum = L.sum;
}

//*************************************88
Student::Student()
{
	number = 0;
	name = NULL;
	Chinese = 0;
	English = 0;
	math = 0;
	average = 0;
	sum = 0;
}

Student::Student(const Student &L)
{
	number = L.number;
	name   = L.name;
	Chinese = L.Chinese;
	English = L.English;
	math = L.math;
	average = L.average;
	sum = L.sum;
}


#endif
