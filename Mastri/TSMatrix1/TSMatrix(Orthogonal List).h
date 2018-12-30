//
// Created by yanjiewei on 18-12-20.
//

#ifndef TSMATRIX_ORTHOGONAL_LIST_TSMATRIX_ORTHOGONAL_LIST_H
#define TSMATRIX_ORTHOGONAL_LIST_TSMATRIX_ORTHOGONAL_LIST_H





template <typename ElemType>
class TSMatrix{

private:
    class Triple{
    public:
        int i, j;
        ElemType e;
    };

public:


    //置空
    void clear();

    //计算各行第一个非0元素的下标
    void calculate_rpos(int *rpos, int display = 0);

    //转置
    void fastTransposeMatrix(TSMatrix <ElemType> &s);

    //输出三元组表
    void show();

    //求列数
    int getColNum();

    //求行数
    int getRowNum();

    //求元素个数
    int getTotalNum();

    //判断是否为空
    bool isEmpty();

    //输出矩阵
    void display();

    //随机生成稀疏矩阵
    void random(int k);

    //输入三元组表
    void TSs();

    //加法
    void TSadd(TSMatrix S, TSMatrix &P);

    //乘法
    void TScheng(TSMatrix S, TSMatrix &P);


    //重载
    TSMatrix <ElemType> operator =(TSMatrix <ElemType> rightS);


    TSMatrix();

    ~TSMatrix();

    TSMatrix(const TSMatrix <ElemType> &s);

protected:
    int rowNum, colNum, totalNum;
    Triple *data;

};


template <typename ElemType>
void TSMatrix <ElemType>::clear() {
    if(data)
        delete[] data;
    data = NULL;
    rowNum = 0, colNum = 0, totalNum = 0;
}

template <typename ElemType>
void TSMatrix <ElemType>::calculate_rpos(int *rpos, int display) {
    int k, cur, pre_num, cur_num;
    if(!totalNum)
        return;
    for(int i = 0; i < rowNum; i++)
        rpos[i] = 0;
    for(int i = 0; i < totalNum; i++)
        rpos[data[i].i]++;
    rpos[0] = 0;
    pre_num = rpos[0];
    for(int i = 1; i < rowNum; i++){
        cur_num = rpos[i];
        rpos[i] = rpos[i - 1] + pre_num;
        pre_num = rpos[i];
    }
    if(display){
        cout<< "行号    第一个非零元素在三元组表中的下标"<< endl;
        for(int i = 0; i < rowNum; i++)
            cout<< "["<< i + 1<< "]       "<< rpos[i]<< endl;
    }

}

template <typename ElemType>
void TSMatrix <ElemType>::show() {
    cout<< "下标  "<<setw(5) << "行"<<setw(5)<< "列"<< setw(5)<< "值"<< endl;
    for(int k = 0; k < totalNum; k++)
        cout<< "["<< setw(2)<< k<< "]"<< setw(4)<<  data[k].i<< setw(4)<< data[k].j << setw(4)<< data[k].e<< endl;

}

template <typename ElemType>
int TSMatrix <ElemType> ::getRowNum() {
    return rowNum;
}

template <typename ElemType>
int TSMatrix <ElemType> ::getColNum() {
    return colNum;
}


template <typename ElemType>
int TSMatrix <ElemType> ::getTotalNum() {
    return totalNum;
}

template <typename ElemType>
bool TSMatrix <ElemType>::isEmpty() {
    if(totalNum)
        return false;
    else
        return true;
}

template <typename ElemType>
void TSMatrix <ElemType>::fastTransposeMatrix(TSMatrix<ElemType> &s) {
    TSMatrix <ElemType> S;
    S.rowNum = colNum;
    S.colNum = rowNum;
    S.totalNum = totalNum;
    S.data = new Triple[totalNum];
    int k2 = 0;
    for(int cur = 0; cur < colNum; cur++){
        for(int k1 = 0; k1 < totalNum; k1++){
            if(data[k1].j == cur){
                S.data[k2].j = data[k1].i;
                S.data[k2].i = data[k1].j;
                S.data[k2].e = data[k1].e;
                k2++;
            }
        }
    }
    data = S.data;
    cout<< "转置后的矩阵如下"<< endl;
    display();
    cout<< endl;
}

