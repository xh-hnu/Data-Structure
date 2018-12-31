#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct 
{
	long num;
	char name[10];
}DataType;

typedef struct 
{
	DataType stack[MAXSIZE];
	int top;
}SeqStack;

//初始化栈
void stackInitiate(SeqStack *S){
	S -> top = 0;
}

//判断顺序栈非空否，非空返回1，否则返回0
int StackNotEmpty(SeqStack *S){
	if (S -> top <= 0)
	{
		return 0;
	}
	return 1;
}

//入栈
int StackPush(SeqStack *S,DataType d){
	if (S -> top >= MAXSIZE)
	{
		printf("The Stack is OverFlow\n");
		return 0;
	}
	S -> stack[S -> top] = d;
	S -> top++;
	return 1;
}

//出栈
int StackPop(SeqStack *S,DataType *d){
	if (S -> top <= 0)
	{
		printf("The Stack is Empty\n");
		return 0;
	}
	S -> top--;
	*d = S -> stack[S -> top];
	return 1;
}

//查看栈顶元素
int StackTop(SeqStack *S,DataType *d){
	if (S ->top <= 0)
	{
		printf("The Stack is Empty\n");
		return 0;
	}
	*d = S -> stack[S -> top - 1];
	return 1;
}

int main(int argc, char const *argv[])
{
	DataType x[6] = {{201501,"张三"},
					{201502,"李四"},
					{201503,"王五"},
					{201504,"赵六"},
					{201505,"许琪"},
					{201506,"方八"}};
	DataType d;
	SeqStack S;
	stackInitiate(&S);
	for (int i = 0; i < sizeof(x) / sizeof(DataType); ++i)
	{
		StackPush(&S,x[i]);
	}
	//利用栈倒序输出  栈 可改变顺序
	for (int i = 0; i < sizeof(x) / sizeof(DataType); ++i)
	{
		StackPop(&S,&d);
		printf("%d %s\n",d.num,d.name);
	}
	return 0;
}