#include <stdio.h>
#include <stdlib.h>//包含 malloc 函数

typedef struct 
{
	long num;
	char name[10];
}DataType;

typedef struct Node
{
	DataType data;
	struct Node *next;	
}LLNode;

//初始化
void initList(LLNode **head){
	//因为申请内存返回内存地址的指针，所以所以赋值给head头指针，而要改变head的值，需要传入头指针的地址
	//二级指针，改变函数外头指针的值
	*head = (LLNode *)malloc(sizeof(LLNode));
	(*head) -> next = NULL;
}

//获取长度
int getLength(LLNode *head){
	LLNode *p = head;
	int size = 0;
	while(p -> next != NULL){
		p = p -> next;
		size++;
	}
	return size;
}

//插入数据，传入头指针
int insertNode(LLNode *head,int i,DataType x){
	LLNode *p,*q;
	p = head;
	int j = 0;
	//使p指针指向要插入位置的前一个元素
	while(p -> next != NULL && j < i){
		j++;
		p = p -> next;
	}
	if (j != i)
	{
		printf("position is invalid\n");
		return 0;
	}
	q = (LLNode *)malloc(sizeof(LLNode));//申请内存
	q -> data = x;//新节点q 的数据
	q ->next = p -> next; 
	p -> next = q;//插入节点
	return 1;
}

//获取节点数据
int getNode(LLNode *head,int i,DataType *x){
	LLNode *p;
	int j = 0;
	p = head;
	while(p -> next != NULL && j < i){
		p = p -> next;
		j++;
	}
	if (j != i)
	{
		printf("position is invalid\n");
		return 0;
	}
	*x = p -> data;
	return 1;
}

void printLinkList(LLNode * head){
	DataType s;
	if (getLength(head) == 0)
	{
		printf("List is Empty\n");
	}
	for (int i = 1; i <= getLength(head); ++i)
	{
		//这里的i是位置 位置 = 索引 + 1
		getNode(head,i,&s);
		printf("%d %s\n",s.num,s.name);
	}
}

//撤销列表，释放内存
void destroyList(LLNode **head){
	LLNode *p,*q;
	p = *head;//指向第一个元素
	while(p != NULL){
		q = p;
		p = p -> next;//指向下一个元素
		free(q);//释放上一个内存空间
	}
	(*head) -> next = NULL;//释放头指针
}

int main(int argc, char const *argv[])
{
	DataType x[6] = {{201501,"张三"},
					{201502,"李四"},
					{201503,"王五"},
					{201504,"赵六"},
					{201505,"许琪"},
					{201506,"方八"}};
	LLNode *head;
	initList(&head);//初始化
	for (int i = 0; i < sizeof(x) / sizeof(DataType); ++i)
	{
		//这里的i是索引 索引 = 位置 - 1
		insertNode(head,i,x[i]);//插入数据
	}
	printf("%d\n",getLength(head));//查询长度
	printLinkList(head);
	destroyList(&head);//这里我其实是清空操作
	printLinkList(head);
	return 0;
}