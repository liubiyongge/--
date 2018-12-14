/*************************************************************************
    > File Name: SMatrix.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Mon 03 Dec 2018 07:30:17 PM CST
 ************************************************************************/

#ifndef _SMATRIX_H
#define _SMATRIX_H
template <typename T>
class SMatrix
{
private:
	class Triple
	{
	public:
		int i;
		int j;
		T e;		
	};
public:
	void clear();
	bool isEmpty();
////	//////////////////////tmp////////////////
	void init();
private:
	void insert(int num, int i, int j, T e);
////	//////////////////////////////////////
public:
	//计算矩阵每一行第一个非零元素在矩阵中下标
	void calculate_rpos(int *rpos);
	//快速求系数矩阵的转置矩阵
	void fastTransposeMatrix(SMatrix<T> &S);
	
	int getColNum();
	int getRowNum();
	int getTotalNum();
	//取三元组表中某个非零元素的数据值
	T get_data_k_e(int p);
	int get_data_k_i(int p);
	int get_data_k_j(int p);


	void displayMatrix();

	// = + - *

	SMatrix<T> operator = (SMatrix<T> S);
	SMatrix<T> operator + (SMatrix<T> S);
	SMatrix<T> operator * (SMatrix<T> S);
	/////////////////////system auto call
	SMatrix();
	~SMatrix();
	SMatrix(const SMatrix<T> &S); 
protected:
	int rowNum;
	int colNum;
	int totalNum;
	Triple *data;
};

template<typename T>
void SMatrix<T>::insert(int num, int i, int j, T e)
{
	data[num].i = i;
	data[num].j = j;
	data[num].e = e;
}

template<typename T>
void SMatrix<T>::init()
{
	data = (Triple *)malloc(sizeof(Triple)*8);
	rowNum = 4;
	colNum = 4;
	totalNum = 8;
	insert(0, 0, 1, 8);
	insert(1, 1, 0, 4);
	insert(2, 1, 2, 23);
	insert(3, 1, 3, 7);
	insert(4, 2, 0, 11);
	insert(5, 2, 1, 7);
	insert(6, 2, 2, 4);
	insert(7, 3, 1, 8);
}

template<typename T>
void SMatrix<T>::clear()
{
	rowNum = 0;
	colNum = 0;
	totalNum = 0;
	delete []data;
	data = NULL;
}

template<typename T>
bool SMatrix<T>::isEmpty()
{
	return totalNum?0:1;
}

//rpos must have been malloced space
template<typename T>
void SMatrix<T>::calculate_rpos(int *rpos)
{
	for(int i = 0; i < rowNum; i++)
		rpos[i] = -1;
	for(int i = 0; i < totalNum; i++)
		if(rpos[data[i].i] == -1)
			rpos[data[i].i] = i;

}

template<typename T>
void SMatrix<T>::fastTransposeMatrix(SMatrix<T> &S)
{
	int cur_num, cur_i, k1;
	S.clear();
	S.colNum = rowNum;
	S.rowNum = colNum;
	S.totalNum = totalNum;
	S.data = (Triple *)malloc(sizeof(Triple)*totalNum);
	
	int rpos[colNum];
	//intial rpos
	for(int i=0; i < colNum; i++)
		rpos[i] = 0;
	//计算Transpose　Matrix每一列元素数量
	for(int i = 0; i < totalNum; i++)
		++rpos[data[i].j];

	int pre_num = rpos[0];
	//计算Transpose　Matrix每一列首个非零元素在三元组表中的位置
	rpos[0] = 0;
	for(int i=1; i < colNum; i++)
	{
		cur_num = rpos[i];
		rpos[i] = rpos[i-1] + pre_num;
		pre_num = cur_num; 
	}

	for(int i=0; i < totalNum; i++)
	{
		cur_i = data[i].j;
		k1 = rpos[cur_i];
		S.data[k1].i = data[i].j;
		S.data[k1].j = data[i].i;
		S.data[k1].e = data[i].e;
		++rpos[cur_i];
	}
}

