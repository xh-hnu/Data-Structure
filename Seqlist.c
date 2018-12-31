#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 40

typedef struct student
{
	int num;
	char name[10];
	
}datatype;

typedef struct 
{
	datatype data[MAXSIZE];
	int len;
}SeqList;

void InitList(SeqList *L){
	L -> len = 0;
}

int insert(SeqList *L,int i,datatype d){
	if ((*L).len > MAXSIZE)
	{
		printf("the list is overflow\n");
		return 0;
	}
	else if (i > ((*L).len + 1) || i < 0)
	{
		printf("position is incorrect\n");
		return 0;
	}
	else {
		//从后向前依次后移数据，空出要插入数据的位置
		for (int j = (*L).len; j > i; j--)
		{
			 (*L).data[j] = (*L).data[j-1];
		}
		(*L).data[i] = d;
		(*L).len ++;
		return 1;
	}
}

int getNode(SeqList L, int i,datatype *x){
	if (i < 0 || i > L.len - 1)
	{
		printf("i is invalid\n");
		return 0;
	}
	*x = L.data[i];
	return 1;
}

int getLength(SeqList L){
	return L.len;
}

int main(int argc, char const *argv[])
{
	SeqList myList;
	int i;
	datatype x[6] = {{201501,"张三"},
					{201502,"李四"},
					{201503,"王五"},
					{201504,"赵六"},
					{201505,"许琪"},
					{201506,"方八"}};
	datatype s;
	InitList(&myList);
	insert(&myList,0,x[0]);
	insert(&myList,1,x[1]);
	insert(&myList,2,x[2]);
	for (int i = 0; i < getLength(myList); ++i)
	{
		getNode(myList,i,&s);
		printf("%d %s\n",s.num,s.name);
	}
}