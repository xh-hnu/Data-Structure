#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	long num;
	char name[10];	
}DataType;

typedef struct sNode
{
	DataType data;
	struct sNode *next;
}LSNode;

//初始化空栈 动态申请内存空间 指向NULL ^
void LSNodeInitiate(LSNode **head){
	*head = (LSNode *)malloc(sizeof(LSNode));
	(*head) -> next = NULL;
}

//判断非空否
int LSNotEmpty(LSNode *head){
	if (head -> next == NULL)
	{
		return 0;
	}
	return 1;
}

//入栈 动态申请节点，插入栈顶
int LSNodePush(LSNode *head,DataType d){
	LSNode *p;
	p = (LSNode *)malloc(sizeof(LSNode));
	p -> data = d;
	p -> next = head -> next;
	head -> next = p;
	return 1;
}

//出栈 可释放内存空间，为什么要释放
//	因为链式栈的内存是运行时动态申请的，无法被自动回收，如果不释放，有可能内存泄漏
int LSNodePop(LSNode * head,DataType *d){
	if (LSNotEmpty(head))
	{
		LSNode *p;
		p = head -> next;
		*d = p -> data;
		head -> next = p -> next;
		free(p);
		return 1;
	}else{
		printf("The LinkStack is Empty\n");
		return 0;
	}
	
}

int main(int argc, char const *argv[])
{
	DataType x[6] = {{201501,"张三"},
					{201502,"李四"},
					{201503,"王五"},
					{201504,"赵六"},
					{201505,"许琪"},
					{201506,"方八"}};
	LSNode *head;
	DataType d;
	LSNodeInitiate(&head);
	for (int i = 0; i < sizeof(x) / sizeof(DataType); ++i)
	{
		LSNodePush(head,x[i]);
	}
	//利用栈倒序输出  栈 可改变顺序
	for (int i = 0; i < sizeof(x) / sizeof(DataType); ++i)
	{
		LSNodePop(head,&d);
		printf("%d %s\n",d.num,d.name);
	}
	return 0;
}