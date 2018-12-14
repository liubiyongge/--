#ifndef TEST_H
#define TEST_H
#include "test.h"
#endif // !TEST_H

#include<iostream>
using namespace std;
#include<string>

#ifndef THREADTREE_H
#define THREADTREE_H
#include "ThreadTree.h"
#endif

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include "HuffmanTree.h"
#endif

int main()
{
    using std::cout;

    BiTree<char> q, p;
    ThreadTree<char> tt;
    HuffmanTree<char> ht;

    char continueYN;
    int choose = 0;
    std::cout<<"\n********# 随机生成测试树——二叉树 #********\n";
    q.randomcreate(7);//生成普通二叉树,修改默认参数
    std::cout << std::endl;
    bool isCreat_threadTree=false;
    do {
        cout << q;
        std::cout << "\n*********测试顺序表的操作*********" << std::endl;
        std::cout << "输出你想要的操作序号(0为退出)" << std::endl;
        std::cout << "\t1.求二叉树的结点数" << std::endl;
        std::cout << "\t2.求二叉树的叶子数" << std::endl;
        std::cout << "\t3.递归求二叉树的深度" << std::endl;
        std::cout << "\t4.交换二叉树中所有结点的左右子树" << std::endl;
        std::cout << "\t5.前序递归遍历二叉树" << std::endl;
        std::cout << "\t6.中序递归遍历二叉树" << std::endl;
        std::cout << "\t7.后序递归求二叉树" << std::endl;
        std::cout << "\t8.非递归中序遍历二叉树" << std::endl;
        std::cout << "\t9.按层次顺序遍历二叉树" << std::endl;
        std::cout << "\t10.以顺序存储的方式显示二叉树" << std::endl;
        std::cout << "\t11.二叉树的二叉链表储存转化为顺序存储结构" << std::endl;
        std::cout << "\t12.二叉树的顺序存储转换为二叉链表存储结构" << std::endl;
        std::cout << "\t13.随机生成二叉树" << std::endl;
        std::cout << "\t14.输入二叉树" << std::endl;
        std::cout << "\t15.中序遍历中序穿线二叉树"<<'\n';
        std::cout << "\t16.中序穿线二叉树顺序存储转链式存储"<<'\n';
        std::cout << "\t17.中序穿线二叉树中找指定结点中序的前驱和后继"<<'\n';
        std::cout << "\t18.随机生成中序穿线二叉树"<<'\n';
        std::cout << "\t19.输入中序穿线二叉树"<<'\n';
        std::cout << "\t20.哈夫曼树（二叉树的应用）"<<'\n';
        std::cout << "输出你想要的操作序号(0为退出):";
        std::cin >> choose;
        if(choose>14 &&choose<18 && !isCreat_threadTree){
            isCreat_threadTree= true;
            std::cout<<"\n********# 随机生成测试树——穿线中序二叉树 #********\n";
            tt.randomCreate(7);
            cout<<"\n当前穿线中序二叉树为：\n";
            cout<<tt;
        }
        switch (choose)
        {
            case 1:e1(q); cout << endl; break;
            case 2:e2(q); cout << endl; break;
            case 3:e3(q); cout << endl; break;
            case 4:e4(q); cout << endl; break;
            case 5:e5(q); cout << endl; break;
            case 6:e6(q); cout << endl; break;
            case 7:e7(q); cout << endl; break;
            case 8:e8(q); cout << endl; break;
            case 9:e9(q); cout << endl; break;
            case 10:e10(q); cout << endl; break;
            case 11:e11(q); cout << endl; break;
            case 12:e12(q); cout << endl; break;
            case 13:e13(q); cout << endl; break;
            case 14:e14(q); cout << endl; break;
            case 15:e15(tt);cout << '\n'; break;
            case 16:e16(tt);cout << '\n'; break;
            case 17:e17(tt);cout << '\n'; break;
            case 18:e18(tt);cout << '\n'; break;
            case 19:e19(tt);cout << '\n'; break;
            case 20:e20(ht);cout<<'\n';break;
            default: cout << "\n结束" << endl;
        }
        std::cout << "是否继续Y/N" << std::endl;
        std::cin >> continueYN;

    } while (continueYN == 'Y' || continueYN == 'y');
    return 0;
}
