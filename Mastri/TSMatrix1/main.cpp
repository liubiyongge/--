#include "header.h"
#include "test.h"
#include "TSMatrix(Orthogonal List).h"









int main(int argc, char const *argv[])
{

    int choose;
    char contiueYesNO;
    TSMatrix<int> S;
    while(1)
    {
        cout << "*********测试稀疏矩阵的操作**********"<< endl;
        cout<< "   *******（采用十字链表存储）*******   "<< endl;
        cout << "1. 求稀疏矩阵的赋值运算" << endl;
        cout << "2. 求稀疏矩阵的加法" << endl;
        cout << "3. 随机生成稀疏矩阵" << endl;
        cout << "4. 用已有的稀疏矩阵初始化一个新矩阵" << endl;
        cout<< "其他.结束"<< endl;
        cout << "当前稀疏矩阵为：" << endl;
        cout<< "////////////////////////////////////////"<<endl;
        S.display();
        cout<<"//////////////////////////////////////////"<<endl;
        cout<<"请选择你要操作的代码<1-10>";
        cin >> choose;
        switch(choose)
        {
            case 1: ex3_1_1(S);
                break;
            case 2: ex3_1_2(S);
                break;
            case 3: ex3_1_3(S);
                break;
            case 4: ex3_1_4(S);
                break;
            default: cout<<"\n\t你选择了结束"<<endl<<endl;
                return 0;
        }
        cout<<"还继续吗！(Y.继续\tN.结束)";
        cin >> contiueYesNO;
        if(contiueYesNO == 'N' || contiueYesNO == 'n')
            break;

    }

    return 0;
}