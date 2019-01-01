#include <stdio.h>
#include <stdlib.h>

typedef float DataType;
//栈结点
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

float calEsp(char str[]){
	LSNode *myStack;
	LSNodeInitiate(&myStack);
	char ch;
	float num1,num2,result;
	char buffer[10];
	int i = 0,j = 0;
	ch = str[j];
	j++;
	while(ch != '#'){
		while(ch >= '0' && ch <= '9'){
			buffer[i] = ch;
			i++;
			buffer[i] = '\0';
			ch = str[j];
			j++;//下一个字符
		}
		if (ch == ' ' && i != 0)
		{
			float temp = atof(buffer);
			LSNodePush(myStack,temp);
			i = 0;
		}
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			LSNodePop(myStack,&num1);
			LSNodePop(myStack,&num2);
		}
		switch(ch){
			case '+':
			result = num2 + num1;
			printf("%.1f + %.1f = %.1f\n",num2,num1,result);
			LSNodePush(myStack,result);
			break;
			case '-':
			result = num2 - num1;
			printf("%.1f - %.1f = %.1f\n",num2,num1,result);
			LSNodePush(myStack,result);
			break;
			case '*':
			result = num2 * num1;
			printf("%.1f * %.1f = %.1f\n",num2,num1,result);
			LSNodePush(myStack,result);
			break;
			case '/':
			result = num2 / num1;
			printf("%.1f / %.1f = %.1f\n",num2,num1,result);
			LSNodePush(myStack,result);
			break;
		}
		ch = str[j];
		j++;
	}
	LSNodePop(myStack,&result);
	return result;
}
int main(int argc, char const *argv[])
{
	//(2*(12+1)-2)/2    result = 12
	char esp[] = "2 12 1 + * 2 - 2 / #";
	printf("result = %.1f\n",calEsp(esp));
	return 0;
}