template <typename ElemType>
void TSMatrix<ElemType>::display() {
    if(totalNum == 0){
        cout<< "这个矩阵为空哦！"<< endl;
        return;
    }
    cout<< "该"<< rowNum<< " × "<< colNum<< "矩阵共有"<< totalNum<< "个元素"<< endl;
    ElemType a[100][100];
    for(int i = 0; i < rowNum; i++)
        for(int j = 0; j < colNum; j++)
            a[i][j] = 0;
    for(int i = 0; i < totalNum; i++){
        a[data[i].i][data[i].j] = data[i].e;
    }
    cout<< "      ";
    for(int i = 0; i < colNum; i++)
        cout<< "["<< setw(2)<< i + 1<< "] ";
    cout<< endl;
    for(int i = 0; i < rowNum; i++){
        cout<< "["<< setw(2)<< i + 1<< "]";
        for(int j = 0; j < colNum; j++){
            cout<< setw(5)<< a[i][j];
        }
        cout<< endl;
    }

}

template <typename ElemType>
void TSMatrix<ElemType>::random(int k) {
    int r, c;
    if(k)
        r = 10;
    else {
        cout << "请输入您想要生成的矩阵的行数：";
        cin >> r;
    }
    if(k)
        c = 10;
    else {
        cout << "请输入您想要生成的矩阵的列数：";
        cin >> c;
    }
    srand(int(time(0)) + k);
    ElemType a[1000][1000];
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(rand() % 5 == 0)
                a[i][j] = rand() % 100;
            else
                a[i][j] = 0;
        }
    }
    int num = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] != 0){
                num++;
            }
        }
    }
    data = new Triple[num];
    int n = 0;
    for(int i = 0;i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] != 0){
                data[n].i = i;
                data[n].j = j;
                data[n].e = a[i][j];
                n++;
            }
        }
    }
    rowNum = r, colNum = c;
    totalNum = num;
}

template <typename ElemType>
void TSMatrix<ElemType>::TSs() {
    int n, c, r;
    cout<< "请输入稀疏矩阵的行数：";
    cin>> r;
    cout<< "请输入稀疏矩阵的列数：";
    cin>> c;
    cout<< "请输入三元组表元素的个数：";
    cin>> n;
    colNum = c, rowNum = r, totalNum = n;
    data = new Triple[n];
    for(int i = 0; i < n; i++){
        cout<< "请输入第"<< i + 1<< "个元素的行号：";
        cin>> data[i].i, data[i].i--;
        cout<< "请输入第"<< i + 1<< "个元素的列号:";
        cin>> data[i].j, data[i].j--;
        cout<< "请输入第"<< i + 1<< "个元素的值：";
        cin>> data[i].e;
    }
}










template <typename ElemType>
TSMatrix<ElemType> TSMatrix<ElemType>::operator =(TSMatrix<ElemType> rightS){
    clear();
    rowNum = rightS.rowNum;
    colNum = rightS.colNum;
    totalNum = rightS.totalNum;
    if(totalNum){
        data = new Triple[totalNum];
        for(int i = 0; i < totalNum; i++){
            data[i].i = rightS.data[i].i;
            data[i].j = rightS.data[i].j;
            data[i].e = rightS.data[i].e;
        }
    }
    return *this;
}

