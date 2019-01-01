#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

/*
	队列需要申请内存空间，头指针，尾指针指向队头 和 队尾
*/

int initLQueue(LQueue *LQ){
	if (LQ -> front != NULL)
	{
		LQ -> rear = NULL;
		LQ -> front = NULL;
		return 1;
	}
	return 0;
}
//判断非空否
int LQNotEmpty(LQueue LQ){
	if (LQ.front == NULL)
	{
		return 0;
	}
	return 1;
}

int LQAppend(LQueue *LQ,DataType d){
	//申请结点内存空间
	LQNode *new_node;
	new_node = (LQNode *)malloc(sizeof(LQNode));
	if (!new_node)
	{
		printf("LQNode malloc error\n");
		return 0;
	}
	new_node -> data = d;
	new_node -> next = NULL;
    if (LQ -> rear != NULL)//如果队列非空，队尾指向新节点
    {
    	LQ -> rear -> next = new_node;
    }
    LQ -> rear = new_node;//尾指针指向队尾
    if (LQ -> front == NULL)//如果队列为空，头指针指向新节点
    {
    	LQ -> front = new_node;
    }
	return new_node -> data;
}

int LQDelete(LQueue *LQ,DataType *d){
	if (LQNotEmpty(*LQ))//非空
	{
		LQNode *p;
		*d = LQ -> front ->data;//获取数据
		p = LQ -> front;
		LQ -> front = p -> next;//头指针指向对头的下一个结点
		free(p);//释放结点内存
	}
	return 0;
}

int getFront(LQueue LQ){
	return LQ.front -> data;
}

int getQueueLength(LQueue LQ){
	int count = 0;
	LQNode *p;
	p = LQ.front;
	while(p != NULL){
		count++;
		p = p -> next;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	DataType data[4] = {3,4,5,6};
	DataType d;
	LQueue lq;
	initLQueue(&lq);
	//入队
	for (int i = 0; i < sizeof(data) / sizeof(DataType); ++i)
	{
		LQAppend(&lq,data[i]);
	}
	//队长
	printf("队列长度：%d\n",getQueueLength(lq));
	//队头
	printf("队头元素：%d\n",getFront(lq));
	//出队
	printf("出队序列：");
	for (int i = 0; i < 4; ++i)
	{
		LQDelete(&lq,&d);
		printf("%d ",d);
	}
	return 0;
}