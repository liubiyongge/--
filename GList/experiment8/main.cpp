#include "test.h"


int main()
{

	GList GL;
	GList head;
	cin >> GL;

	int choose;		//存放switch的实参
	char ContinueChar = 'N';		//判断是否继续

	while (1)
	{
		system("cls");		//先清屏
		cout << endl;
		cout << "\t*************测 试 广 义 表 的 操 作 ***************" << endl << endl;

		cout << "\t1. 求广义表的深度" << endl;
		cout << "\t2. 广义表的赋值运算" << endl;
		cout << "\t3. 求广义表的长度" << endl;
		cout << "\t4. 判断广义表是否为空" << endl;
		cout << "\t5. 取广义表的表头" << endl;
		cout << "\t6. 取广义表的表尾" << endl;
		cout << "\t7. 删除广义表的表头" << endl;
		cout << "\t8. 插入一个广义表作为广义表的表头" << endl;
		cout << "\t9. 用已有的广义表初始化另一个广义表" << endl;
		cout << "\t10.以字符串形式输出广义表" << endl;
		

		cout << "\t///////////////////////////////////////////////////" << endl << endl;
		displayGList(GL);
		cout << "\t///////////////////////////////////////////////////" << endl << endl;

		cout << "\t请输入你要操作的代码（1-10）号码：";
		cin >> choose;
		if (choose > 0 && choose < 11)		//判断choose 是否合法
		{
			system("cls");
			displayGList(GL);
		}

		switch (choose)
		{
		case 1:
			ex8_1_1(GL, ContinueChar);
			break;
		case 2:
			ex8_1_2(GL, ContinueChar);
			break;
		case 3:
			ex8_1_3(GL, ContinueChar);
			break;
		case 4:
			ex8_1_4(GL, ContinueChar);
			break;
		case 5:
			ex8_1_5(GL, ContinueChar);
			break;
		case 6:
			ex8_1_6(GL, ContinueChar);
			break;
		case 7:
			ex8_1_7(GL, ContinueChar, head);
			break;
		case 8:
			ex8_1_8(GL, ContinueChar, head);
			break;
		case 9:
			ex8_1_9(GL, ContinueChar);
			break;
		case 10:
			ex8_1_10(GL, ContinueChar);
			break;


		default:
			cout << "\t你选择了结束。" << endl << endl;
			return 0;
		}

		if (ContinueChar == 'N' || ContinueChar == 'n')
			break;
	}

	return 0;



}