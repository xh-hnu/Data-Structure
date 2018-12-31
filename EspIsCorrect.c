#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef char DataType;

typedef struct 
{
	DataType data[MAXSIZE];
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
	S -> data[S -> top] = d;
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
	*d = S -> data[S -> top];
	return 1;
}

//查看栈顶元素
int StackTop(SeqStack *S,DataType *d){
	if (S ->top <= 0)
	{
		printf("The Stack is Empty\n");
		return 0;
	}
	*d = S -> data[S -> top - 1];
	return 1;
}

int EspIsCorrect(char esp[],int n){
	SeqStack myStack;
	stackInitiate(&myStack);
	char c;
	for (int i = 0; i < n; ++i)
	{
		if (esp[i] == '(' || esp[i] == '[' || esp[i] == '{')
		{
			StackPush(&myStack,esp[i]);
		}else if (esp[i] == ')' && StackNotEmpty(&myStack) && StackTop(&myStack,&c) && c == '(')
		{
			StackPop(&myStack,&c);
		}else if (esp[i] == ')' && StackNotEmpty(&myStack) && StackTop(&myStack,&c) && c != '(')
		{
			printf("左右括号配对次序不正确\n");
			return 0;
		}else if (esp[i] == ']' && StackNotEmpty(&myStack) && StackTop(&myStack,&c) && c == '[')
		{
			StackPop(&myStack,&c);
		}else if (esp[i] == ']' && StackNotEmpty(&myStack) && StackTop(&myStack,&c) && c != '[')
		{
			printf("左右括号配对次序不正确\n");
			return 0;
		}else if (esp[i] == '}' && StackNotEmpty(&myStack) && StackTop(&myStack,&c) && c == '{')
		{
			StackPop(&myStack,&c);
		}else if (esp[i] == '}' && StackNotEmpty(&myStack) && StackTop(&myStack,&c) && c != '{')
		{
			printf("左右括号配对次序不正确\n");
			return 0;
		}else if ((esp[i] == ')' || esp[i] == ']' || esp[i] == '}') && !StackNotEmpty(&myStack))
		{
			printf("右括号多于左括号\n");
			return 0;
		}
	}
	if (StackNotEmpty(&myStack))
		{
			printf("左括号多于右括号\n");
			return 0;
		}else{
			printf("匹配正确\n");
			return 1;
		}
}

int main(int argc, char const *argv[])
{
	char a[] = "(())abc{[]()}";
	char b[] = "(()))abc{[]}";
	char c[] = "(()()abc{[]}";
	char d[] = "(())abc{[]}";
	char e[] = "(()}abc{[]}";
	int na = strlen(a);
	int nb = strlen(b);
	int nc = strlen(c);
	int nd = strlen(d);
	int ne = strlen(e);
	EspIsCorrect(a,na);
	EspIsCorrect(b,nb);
	EspIsCorrect(c,nc);
	EspIsCorrect(d,nd);
	EspIsCorrect(e,ne);
	return 0;
}