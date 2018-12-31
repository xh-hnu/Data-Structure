#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // isdigit(char c)函数

/*
	加减乘除带括号的中缀表达式转换成后缀表达式
	使用栈结构实现
*/

typedef char DataType;

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

int LSNodeTop(LSNode *head,DataType *d){
	if (LSNotEmpty(head))
	{
		*d = head -> next -> data;
		return 1;
	}
	return 0;
}

void DestroyStack(LSNode *head){
	LSNode *p,*q;
	p = head;
	while(p != NULL){
		q = p;
		p = p -> next;
		free(q);
	}
}

int PostEsp(char str[]){
	LSNode *head;
	int x;
	char top;
	LSNodeInitiate(&head);
	LSNodePush(head,'#');//先把 # 入栈
	for (int i = 0; str[i] != '#'; i++)
	{
		if (isdigit(str[i])){
		//数字
			x = (int) (str[i] - 48);
			printf("%d",x);
		}else {
		//操作符 根据优先级做判断
			if ((str[i] == '+' || str[i] == '-') && LSNodeTop(head,&top))
			{//扫描到 + -，堆栈非空
				while(top == '+' || top == '-' || top == '*' || top == '/' || top == ')'){
				//栈顶为 + - * /，出栈，再读一次栈顶
					LSNodePop(head,&top);
					printf(" %c",top);
					LSNodeTop(head,&top);
				}
				LSNodePush(head,str[i]);
				LSNodeTop(head,&top);
				printf(" ");
			}else if ((str[i] == '*' || str[i] == '/') && LSNodeTop(head,&top) || top == ')')
			{//扫描到 * / ，堆栈非空
				while(top == '*' || top == '/'){
					LSNodePop(head,&top);
					printf(" %c",top);
					LSNodeTop(head,&top);
				}
				LSNodePush(head,str[i]);
				printf(" ");
			}else if (str[i] == ')' && LSNodeTop(head,&top))
			{//扫描到 ） ，堆栈非空
				while(top == '+' || top == '-' || top == '*' || top == '/' || top == ')'){
					LSNodePop(head,&top);
					printf(" %c",top);
					LSNodeTop(head,&top);
				}
				if (top == '(')
				{
					LSNodePop(head,&top);
				}
			}else if (str[i] == '(' && LSNodeTop(head,&top))
			{
				LSNodePush(head,str[i]);
				printf(" ");
			}
		}
	}
	while(LSNodePop(head,&top) && top != '#'){
		printf(" %c",top);
	}
	DestroyStack(head);
}

int main(int argc, char const *argv[])
{
	//(2*(12+1)-2)/2
	char esp[] = "(2*(12+1)-2)/2#";
	PostEsp(esp);
	return 0;
}