#include <iostream>
#include "textEditor.h"
#include "SqString.h"
using namespace std;

SqString a;
textEditor x;

void menu();
void code1();
void code2();
void code3();
void code4();
void code5();
void code6();
void code7();
void code8();
void code9();
void code10();
void code11();
void code12();
void code13();
void code14();
void code15();
void code16();
void code17();
void code18();
void code19();
void code20();
void code201();
void code202();
void code203();
void code204();
void code205();
void code206();
void code207();
void code208();
void code209();

int main()
{
    while(1)
    {
        system("clear");
        menu();
        if(a.isEmpty())
            cout << " ��ǰ˳��Ϊ��" << endl;
        else
            cout << " ��ǰ˳��Ϊ: " << a << endl;
        cout << " ----------------------------------------------------------------------- \n";
        cout << " ��ѡ����Ҫ�����Ĵ���<1-20>: ";
        int n;
        cin >> n;
        switch(n)
        {
            case 1:
                code1();
                break;
            case 2:
                code2();
                break;
            case 3:
                code3();
                break;
            case 4:
                code4();
                break;
            case 5:
                code5();
                break;
            case 6:
                code6();
                break;
            case 7:
                code7();
                break;
            case 8:
                code8();
                break;
            case 9:
                code9();
                break;
            case 10:
                code10();
                break;
            case 11:
                code11();
                break;
            case 12:
                code12();
                break;
            case 13:
                code13();
                break;
            case 14:
                code14();
                break;
            case 15:
                code15();
                break;
            case 16:
                code16();
                break;
            case 17:
                code17();
                break;
            case 18:
                code18();
                break;
            case 19:
                code19();
                break;
            case 20:
                code20();
                break;
            default:
                cout << " ����" << endl;
                return 0;
        }
        cout << " ��������<Y.����\tN.����>?";
        char c;
        cin >> c;
        if(c == 'Y' || c == 'y')
            continue;
        else
            break;
    }
    return 0;
}

