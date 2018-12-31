#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	long num;
	char name[10];
}DataType;
//数据结构
typedef struct Node
{
	DataType data;
	struct Node *next;
	struct Node *prior;
}DLNode;
//算法
//初始化一个空链表
void initDoubleList(DLNode **head){
	*head = (DLNode *)malloc(sizeof(DLNode));
	(*head) -> next = *head;
	(*head) -> prior = *head;
}

//插入数据 插入第0个数据和第i个数据(i > 0)的方法一致
int insertNode(DLNode *head,int i,DataType x){
	DLNode *p,*s;
	int j = 0;
	p = head -> next;
	while(p != head && j <= i){
		p = p -> next;
		j++;
	}
	if (j != i)
	{
		printf("position is invalid\n");
		return 0;
	}
	s = (DLNode *)malloc(sizeof(DLNode));//申请节点内存
	s -> data = x;
	s ->prior = p -> prior; //1
	p ->prior ->next = s;	//2
	s -> next = p;			//3		
	p -> prior = s;			//4
	return 1;
}

//打印双向表
void printDL(DLNode *head){
	DLNode *p;
	//判空
	if (head -> next == head && head -> prior == head)
	{
		printf("List is Empty\n");
		return;
	}
	p = head -> next;
	//不为空，先打印，再判断下一节点是否为头指针
	do{
		printf("% d %s\n",(p -> data).num,(p -> data).name);
		p = p ->next;
	}while(p != head);
}

int main(int argc, char const *argv[])
{
	DataType x[6] = {{201501,"张三"},
					{201502,"李四"},
					{201503,"王五"},
					{201504,"赵六"},
					{201505,"许琪"},
					{201506,"方八"}};
	DLNode *head;
	initDoubleList(&head);
	for (int i = 0; i < sizeof(x) / sizeof(DataType); ++i)
	{
		insertNode(head,i,x[i]);
	}
	printDL(head);
	return 0;
}