template<typename T>
void SMatrix<T>::displayMatrix()
{
		cout << "     ";
	for(int i=0 ;i < colNum; i++)
		cout << "[ " << i << " ]";
	cout << endl;
	int m = 0;
	int j;
	while(m < totalNum) 
	{
		for (int i = 0; i < rowNum; ++i)
		{
			cout << "[ " << i << " ]";
			for (j = 0; j < colNum; ++j)
			{

				if(i == data[m].i && j == data[m].j)
					{
						cout << setw(5) << data[m].e;
						m++;
					}
				else
					cout << setw(5) << 0;
			
			}
			printf("\n");
		}
	}
}

template<typename T>
int SMatrix<T>::getColNum()
{
	return colNum;
}

template<typename T>
int SMatrix<T>::getRowNum()
{
	return rowNum;
}

template<typename T>
int SMatrix<T>::getTotalNum()
{
	return totalNum;
}

template<typename T>
T SMatrix<T>::get_data_k_e(int p)
{
	return data[p].e;
}

template<typename T>
int SMatrix<T>::get_data_k_i(int p)
{
	return data[p].i;
}

template<typename T>
int SMatrix<T>::get_data_k_j(int p)
{
	return data[p].j;
}

template<typename T>
SMatrix<T> SMatrix<T>::operator = (SMatrix<T> S)
{
	clear();
	rowNum = S.rowNum;
	colNum = S.colNum;
	totalNum = S.totalNum;
	data = (Triple *)malloc(sizeof(Triple)*S.totalNum);
	for(int i = 0; i < totalNum; i++)
	{
		data[i].i = S.data[i].i;
		data[i].j = S.data[i].j;
		data[i].e = S.data[i].e;
	}
	return *this;
}


template<typename T>
SMatrix<T> SMatrix<T>::operator * (SMatrix<T> S)
{
	if(colNum != S.rowNum)
	{
		cout << "error...." << endl;
		exit(1);
	}	

	int rpos1[rowNum];
	calculate_rpos(rpos1);

	SMatrix<T> S1;
	S.fastTransposeMatrix(S1);
	int rpos2[S1.rowNum];	
	S1.calculate_rpos(rpos2);

	int tmp[S1.rowNum];//临时存放计算结果
	for (int i = 0; i < S1.rowNum; ++i)
	{
		tmp[i] = 0;
	}


	SMatrix<T> T1;//过渡矩阵
	SMatrix<T> T2;//结果矩阵
	T1.data = (Triple *)malloc(sizeof(Triple)*(S1.rowNum * rowNum));
	T1.totalNum = 0;

	for(int i = 0; i < rowNum; i++)
	{	
		for(int j = rpos1[i]; j < (i == rowNum-1 ? totalNum:rpos1[i+1]); j++)
		{
			for(int m = 0; m < S1.rowNum; m++)
				for(int n = rpos2[m]; n < (m == S1.rowNum-1 ? S1.totalNum:rpos2[m+1]); n++)
				{
					if(S1.data[n].j == data[j].j )	
					{
						tmp[m] += S1.data[n].e * data[j].e; 
						break;
					}
				}
			
		}
		
		for (int q = 0; q < S1.rowNum; ++q)
		{
			if(tmp[q] != 0)
			{
				T1.data[T1.totalNum].i = i;
				T1.data[T1.totalNum].j = q;
				T1.data[T1.totalNum].e = tmp[q];
				T1.totalNum++;
				tmp[q] =0;
			}
		}
	}		

	T2.data = (Triple *)malloc(sizeof(Triple) * T1.totalNum);
	T2.rowNum = rowNum;
	T2.colNum = S1.rowNum;
	T2.totalNum = T1.totalNum;
	for(int i=0; i < T1.totalNum; i++)
	{
		T2.data[i].i = T1.data[i].i;
		T2.data[i].j = T1.data[i].j;
		T2.data[i].e = T1.data[i].e;
	} 
	cout << T2.totalNum << endl;	
	return T2;
} 