void code1()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " ------------------------ && ��˳�򴮵ĳ��� && ------------------------- \n";
    cout << " ��ǰ˳�򴮵ĳ���Ϊ" << a.getLength() << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code2()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " ---------------------- && �ж�˳���Ƿ�Ϊ�� && ----------------------- \n";
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��" << endl;
    else
        cout << " ��ǰ˳�򴮲�Ϊ��" << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code3()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " ------------------------ && ȡ˳�򴮵��Ӵ� && ------------------------- \n";
    cout << " �������Ӵ���ʼ���ַ����: ";
    int start;
    int n = a.getLength();
    while(cin >> start)
    {
        if(start >= 1 && start <= n)
            break;
        else
            cout << " ��������Ƿ�, ������<1-" << n << ">: ";
    }
    int len;
    cout << " �������Ӵ��ĳ���: ";
    while(cin >> len)
    {
        if(len >= 1 && len <= n - start + 1)
            break;
        else
            cout << " ��������Ƿ�, ������<1-" << n - start + 1 << ">: ";
    }
    SqString tmp;
    a.subString(tmp, start, len);
    cout << " ��ǰ���ӵ�" << start << "���ַ���ʼ����Ϊ" << len << "���Ӵ�Ϊ" << tmp << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code4()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " ---------------- && �ڵ�i���ַ�ǰ������һ��˳�� && ------------------ \n ";
    cout << " ��һ��˳��Ϊ: ";
    SqString c;
    cin >> c;
    cout << " �����������һ��˳�򴮵�λ��: ";
    int i;
    int n = a.getLength();
    while(cin >> i)
    {
        if(i >= 1 && i <= n)
            break;
        else
            cout << " ��������Ƿ�, ������<1-" << n << ">: ";
    }
    a.insert(i, c);
    cout << " �ڵ�" << i << "���ַ�ǰ����" << c << "��, ��ǰ˳��Ϊ" << a << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code5()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " --------------- && ɾ���ӵ�i���ַ��𳤶�Ϊlen���Ӵ� && ---------------- \n";
    cout << " ������ɾ���Ӵ�����ʼλ��: ";
    int start;
    int n = a.getLength();
    while(cin >> start)
    {
        if(start >= 1 && start <= n)
            break;
        else
            cout << " ��������Ƿ�, ������<1-" << n << ">: ";
    }
    cout << " ������ɾ���Ӵ��ĳ���: ";
    int len;
    while(cin >> len)
    {
        if(len >= 1 && len <= n - start + 1)
            break;
        else
            cout << " ��������Ƿ�, ������<1-" << n - start + 1 << ">: ";
    }
    SqString tmp;
    a.strDelete(start, len);
    cout << " �ӵ�" << start << "���ַ���ʼɾ������Ϊ" << len << "���Ӵ�Ϊ " << a << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code6()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " ---------- && �ж�SqString˳����C++String˳���Ƿ���� && ---------- \n";
    cout << " ������һ��C++String˳��: ";
    char c[100];
    cin >> c;
    cout << " ��ǰ��SqString˳��" << a;
    if((a == c) == 0)
        cout << "����";
    else
        cout << "������";
    cout << "C++String˳��" << c << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code7()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " ---------- && �ж�SqString˳����SqString˳���Ƿ���� && ---------- \n";
    cout << " ������һ��SqString˳��: ";
    SqString c;
    cin >> c;
    // cout << c.getLength() << a.getLength() << endl;
    cout << " ��ǰ��SqString˳��" << a;
    if((a == c) == 0)
        cout << "����";
    else
        cout << "������";
    cout << "SqString˳��" << c << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code8()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " ----------- && SqString˳����C++String˳�򴮵ļӷ����� && ----------- \n";
    cout << " ������һ��C++String˳��: ";
    char c[100];
    cin >> c;
    a = a + c;
    cout << " ��ǰSqString˳��" << a << "��\n C++String˳��" << c << "�������ӳ�" << a << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code9()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " --------------- && ����SqString˳��֮��ļӷ����� && ---------------- \n";
    cout << " ��������һ��SqString˳��: ";
    SqString c;
    cin >> c;
    a = a + c;
    cout << " ��ǰSqString˳��\"" << a << "\"��\n C++String˳��\"" << c << "\"�������ӳ�\"" << a << "\"" << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code10()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " -------------------- && ��������ƥ��(�л��ݲ���) && ------------------- \n";
    cout << " ----------- ����ģʽ���������е�pos���ַ����һ�γ��ֵ�λ�� ----------- \n";
    cout << " ������һ������: ";
    SqString c, d;
    cin >> c;
    cout << " ������һ��ģʽ��: ";
    cin >> d;
    cout << " �����뿪ʼ���ҵ��ַ������(��1��ʼ): ";
    int i;
    int n = a.getLength();
    while(cin >> i)
    {
        if(i >= 1 && i <= n)
            break;
        else
            cout << " ��������Ƿ�, ������<1-" << n << ">: ";
    }

    int x = c.index(d, i);
    if(x)
    {
        cout << " ģʽ��" << d << "������" << c << "�ӵ�1���ַ���" << endl;
        cout << " ��һ�γ��ֵ�λ��Ϊ: " << x << endl;
    }
    else
        cout << " ģʽ��" << d << "δ��������ƥ�䵽" << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code11()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " ---------------------- && ��ģʽ����next���� && ----------------------- \n";
    cout << " ������һ��ģʽ��: ";
    SqString c;
    cin >> c;
    int next[100];
    c.get_next(next, 1);
    cout << " ----------------------------------------------------------------------- \n";
}

