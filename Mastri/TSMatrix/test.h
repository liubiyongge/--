//
// Created by yanjiewei on 18-12-19.
//

#ifndef TSMATRIX_TEST_H
#define TSMATRIX_TEST_H


template <typename ElemType>
void ex3_1_1(TSMatrix<ElemType> &S)
{
    cout<< "*****求稀疏矩阵的转置矩阵*****"<< endl;
    S.fastTransposeMatrix(S);
    cout<< "转置后的矩阵如下"<< endl;
    S.display();
    cout<< endl;
    cout<< "***********************"<< endl;
}


template <typename ElemType>
void ex3_1_2(TSMatrix<ElemType> &S)
{
    cout<< "*****快速求稀疏矩阵的转置矩阵*****"<< endl;
    S.fastTransposeMatrix(S);
    cout<< "转置后的矩阵如下"<< endl;
    S.display();
    cout<< endl;
    cout<< "***********************"<< endl;
}


template <typename ElemType>
void ex3_1_3(TSMatrix<ElemType> &S)
{
    cout<< "*****计算稀疏矩阵第各行第一个非零元素在三元组表中的下标*****"<< endl;
    int rpos[100];
    S.calculate_rpos(rpos, 1);
    cout<< endl;
    cout<< "***********************"<< endl;
}

template <typename ElemType>
void ex3_1_4(TSMatrix<ElemType> &S)
{
    cout<< "*****稀疏矩阵的赋值运算*****"<< endl;
    cout<< "另一个稀疏矩阵赋值给当前矩阵后如下";
    S.random(1);
    S.display();
    cout<< endl<< "***********************"<< endl;
}

template <typename ElemType>
void ex3_1_5(TSMatrix<ElemType> &S)
{
    cout<< "*****求稀疏矩阵的加法*****"<< endl;
    TSMatrix<ElemType> T, P;
    T.random(1);
    S.random(10);
    cout<< "当前矩阵如下"<< endl;
    S.display();
    cout<< endl<< "随机生成的矩阵如下"<< endl;
    T.display();
    S.TSadd(T, P);
    cout<< endl<< "相加后的矩阵如下"<< endl;
    P.display();
    cout<< "***********************"<< endl;
}

template <typename ElemType>
void ex3_1_6(TSMatrix<ElemType> &S)
{
    cout<< "*****求稀疏矩阵的乘积*****"<< endl;
    TSMatrix<ElemType> T, P;
    T.random(1);
    S.random(10);
    cout<< "当前矩阵如下"<< endl;
    S.display();
    cout<< endl<< "随机生成的矩阵如下"<< endl;
    T.display();
    cout<< endl<< "相乘后的矩阵如下"<< endl;
    S.TScheng(T, P);
    P.display();
    cout<< "***********************"<< endl;
}



template <typename ElemType>
void ex3_1_7(TSMatrix<ElemType> &S)
{
    cout<< "*****显示稀疏矩阵的三元组表示*****"<< endl;
    S.show();
    cout<< endl;
    cout<< "***********************"<< endl;
}

template <typename ElemType>
void ex3_1_8(TSMatrix<ElemType> &S)
{
    cout<< "*****随机生成稀疏矩阵*****"<< endl;
    S.random(0);
    cout<< "随机生成的稀疏矩阵如下"<< endl;
    S.display();
    cout<< endl<<  "***********************"<< endl;
}


template <typename ElemType>
void ex3_1_9(TSMatrix<ElemType> &S)
{
    cout<< "*****用已有的稀疏矩阵初始化一个新矩阵*****"<< endl;
    cout<< "初始化后的稀疏矩阵如下"<< endl;
    S.display();
    cout<< endl<<  "***********************"<< endl;
}

template <typename ElemType>
void ex3_1_10(TSMatrix<ElemType> &S)
{
    cout<< "*****输入稀疏矩阵的三元组表*****"<< endl;
    S.TSs();
    cout<< "输入后的稀疏矩阵如下"<< endl;
    S.display();
    cout<< endl;
    cout<< endl<<  "***********************"<< endl;
}





#endif //TSMATRIX_TEST_H
