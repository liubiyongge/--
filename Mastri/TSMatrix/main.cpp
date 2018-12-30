#include "header.h"
#include "TSMatrix.h"
#include "test.h"


int main(int argc, char const *argv[])
{

    int choose;
    char contiueYesNO;
    TSMatrix <int> S;
    while(1)
    {
        cout << "*********测试稀疏矩阵的操作**********"<< endl;
        cout<< "   *******采用三元组表存储*******   "<< endl;
        cout << "1. 求稀疏矩阵的转置矩阵" << endl;
        cout << "2. 快速求稀疏矩阵的转置矩阵" << endl;
        cout << "3. 计算稀疏矩阵各行第一个非零元素的下标" << endl;
        cout << "4. 稀疏矩阵的赋值运算" << endl;
        cout << "5. 求稀疏矩阵的加法" << endl;
        cout << "6. 求稀疏矩阵的乘积" << endl;
        cout << "7. 显示稀疏矩阵的三元组表示" << endl;
        cout << "8. 随机生成稀疏矩阵" << endl;
        cout << "9. 用已有的稀疏矩阵初始化一个新矩阵" << endl;
        cout << "10. 输入稀疏矩阵的三元组表" << endl;
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
            case 5: ex3_1_5(S);
                break;
            case 6: ex3_1_6(S);
                break;
            case 7: ex3_1_7(S);
                break;
            case 8: ex3_1_8(S);
                break;
            case 9: ex3_1_9(S);
                break;
            case 10: ex3_1_10(S);
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