void code12()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " ------------------ && ģʽƥ��(�޻���KMP��������) && ------------------ \n";
    cout << " ----------- ����ģʽ���������е�pos���ַ����һ�γ��ֵ�λ�� ----------- \n";
    cout << " ������һ������: ";
    SqString c, d;
    cin >> c;
    cout << " ������һ��ģʽ��: ";
    cin >> d;
    cout << " �����뿪ʼ���ҵ��ַ������(��1��ʼ): ";
    int i;
    int n = a.getLength();
    while(cin >> i)
    {
        if(i >= 1 && i <= n)
            break;
        else
            cout << " ��������Ƿ�, ������<1-" << n << ">: ";
    }

    int x = c.index_KMP(d, i);
    if(x)
    {
        cout << " ��KMP���������Ӵ�" << d << "������" << c << "\n �ӵ�1���ַ���" << endl;
        cout << " ��һ�γ��ֵ�λ��Ϊ: " << x << endl;
    }
    else
        cout << " ģʽ��" << d << "δ��������ƥ�䵽" << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code13()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " ----------- && ��ֵ����<SqString˳��=C++String˳��> && ------------ \n";
    cout << " C++String˳��Ϊ: ";
    char c[100];
    cin >> c;
    a = c;
    cout << " ��ǰ˳�򴮱���ֵΪ: " << a << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code14()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " ------------ && ��ֵ����<SqString˳��=SqString˳��> && ------------ \n";
    SqString c;
    c.getByRand();
    a = c;
    cout << " ��һ��SqString˳�򴮸�ֵ����ǰSqString˳��Ϊ: " << a << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code15()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " -------------------------- && ��˳���ÿ� && ------------------------- \n";
    cout << " ��ǰ˳�򴮵ĳ���Ϊ: " << a.getLength() << endl;
    a.clear();
    cout << " �ѵ�ǰ˳���ÿպ�ĳ���Ϊ: " << a.getLength() << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code16()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " ------------------ && �������˳��(СдӢ����ĸ) && ----------------- \n";
    cout << " ������ɵ�ǰ�ַ���˳��(СдӢ����ĸ)Ϊ: ";
    a.getByRand();
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << a << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code17()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " --------------- && ��C++String˳�򴮳�ʼ��һ��˳�� && --------------- \n";
    cout << " ------------------- && ���ÿ�����ʼ�����캯�� && ---------------------- \n";
    cout << " ������һ��C++String˳��: ";
    char c[100];
    cin >> c;
    cout << " ͨ��������ʼ�����캯��." << endl;
    SqString d(c);
    cout << " �������C++String˳�򴮳�ʼ����SqString˳��Ϊ: " << d << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code18()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ˳��Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " ------------- && ����һ��Sqstring˳�򴮳�ʼ��һ��˳�� && ------------ \n";
    cout << " ------------------- && ���ÿ�����ʼ�����캯�� && ---------------------- \n";
    cout << " ͨ��������ʼ�����캯��, �õ�ǰ��SqString˳��\n";
    cout << " ��ʼ����һ��SqString˳��Ϊ: ";
    SqString c(a);
    cout << c << endl;
    cout << " ----------------------------------------------------------------------- \n";
}

void code19()
{
    system("clear");
    if(a.isEmpty())
        cout << " ��ǰ�ı�Ϊ��." << endl;
    else
        cout << " ��ǰ˳��Ϊ: " << a << endl;
    cout << " -------------------------- && ����˳�� && --------------------------- \n";
    cout << " ������˳��: ";
    cin >> a;
    cout << " ----------------------------------------------------------------------- \n";
}

void code20()
{
    while(1)
    {
        system("clear");
        cout << " ----------------- && �򵥵��ı��༭��(˳�򴮵�Ӧ��) && ---------------- \n";
        cout << " 20.1. �������һ��\n"
             << " 20.2. �������һ��\n"
             << " 20.3. �������һ���ַ�\n"
             << " 20.4. �������һ���ַ�\n"
             << " 20.5. ɾ����괦��ʼ���ַ���\n"
             << " 20.6. �ڹ��֮ǰ����һ���ı�\n"
             << " 20.7. ��һ���ı��滻��괦��ʼ��len���ַ���\n"
             << " 20.8. ҳ������\n"
             << " 20.9. �����ı�\n"
             << " ����. ����\n";
        cout << " ----------------------------------------------------------------------- \n";
        cout << x;
        cout << " ----------------------------------------------------------------------- \n";
        cout << " ��ѡ����Ҫ�����Ĵ���<1-9>: ";
        int n;
        cin >> n;
        switch(n)
        {
            case 1:
                code201();
                break;
            case 2:
                code202();
                break;
            case 3:
                code203();
                break;
            case 4:
                code204();
                break;
            case 5:
                code205();
                break;
            case 6:
                code206();
                break;
            case 7:
                code207();
                break;
            case 8:
                code208();
                break;
            case 9:
                code209();
                break;
            default:
                cout << " ����" << endl;
                return ;
        }
        cout << " ��������<Y.����\tN.����>?";
        char c;
        while(cin >> c)
        {
            if(c == 'n' || c == 'N')
                return ;
            else if(c == 'y' || c == 'Y')
                break;
            else
            {
                cout << " ������<Y.����\tN.����> ";
                continue;
            }
        }
    }
}

