/*************************************************************************
    > File Name: MGraph.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Sun 30 Dec 2018 08:44:17 AM CST
 ************************************************************************/

#ifndef _MGRAPH_H
#define _MGRAPH_H
#define INFINITY 20000

template <typename T>
class MGraph
{
public:
	void input();
	void printMGraph();
	void kruskal();
	void Prim();
	// void Dijkstra();
	//*******auto call**************************
	MGraph();
	~MGraph();

private:
	int getSerialNumber(char ch);
	int find(int set[], int f)
	{
		while(set[f] > -1)
			f = set[f];
		return f;
	}
	int minarc(int *shortest);
private:
	int kind;
	int vexNum;
	T *vexs;
	int arcNum;
	int *arcs;
	
};

template<typename T>
int MGraph<T>::minarc(int *shortest)
{
	int min = shortest[0];
	int min_i = 0;
	for(int i = 1; i < vexNum; i++)
	{
		if(min > shortest[i])
		{
			min = shortest[i];
			min_i = i;
		}
	}
	return min_i;

}

/*未完
template <typename T>
void MGraph<T>::Dijkstra()
{
	char ch;
	int begin;
	int step = 1;
	int shortest[vexNum];//存储到每个顶点的最短路径长度
	int path[vexNum][vexNum] = {0};	

	int final[vexNum] = {0};
	int min_i;
	cout << "请输入某顶点，求到其他所有顶点的最短路径:";
	cin >> ch;
	begin = getSerialNumber(ch);
	for(int i = 0; i < vexNum; i++)
	{
		shortest[i] = arcs[begin * vexNum + i];
		if(arcs[begin * vexNum + i] > 0)
		{
			path[i][begin] = step;
		}
	}
	shortest[begin] = 0;
	path[begin][begin] = step;

	for(int i = 1; i < vexNum -1; i++)
	{
		min_i = minarc(shortest);
		if(!path[min_i][min_i])
			path[min_i][min_i] = ++step;
		else
			step = path[min_i][min_i];
	}


}
*/

template <typename T>
void MGraph<T>::kruskal()
{
	//set记录父亲节点才能实现
	struct cord 
	{
		int begin;
		int end;
		int cost;
	};
	cord edges[arcNum];
	int set[vexNum];//辅助数组set
	for(int i = 0; i < vexNum; i++) set[i] = -1;
	int k;
	int min_shortest;
	int begin_set, end_set;
	for(k = 0; k < arcNum; ++k)
		edges[k].cost = INFINITY;

	//按由小到大的顺序记录边
	for(int i = 0;i < vexNum; i++)
	{
		for(int j = i+1; j < vexNum; ++j)
		{
			if(arcs[i * vexNum + j] != -1)
			{
				for(k = 0; k < arcNum;++k)
				{	
					if(arcs[i * vexNum + j] < edges[k].cost)
					{
						break;
					}	
				}	
				min_shortest = k;
				for(;edges[k].cost != INFINITY; ++k);
				for(;k>min_shortest;--k)
				{
					edges[k].begin = edges[k-1].begin;
					edges[k].end = edges[k-1].end;
					edges[k].cost = edges[k-1].cost;
				}
				edges[min_shortest].begin = i;
				edges[min_shortest].end = j;
				edges[min_shortest].cost = arcs[i * vexNum +j];
			}
		}

	}
	k = 0;
	for(int i = 0; i < arcNum; ++i)
	{
		begin_set = find(set, edges[i].begin);
		end_set = find(set, edges[i].end);
		if(begin_set != end_set)
		{
			set[edges[i].end] = edges[i].begin;
		}
	}
	for(int i = 0; i < vexNum; i++)
		cout << set[i];
	cout << endl;

}