template <typename ElemType>
void TSMatrix<ElemType>::TSadd(TSMatrix S, TSMatrix &P) {
    int a[100][100], b[100][100], c[100][100];
    if (colNum != S.colNum || rowNum != S.colNum) {
        cout << "俩矩阵行列不相等，无法相加！" << endl;
        exit(1);
    }
    for (int i = 0; i < S.rowNum; i++) {
        for (int j = 0; j < S.colNum; j++) {
            a[i][j] = b[i][j] = 0;
        }
    }
    for (int i = 0; i < totalNum; i++) {
        a[data[i].i][data[i].j] = data[i].e;
    }
    for (int i = 0; i < S.totalNum; i++)
        b[S.data[i].i][S.data[i].j] = S.data[i].e;
    for (int i = 0; i < S.rowNum; i++) {
        for (int j = 0; j < S.colNum; j++)
            c[i][j] = a[i][j] + b[i][j];
    }
    int num = 0, n = 0;
    for (int i = 0; i < S.rowNum; i++) {
        for (int j = 0; j < S.colNum; j++)
            if (c[i][j] != 0)
                num++;
    }
    P.colNum = S.colNum, P.rowNum = S.rowNum;
    P.totalNum = num;
    P.data = new Triple[num];
    for (int i = 0; i < S.rowNum; i++) {
        for (int j = 0; j < S.colNum; j++) {
            if (c[i][j] != 0) {
                P.data[n].i = i;
                P.data[n].j = j;
                P.data[n].e = c[i][j];
                n++;
            }
        }
    }
}



template <typename ElemType>
void TSMatrix<ElemType>::TScheng(TSMatrix S, TSMatrix &P) {
    int a[100][100], b[100][100], c[100][100];
    if (colNum != S.rowNum) {
        cout << "俩矩阵行列不相等，无法相乘！" << endl;
        exit(1);
    }
    for (int i = 0; i < S.rowNum; i++) {
        for (int j = 0; j < S.colNum; j++) {
            a[i][j] = b[i][j] = 0;
        }
    }
    for (int i = 0; i < totalNum; i++) {
        a[data[i].i][data[i].j] = data[i].e;
    }
    for (int i = 0; i < S.totalNum; i++)
        b[S.data[i].i][S.data[i].j] = S.data[i].e;
    int num = 0, n = 0;
    for(int i = 0; i < rowNum; i++){
        for(int j = 0; j < S.colNum; j++){
            for(int k = 0; k < colNum; k++){
                n = n + a[i][k] * b[k][j];
            }
            c[i][j] = n, n = 0;
        }
    }
    for (int i = 0; i < S.rowNum; i++) {
        for (int j = 0; j < S.colNum; j++)
            if (c[i][j] != 0)
                num++;
    }
    P.colNum = S.colNum, P.rowNum = S.rowNum;
    P.totalNum = num;
    P.data = new Triple[num];
    for (int i = 0; i < S.rowNum; i++) {
        for (int j = 0; j < S.colNum; j++) {
            if (c[i][j] != 0) {
                P.data[n].i = i;
                P.data[n].j = j;
                P.data[n].e = c[i][j];
                n++;
            }
        }
    }
}





template <typename ElemType>
TSMatrix<ElemType>::TSMatrix() {
    colNum = 0, rowNum = 0, totalNum = 0;
    data = NULL;
}

template <typename ElemType>
TSMatrix<ElemType>::~TSMatrix() {
    clear();
}

template <typename ElemType>
TSMatrix<ElemType>::TSMatrix(const TSMatrix<ElemType> &otherS){
    rowNum = otherS.rowNum;
    colNum = otherS.colNum;
    totalNum = otherS.totalNum;
    if(totalNum){
        data = new Triple[totalNum];
        for(int i = 0; i < totalNum; i++){
            data[i].i = otherS.data[i].i;
            data[i].j = otherS.data[i].j;
            data[i].e = otherS.data[i].e;
        }
    }
    else
        data = NULL;
}


#endif //TSMATRIX_ORTHOGONAL_LIST_TSMATRIX_ORTHOGONAL_LIST_H
