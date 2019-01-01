#ifndef LINKQUEUE_H
#define LINKQUEUE_H

typedef int DataType;
//队列结点
typedef struct node
{
	DataType data;
	struct node *next;
}LQNode;
//链式队列
typedef struct 
{
	LQNode *front;
	LQNode *rear;
}LQueue;

int initLQueue(LQueue *LQ);
int LQNotEmpty(LQueue LQ);
int LQAppend(LQueue *LQ,DataType d);
int LQDelete(LQueue *LQ,DataType *d);
int getFront(LQueue LQ);
int getQueueLength(LQueue LQ);

#endif