void code201()
{
    system("clear");
    cout << x;
    cout << " ------------------------- && �������һ�� && -------------------------- \n";
    x.pDown();
    cout << x; 
    cout << " ----------------------------------------------------------------------- \n";
}

void code202()
{
    system("clear");
    cout << x;
    cout << " ------------------------- && �������һ�� && -------------------------- \n";
    x.pUp();
    cout << x; 
    cout << " ----------------------------------------------------------------------- \n";
}

void code203()
{
    system("clear");
    cout << x;
    cout << " ------------------------- && �������һ�� && -------------------------- \n";
    x.pLeft();
    cout << x; 
    cout << " ----------------------------------------------------------------------- \n";
}

void code204()
{
    system("clear");
    cout << x;
    cout << " ------------------------- && �������һ�� && -------------------------- \n";
    x.pRight();
    cout << x; 
    cout << " ----------------------------------------------------------------------- \n";
}

void code205()
{
    system("clear");
    cout << x;
    cout << " --------------------- && ɾ����괦��ʼ���ַ��� && -------------------- \n";
    x.deleteText();

    cout << x;
    cout << " ----------------------------------------------------------------------- \n";
}

void code206()
{
    system("clear");
    cout << x;
    cout << " --------------------- && �ڹ��֮ǰ����һ���ı� && -------------------- \n";
    x.insertText();

    cout << x;
    cout << " ----------------------------------------------------------------------- \n";
}

void code207()
{
    system("clear");
    cout << x;
    cout << " ----------- && ��һ���ı��滻��괦��ʼ��len���ַ�˳�� && ----------- \n"; 
    x.replaceText();

    cout << x;
    cout << " ----------------------------------------------------------------------- \n";
}

void code208()
{
    system("clear");
    cout << x;
    cout << " ---------------------------- && ҳ������ && --------------------------- \n";
    x.setText();
    cout << " ----------------------------------------------------------------------- \n";
}

void code209()
{
    system("clear");
    cout << x;
    cout << " ---------------------------- && �����ı� && --------------------------- \n";
    cin >> x;
    cout << " ----------------------------------------------------------------------- \n";
}

void menu()
{
    cout << " ----------------------- && ����˳�򴮵Ĳ��� && ------------------------ \n";
    cout << "    1. ��˳�򴮵ĳ���\n"
         << "    2. �ж�˳���Ƿ�Ϊ��\n"
         << "    3. ȡ˳�򴮵��Ӵ�\n"
         << "    4. �ڵ� i ���ַ�ǰ������һ��˳��\n"
         << "    5. ɾ���ӵ� i ���ַ��𳤶�Ϊ len ���Ӵ�\n"
         << "    6. �ж��Ƿ���� SqString ˳�� == C++String˳��\n"
         << "    7. �ж��Ƿ���� SqString ˳�� == SqString˳��\n"
         << "    8. �ӷ����� SqString ˳�� + C++String˳��\n"
         << "    9. �ӷ����� SqString ˳�� + SqString˳��\n"
         << "   10. ��������ƥ��(�л��ݲ���)\n"
         << "   11. ��ģʽ���� next ����\n"
         << "   12. ģʽƥ��(�޻���KMP��������)\n"
         << "   13. ��ֵ���� SqString ˳�� = C++String ˳��\n"
         << "   14. ��ֵ���� SqString ˳�� = SqString ˳��\n"
         << "   15. ��˳���ÿ�\n"
         << "   16. �������˳��(СдӢ����ĸ)\n"
         << "   17. �� C++String ˳�򴮳�ʼ��һ��˳��(���ÿ�����ʼ�����캯��)\n"
         << "   18. �� SqString ˳�򴮳�ʼ��һ��˳��(���ÿ�����ʼ�����캯��)\n"
         << "   19. ����˳��\n"
         << "   20. �򵥵��ı��༭��(˳�򴮵�Ӧ��)\n";
    cout << " ����. ���� " << endl;
    cout << " ----------------------------------------------------------------------- \n";
}