template<typename T>
SMatrix<T> SMatrix<T>::operator + (SMatrix<T> S)
{
	int k1 = 0; //左边矩阵三元组的索引
	int k2 = 0; //右边矩阵三元组的索引
	int k3 = 0; //过渡矩阵索引

	SMatrix<T> T1;//过渡矩阵
	SMatrix<T> T2;//结果矩阵
	T1.data = (Triple *)malloc(sizeof(Triple)*(S.totalNum + totalNum));
	assert(T1.data != 0);
	T1.colNum = colNum;
	T1.rowNum = rowNum;
	T1.totalNum = 0;
	if(colNum != S.colNum || rowNum != S.rowNum)
	{
		cout << "俩矩阵行列不等无法相加" << endl;
		exit(1);
	}

	while(k1 < totalNum && k2 < S.totalNum)
	{
		if(data[k1].i < S.data[k2].i)
		{
			
			T1.data[k3].i = data[k1].i;
			T1.data[k3].j = data[k1].j;
			T1.data[k3].e = data[k1].e;
			T1.totalNum++;
			k1++;
			k3++;
		}
		else if(data[k1].i > S.data[k2].i)
		{
			T1.data[k3].i = S.data[k2].i;
			T1.data[k3].j = S.data[k2].j;
			T1.data[k3].e = S.data[k2].e;
			T1.totalNum++;
			k2++;
			k3++;
		}
		else if(data[k1].j < S.data[k2].j)
		{
			T1.data[k3].i = data[k1].i;
			T1.data[k3].j = data[k1].j;
			T1.data[k3].e = data[k1].e;
			T1.totalNum++;
			k1++;
			k3++;
		}
		else if(data[k1].j > S.data[k2].j)
		{
			T1.data[k3].i = S.data[k2].i;
			T1.data[k3].j = S.data[k2].j;
			T1.data[k3].e = S.data[k2].e;
			T1.totalNum++;
			k2++;
			k3++;
		}
		else if(data[k1].e + S.data[k2].e == 0)
		{
			k1++;
			k2++;
		}
		else
		{
			T1.data[k3].i = S.data[k2].i;
			T1.data[k3].j = S.data[k2].j;
			T1.data[k3].e = S.data[k2].e + data[k1].e;
			T1.totalNum++;
			k1++;
			k2++;
			k3++;
		}
	}
	while(k1 < rowNum)
	{
		T1.data[k3].i = data[k1].i;
		T1.data[k3].j = data[k1].j;
		T1.data[k3].e = data[k1].e;
		T1.totalNum++;
		k1++;
		k3++;
	}
	while(k2 < S.rowNum)
	{
		T1.data[k3].i = S.data[k2].i;
		T1.data[k3].j = S.data[k2].j;
		T1.data[k3].e = S.data[k2].e;
		T1.totalNum++;
		k2++;
		k3++;
	}
	T2.data = (Triple *)malloc(sizeof(Triple) * T1.totalNum);
	T2.colNum = colNum;
	T2.rowNum = rowNum;
	T2.totalNum = T1.totalNum;
	for(int i=0; i < T2.totalNum; i++)
	{
		T2.data[i].i = T1.data[i].i; 
		T2.data[i].j = T1.data[i].j; 
		T2.data[i].e = T1.data[i].e; 
	}
	return T2;
}
/////////////////////system auto call
template<typename T>
SMatrix<T>::SMatrix()
{
	rowNum = 0;
	colNum = 0;
	totalNum = 0;
	data = NULL;
}

template<typename T>
SMatrix<T>::~SMatrix()
{
	delete []data;
}
template<typename T>
SMatrix<T>::SMatrix(const SMatrix &S)
{
	rowNum = S.rowNum;
	colNum = S.colNum;
	totalNum = S.totalNum;
	data = (Triple *)malloc(sizeof(Triple)*S.totalNum);
	for(int i = 0; i < totalNum; i++)
	{
		data[i].i = S.data[i].i;
		data[i].j = S.data[i].j;
		data[i].e = S.data[i].e;
	}	
}
#endif
