/*************************************************************************
    > File Name: maze.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Fri 23 Nov 2018 04:13:45 PM CST
 ************************************************************************/

#ifndef _MAZE_H
#define _MAZE_H

#define RowSize 10
#define ColSize 10
typedef int MapType[RowSize][ColSize];
class pos
{
public:
	void read(istream &in);
	void display(ostream &out) const;
public:
	int x;
	int y;
};

void pos::read(istream &in)
{

	cout << "x:";
	in >> x;
	cout << "y:";
	in >> y;
}


istream & operator >>(istream &in, pos &pL)
{
	pL.read(in);
	return in;
}

void pos::display(ostream &out) const
{
	out << "(" << x << "," << y << ")";
}

ostream & operator << (ostream &out, const pos &L)
{
	L.display(out);
	return out;
}

class Ipos
{
public:
	pos position;
	int d;
};

void printMaze(MapType maze)
{
	cout << "   ";
	for(int i=0 ;i < ColSize; i++)
		cout << "[" << i << "]";
	cout << endl;

	for (int i = 0; i < RowSize; ++i)
	{
		cout << "[" << i << "]";
		for (int j = 0; j < ColSize; ++j)
		{
			cout << setw(3) << maze[i][j];
		}
		printf("\n");
	}
}

int pass(pos curpos, MapType mazepath)
{
	return !mazepath[curpos.x][curpos.y];
}

pos NextPos(pos curpos, int direction)// 1 rigth 2 down 3 left 4 up
{	
	if(direction%2){
		curpos.x = curpos.x - direction + 2;
	}
	else{
		curpos.y = curpos.y - direction + 3;
	}
	return curpos;

}

int pathMaze(MapType maze, pos start, pos end)
{
	MapType mazepath;
	for (int i = 0; i < RowSize; ++i)
	{
		for (int j = 0; j < ColSize; ++j)
		{
			mazepath[i][j] = maze[i][j];
		}
	}
	pos curpos = start;
	SqStack<Ipos> S;
	Ipos e;
	do{
	if(pass(curpos, mazepath)){
			//if current positon can pass(=1)
			e.d = 1;// 1 is right
			e.position = curpos;
			S.push(e);
			mazepath[curpos.x][curpos.y] = 1;
			//mazepath[curpos.x][curpos.y] = 2;	//have arrive set 1
			if(curpos.x == end.x && curpos.y == end.y)
			{
				while(!S.isEmpty())
				{
					S.pop(e);
					curpos = e.position;
					mazepath[curpos.x][curpos.y] = 2;
				}
				cout << "用２表示通路\n";
				printMaze(mazepath);
				return (TRUE);
			}
			curpos = NextPos(curpos, 1);//right
		}
		else{

			if(!S.isEmpty()){
				S.pop(e);
				while(e.d == 4 && !S.isEmpty() ){
					
					mazepath[e.position.x][e.position.y] = 1;S.pop(e);//mark not pass and return one step
				}
			if(e.d < 4){
				e.d++; S.push(e);//change direction
				curpos = NextPos(e.position, e.d);
				}
			}
		}
	}while(!S.isEmpty());
	return FALSE;

}

void test1_1(MapType maze)
{
	cout << "**走迷宫**\n";

	pos pos1;
	pos pos2;
	cout << "** 走迷宫**\n";
	cout << "请输入起始坐标\n";
	cin >> pos1;
	cout << "请输入终点坐标\n";
	cin >> pos2;
	cout << "从起点" << pos1 << "到终点" << pos2<< endl;
	if(!pathMaze( maze, pos1, pos2))
		cout << "没有通路" << endl;


	cout << "*******************88\n";
}
void test2_1(MapType maze)
{
	cout << "**把一个迷宫赋值给另一个迷宫**\n";
	cout << "把当前迷宫赋值给另一个迷宫" << endl;
	MapType maze1;
	for (int i = 0; i < RowSize; ++i)
	{
		for (int j = 0; j < ColSize; ++j)
		{
			maze1[i][j] = maze[i][j];
		}
	}
	printMaze(maze1);
	cout << "*******************88\n";
}


void test3_1(MapType maze)
{
	cout << "**随机生成迷宫**\n";
	for (int i = 0; i < RowSize; ++i)
	{
		for (int j = 0; j < ColSize; ++j)
		{
			maze[i][j] = rand()%2;
		}
	}
	cout << "随机生成的迷宫为:\n";
	printMaze(maze);
	cout << "*******************88\n";
}


void test4_1(MapType maze)
{
	cout << "****\n";
		for (int i = 0; i < RowSize; ++i)
	{
		for (int j = 0; j < ColSize; ++j)
		{
			cout << "("<<i << "," << j <<"):";
			cin >> maze[i][j];
		}
	}
	cout << "你输入的迷宫为\n";
	printMaze(maze);
	cout << "*******************88\n";
}

#endif
