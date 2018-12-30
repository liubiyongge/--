//
// Created by yanjiewei on 18-12-20.
//

#ifndef TSMATRIX_ORTHOGONAL_LIST_TEST_H
#define TSMATRIX_ORTHOGONAL_LIST_TEST_H


#include "TSMatrix(Orthogonal List).h"

template <typename ElemType>
void ex3_1_1(TSMatrix<ElemType> &S)
{
    cout<< "*****稀疏矩阵的赋值运算*****"<< endl;
    TSMatrix<ElemType> T;
    T.random(1);
    S = T;
    cout<< "另一个稀疏矩阵赋值给当前稀疏矩阵为："<< endl;
    S.display();
    cout<< endl;
    cout<< "***********************"<< endl;
}


template <typename ElemType>
void ex3_1_2(TSMatrix<ElemType> &S)
{
    cout<< "*****求稀疏矩阵的加法*****"<< endl;
    cout<< "当前矩阵如下:"<< endl;
    S.display();
    TSMatrix<ElemType> T, P;
    T.random(1);
    cout<< "随机生成一个矩阵如下："<< endl;
    T.display();
    S.TSadd(T, P);
    cout<< "相加所得矩阵如下:"<< endl;
    P.display();
    cout<< endl;
    cout<< "***********************"<< endl;
}



template <typename ElemType>
void ex3_1_3(TSMatrix<ElemType> &S)
{
    cout<< "*****随机生成稀疏矩阵*****"<< endl;
    S.random(0);
    cout<< "生成了"<< S.getRowNum()<< " × "<< S.getColNum()<< "的稀疏矩阵，其非零元素如下"<< endl;
    S.show();
    cout<< "十字链表存储如下"<< endl;
    S.display();
    cout<< endl;
    cout<< "***********************"<< endl;
}

template <typename ElemType>
void ex3_1_4(TSMatrix<ElemType> &S)
{
    cout<< "*****用已有的稀疏矩阵初始化一个新矩阵*****"<< endl;
    cout<< "当前稀疏矩阵初始化一个新矩阵为:"<< endl;
    S.display();
    cout<< endl;
    cout<< "***********************"<< endl;
}



#endif //TSMATRIX_ORTHOGONAL_LIST_TEST_H
