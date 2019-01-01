#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

/*
	gcc编译时，需要将LinkQueue.c 的main函数注释掉
	gcc -fexec-charset=GBK linkqueue.c radixsort.c -o radixSort
*/

//基数排序
//当关键字为整数形式时，基数排序非常高效
//当有两个关键字相同时，排序之后的相对位置不变
//所以是一种稳定的排序算法
void RadioSort(DataType a[],int n,int m,int d){//m位d进制
	LQueue tub[d];
	int k;
	int power = 1;
	//tub = (LQueue *)malloc(sizeof(LQueue) * d);//申请一个动态链表数组
	for (int i = 0; i < d; i++)
	{
		initLQueue(&tub[i]);//d个队列进行初始化
	}
	//m次放入 和 收回
	for (int i = 0; i < m; i++)
	{
		if (i == 0)
		{
			power = 1;
		}else{
			power = power * d;
		}
		//根据k值把n个元素放入不同的桶
		for (int j = 0; j < n; j++)
		{
			k = a[j] / power - d * (a[j] / (power * d));//计算k值
			//printf("k = %d\n", k);
			LQAppend(&tub[k],a[j]);//将元素放入对应的桶队列中
		}
		//顺序回收d个队列中的数据到数组中
		k = 0;
		for (int j = 0; j < d; j++)
		{
			while(LQNotEmpty(tub[j])){
				LQDelete(&tub[j],&a[k]);
				//printf("a = %d\n", a[k]);
				k++;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	DataType a[] = {710,342,45,686,6,841,429,134,68,246};
	int i,n = sizeof(a)/sizeof(DataType),m = 3,d = 10;
	RadioSort(a,n,m,d);
	printf("基数排序结果\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	return 0;
}