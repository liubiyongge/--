/*************************************************************************
    > File Name: class_function.cpp
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: 2018年10月12日 星期五 15时28分09秒
    >function: Sequence table class define
 ************************************************************************/
#ifndef CLASS_FUNCION 
#define CLASS_FUNCION

#include "class_outfunction.h"

template <class ElemType> 
class Sqlist{
	public:
		
		//Binary search method
		int bit_Search(ElemType key);
		//clear sequence table
		void clear();
  		//delete i position data, and return e
		// 1 =< i <= ListLength_Sq(L)
		Status ListDelete_Sq(int i, ElemType &e);
		//get i elem
		Status getElem(int i, ElemType &e);
		//get number of elem
		int getLength();
		//get length of storage
		int getListSize();
		//insert e to data table L before i position 	 1 =< i <= ListLength_Sq(L) + 1
		Status ListInsert_Sq(int i, ElemType e);
		//table is empty or not
		bool isEmpty();	
		//find the fisrt data in linear table equal to e
		// if find ,return i;else return 0
		int LocateElem_Sq(ElemType e,int(* compare)(ElemType, ElemType));
		//return next elem of e
		Status nextElem(ElemType e, ElemType &next_e);
		//assignment operator overriding
		Sqlist<ElemType> operator = (const Sqlist<ElemType> rightL);
		//return prior elem of e
		Status PriorElem(ElemType e, ElemType & prior_e);
//***********************system function******************************************88

		// create function
		Sqlist();

		~Sqlist();

		Sqlist(const Sqlist<ElemType>& otherL);

 		
 	protected:
		//linear table basic address
		ElemType *elem;
		//length of Data tables used
		int length;
		//length of Data table
		int listsize;
};
//Binary search method
//pre:The order is right
template<class ElemType>
int Sqlist<ElemType>::bit_Search(ElemType key)
{
	int low, mid, high;
	//1.find in entire region 
	low = 0;
	high = length;
	//begin
	while(low<=high)
	{
		mid = (low+high)/2;
		if(elem[mid]==key) return mid+1;
		else if(elem[mid]<key) low = mid+1;
		else high = mid - 1;
	}
	return 0;
}

//clear sequence table
template<class ElemType>
void Sqlist<ElemType>::clear()
{
	length = 0;
}

//delete elem

template <class ElemType>
Status Sqlist<ElemType>::ListDelete_Sq(int i, ElemType &e){
	//delete i position data, and return e
	// 1 =< i <= ListLength_Sq(L)
	if(i < 1 || i > this->length) return ERROR; // i is illegal
	ElemType* p = &(this->elem[i - 1]); // p is position of delete data 
	e = *p;
	ElemType* q = this->elem + this->length - 1;//The end of table position
	for(++p; p <= q; ++p) *(p - 1) = *p;
	--this->length;
	return 1;
}

//get i elem
template<class ElemType>
Status Sqlist<ElemType>::getElem(int i, ElemType& e)
{
	if(i < 1 || i > length ) return ERROR;
	e = elem[i - 1];
	return OK;
}

//get number of elem

template<class ElemType>
int Sqlist<ElemType>::getLength()
{
	return length;
}

//get length of storage
template<class ElemType>
int Sqlist<ElemType>::getListSize()
{
	return listsize;
}

//insert e to data table L before i position 	 1 =< i <= ListLength_Sq(L) + 1
template <class ElemType>
Status Sqlist<ElemType>::ListInsert_Sq(int i, ElemType e){
	if(i < 1 || i > this->length  + 1){
		printf("i is illegal.\n");
	 	return ERROR; // i is illegal
	}
	if(this->length >= this->listsize){
		ElemType* newbase = (ElemType *)realloc(this->elem, (this->listsize + LISTINCREMENT) * sizeof(ElemType));//increment table 
		if(!newbase) {
			printf("error memory\n");
			exit(OVREFLOW);
		}
		this->elem = newbase;//new base
		this->listsize += LISTINCREMENT;
	}
	for(int j=length;j>=i;--j)
	{
		elem[j] = elem[j-1];
	}
	elem[i-1] = e;
	++length;
	return OK;
}

//empty or not
template<class ElemType>
bool Sqlist<ElemType>::isEmpty()
{
	return length?0:1;
}

//locate elem
template <class ElemType> 
int Sqlist<ElemType>::LocateElem_Sq(ElemType e,int(* compare)(ElemType, ElemType))
{
	//find the fisrt data in linear table equal to e
	// if find ,return i;else return 0
	int i = 1; //i initail position
	ElemType* p = this->elem;//initail address of data
	while(i <= this->length && !compare(* p++, e)) ++i;
	if(i <= this->length)return i;
	else return 0;
}



//return next elem
template <class ElemType>
Status Sqlist<ElemType>::nextElem(ElemType e, ElemType &next_e)
{
	int i = LocateElem_Sq(e,equal);
	if(i<1 || i==length)
		return ERROR;
	else
		getElem(i+1, next_e);
	return OK;
}

template<class ElemType>
Sqlist<ElemType> Sqlist<ElemType>::operator=(const Sqlist<ElemType>rightL)
{
	if(this != &rightL)
	{
		if(listsize < rightL.listsize)
		{
			delete[] elem;
			elem=new ElemType[rightL.listsize];
			assert(elem!=0);
			listsize = rightL.listsize;
		}
		length = rightL.length;
		for(int i = 1; i <= length; ++i)
			elem[i-1] = rightL.elem[i-1];
	}
	return *this;
}

template<class ElemType>
Status Sqlist<ElemType>::PriorElem(ElemType e, ElemType& prior_e)
{
	int i=LocateElem_Sq(e, equal);

	if(i <= 1)
		return ERROR;
	else
		getElem(i-1, prior_e);
	return OK;
}

//**************************************************8
template <class ElemType>
Sqlist<ElemType>::Sqlist(){
	this->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(! this->elem){ 
		printf("error\n");
		exit(OVREFLOW);
	}
	this->length = 0;
	this->listsize = LIST_INIT_SIZE;
}

template <class ElemType>
Sqlist<ElemType>::~Sqlist()
{
	delete [] elem; 
}

template <class ElemType>
Sqlist<ElemType>::Sqlist(const Sqlist& otherL)
{
	elem = new ElemType[otherL.listsize];
	listsize = otherL.listsize;
	length = otherL.length;

	for(int i=1; i<=length; i++)
		elem[i-1]  = otherL.elem[i-1];

}


#endif