template <typename T>
void MGraph<T>::Prim()
{
	char ch;
	int m;
	int min, th;
	int parents[vexNum];
	for(int i = 0;i < vexNum; i++)
		parents[i] = -1;
	int lowcost[vexNum];//辅助数组
	cout << "选择一个顶点作为根节点:";
	cin >> ch;
	m = getSerialNumber(ch);
	parents[m] = -1;
	lowcost[m] = 0;//-1代表无穷大
	for(int i = 0; i < vexNum; i++)
	{
		parents[i] = m;
		lowcost[i] = arcs[m * vexNum + i];
	}
	parents[m] = -1;
	lowcost[m] = 0;//为零表示出列

	for(int i = 0; i < vexNum -1; i++)
	{
		min = -1;	
		for(int j = 0; j < vexNum; j++)
		{
			if(lowcost[j] > 0 && (min == -1 || lowcost[j] < min))
			{
				min = lowcost[j];
				th = j;
			}
		}
		lowcost[th] = 0;
		for(int j = 0; j < vexNum; j++)
		{
			if(arcs[th * vexNum + j] > 0 && (lowcost[j] == -1 || arcs[th * vexNum + j] < lowcost[j]))
			{
				lowcost[j] = arcs[th * vexNum + j];
				parents[j] = th;
			}
		}
	}
	
	for(int j = 0; j < vexNum; j++)
		cout << parents[j];
	cout << endl;
}

template <typename T>
void MGraph<T>::printMGraph()
{
	cout << "    ";
	for(int i = 0; i < vexNum; i++)
	{
		cout << "[ " << i + 1 << "]";
	}
	cout << endl;
	for(int i = 0; i < vexNum; i++)
	{
		cout << "[ " << i + 1 << "]";
		for(int j = 0; j < vexNum; j++)
			cout << setw(4) << arcs[i * vexNum + j];
		cout << endl;
	}
}

template <typename T>
int MGraph<T>::getSerialNumber(char ch)
{
	int i;
	for(i = 0; i < vexNum; i++)
	{
		if(ch == vexs[i])
			break;
	}
	return i;
}

template <typename T>
void MGraph<T>::input()
{
	char vex[3];//输入的边
	int m, n;//俩个顶点
	cout << "\t1.无向无权图　\n \t2.无向有权图　\n \t3.有向无权图　\n \t4.有向有权图\n";
	cout << "请输入图的种类(1-4):";
	cin >> kind;
	cout << "请输入顶点个数:";
	cin >> vexNum;
	vexs = (T *)malloc(sizeof(T) * vexNum);
	for(int i = 0; i < vexNum; i++)
	{
		cout << "请输入第" << i + 1<< "个顶点:";
		cin >> vexs[i];
	}
	arcs = (int *)malloc(sizeof(int) * vexNum * vexNum);
	for(int i = 0; i < vexNum * vexNum; i++)
	{
		arcs[i] = -1;
		if(i/vexNum == i%vexNum)
		{
			if(kind == 2 || kind == 4)
			{
				arcs[i] = 0;
			}
			else
			{
				arcs[i] = 1;
			}
		}

	}
	cout << "请输入边的条数:";
	cin >> arcNum;
	for(int i = 0; i < arcNum; i++)
	{
		cout << "请输入第" << i+1 << "条边:";
		cin >> vex;
		m = getSerialNumber(vex[0]);
		n = getSerialNumber(vex[1]);

		if(kind == 4)
		{
			cout << "权值:";
			cin >> arcs[m * vexNum + n]; 
		}
		else if(kind == 3)
		{
			arcs[m * vexNum + n] = 1;
		}
		else if(kind == 2)
		{
			cout << "权值:";
			cin >> arcs[m * vexNum + n];
			arcs[n * vexNum + m] = arcs[m * vexNum + n];
		}
		else
		{
			arcs[m * vexNum + n] = 1;
			arcs[n * vexNum + m] = arcs[m * vexNum + n];
		}
	}
}





// *******************auto call***********************
template <typename T>
MGraph<T>::MGraph()
{
	kind = -1;
	vexNum = 0;
	vexs = NULL;
	arcNum = 0;
	arcs = NULL;
}

template <typename T>
MGraph<T>::~MGraph()
{
	delete vexs;
	delete arcs;
}


#endif
