/*************************************************************************
    > File Name: calculate.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Fri 23 Nov 2018 11:03:46 AM CST
 ************************************************************************/

#ifndef _CALCULATE_H
#define _CALCULATE_H

// + .... 0 1..9 1 others -1

int isOpMember(char ch)
{
	if('0' <= ch && ch <= '9')
		return 1;
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '\0')
		return 0;
	return -1;
}

//+ - * / ( ) \0 0-6
int charToint(char p)
{
	switch(p)
	{
		case '+' : return 0;
		case '-' : return 1;
		case '*' : return 2;
		case '/' : return 3;
		case '(' : return 4;
		case ')' : return 5;
		case '\0': return 6;
		default: return 7; 
	}
}

//p before q
int comparecalchar(char p, char q)
{
	int CmpOut[7][7] ={{1, 1, 1, -1, -1, -1, 1},
					   {1, 1, 1, -1, -1, -1, 1},
					   {1, 1, 1, 1, -1, 1, 1},
					   {1, 1, 1, 1, -1, 1, 1},
					   {-1, -1, -1, -1, -1, 0, 0},
					   {1, 1, 1, 1, 2, 1, 1},
					   {-1, -1, -1, -1, -1, 2, 0}
						};
	int i, j;
	i = charToint(p);
	j = charToint(q);
	return CmpOut[i][j];


}

//midS and suffixS is array 
void transform(char *midS, char *suffixS)
{
	int i = 0;
	int j = 0;
	char ch = midS[0];
	SqStack<char> S;
	char op;
	S.push('\0');
	while(!S.isEmpty())
	{
		if(isOpMember(ch) == -1)
		{
			cout << "error expression \n";
			return;
		}
		else if(isOpMember(ch))
		{
			if(i > 0 && !isOpMember(suffixS[i-1]))
				suffixS[i++] = ' ';
			suffixS[i++] = ch;
		}
		else
		{
			if(i > 0 && suffixS[i-1] != ' ')
				suffixS[i++] = ' ';
			switch(ch)
			{	
				case '(' : S.push(ch);
				break;
				case ')' : S.pop(op);
				while(op != '(')
				{
					suffixS[i++] = op;
					suffixS[i++] = ' ';
					S.pop(op);
				}
				--i;
				break;
				
				default:
					while(S.getTop(op))
					{
						if(comparecalchar(op, ch) == 1 || comparecalchar(op, ch) == 0)
						{
							suffixS[i++] = op;
							suffixS[i++] = ' ';
						}
						else
							break;
						S.pop(op);
					}
					if(ch != '\0')
						S.push(ch);
					break;
			}//switch
		}//else
		if(ch != '\0')
			ch = midS[++j];
	}//while
	suffixS[i] = '\0';
}

double calculate(double a, char ch, double b)
{
	switch(ch)
	{
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/':	return a/b;
		default :return -1;
	}
}
double calculateall(char *suffixS)
{
	int i = 0;
	char ch = suffixS[i];
	double x;
	SqStack<double> S;
	double a, b;
	while(ch != '\0')
	{
		if(isOpMember(ch) == 1)
		{
			x = 0;
			while(isOpMember(ch) == 1)
			{
				x = 10*x + (ch - '0');
				ch = suffixS[++i];
			}
			S.push(x);
		}
		else if(!isOpMember(ch))
		{
			S.pop(b);
			S.pop(a);
			S.push(calculate(a, ch, b));
		}
		ch = suffixS[++i];
	}
	S.pop(x);
	return x;
}
#endif
