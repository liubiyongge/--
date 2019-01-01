/*************************************************************************
    > File Name: Sort.h
    > Author: liubiyongge
    > Mail: liubiyongge@163.com
    > Created Time: Sun 30 Dec 2018 09:44:02 PM CST
 ************************************************************************/

#ifndef _SORT_H
#define _SORT_H

void insertSort(int *row, int n);
void print_R(int *row, int n);
void binaryInsertSort(int *row, int n);
void staticLinkSort(int *link, int n);

void staticLinkSort(Linkrow *link, int n)
{
	link[0].next = 1;
	int j;
	int pre;
	for(int i = 1; i < n; i++)
		link[i].next = 0;
	for(int i = 2; i < n; i++)
	{
		for(j = link[0].next; link[j].next != 0; j = link[j].next)
		{

			if(link[i].data < link[j].data)
				break;
			pre = j;
		}
		if(j == link[0].next)
		{
			link[i].next = j;
			link[0].next = i;
		}
		else if(j == 0)
		{
			link[pre].next = i;
		}
		else
		{
			link[i].next = link[pre].next;
			link[pre].next = i;
		}

	}
}


void print_R(int *row, int n)
{
	for(int i = 0; i < n; i++)
		cout << row[i].data << " ";
	cout << endl;
	
	for(int i = 0; i < n; i++)
		cout << row[i].next << " ";

	cout << endl;
}


//直接插入排序
void insertSort(int *row, int n)
{
	int index_data;
	int index, j;
	for(int i = 1; i < n; i++)
	{
		index = i;
		index_data = row[index];
		for(j = i-1; j >= 0; j--)
		{
			if(index_data > row[j])
				break;
			row[j+1] = row[j];
		}

		row[j+1] = index_data;
	}
}

void binaryInsertSort(int *row, int n)
{
	int low, high, mid;
	int key;
	for(int i = 1; i < n; i++)
	{
		key = row[i];
		low = 0;
		high = i - 1;
		while(low <= high)
		{
			mid = (low + high)/2;
			if(key >= row[mid])
				low = mid + 1 ;
			else
				high = mid - 1;
		}
		//[high+1]--[i-1]３后移动一位
		for(int j = i - 1; j > high; j--)
			row[j+1] = row[j];
		row[high+1] = key;

	}

}

#endif

