/////////////////////////
//ExampleClass.h 长方形数据结构C++类定义
/////////////////////////////////////////
#ifndef EXAMPLECLASS_H
#define EXAMPLECLASS_H

template <class Elemtype>
class Rectangle
{
public :
	class RectangleNo {
	public:
		int no;//存放长方形的序号
	};

	//*****************系统自动调用的构造函数及折构函数声明******************
	//长方形构造函数
	Rectangle();

	//长方形拷贝初始化函数
	Rectangle(const Rectangle<Elemtype>& otherD);

	//长方形折构函数
	~Rectangle();

	//refine =
	Rectangle operator =(Rectangle rightR);

	//set length
	void setLength(Elemtype l);

	//set width
	void setWidth(Elemtype w);

	//set NO
	void setNo(int i);

protected:
	Elemtype length;
	Elemtype width;
	RectangleNo myNo;
};
/////////////////////////////////////////////////
//长方形数据结构C++类实现（基类）

//功能：长方形构造函数
//说明：初始化为一个空对象
template <class Elemtype>
Rectangle<Elemtype>::Rectangle() {
	length = width = 0;
	cout << "自动调用构造函数" << endl;
}

//功能：长方形拷贝初始化函数
//输入：函数的参数otherD用于拷贝初始化长方形
template<class Elemtype>
Rectangle<Elemtype>::Rectangle(const Rectangle<Elemtype>& otherD)
{
	length = otherD.length;
	width  = otherD.width;
	myNo   = otherD.myNo;
	cout << "自动调用拷贝初始化构造函数初始为（" << length << "," << width << ")" << endl;
}

//功能：长方形折构函数
template<class Elemtype>
Rectangle<Elemtype>::~Rectangle() {
	cout << "第" << myNo.no << "个长方形对象(" << length << "," << width << ")生命周期结束" << endl;
}

//function:refine =
template<class Elemtype>
Rectangle<Elemtype> Rectangle<Elemtype>::operator= (Rectangle<Elemtype> rightR) {
	if (this != &rightR) {
		length  = rightR.length;
		width = rightR.width;
		myNo = rightR.myNo;
		cout << " new Rectangle(" << length << "," << width << ")" << endl;
	}
	return *this;
}

//fuction:set length
template<class Elemtype>
void Rectangle<Elemtype>::setLength(Elemtype l) {
	length = l;
}

//fuction:set width
template<class Elemtype>
void Rectangle<Elemtype>::setWidth(Elemtype w) {
	width = w;
}

template<class Elemtype>

//fuction:set No
void Rectangle<Elemtype>::setNo(int i) {
	myNo.no = i;
}

#endif