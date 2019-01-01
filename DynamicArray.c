#include <stdio.h>
#include <malloc.h>

/*
	malloc -- memory allocate 内存分配
	calloc -- clear allocate 表示清除内存，用0 initialize memeory
	relloc -- re allocate 重新申请分配
	动态申请数组内存空间函数 calloc(unsigned n,unsigned size)
	gcc -fexec-charset=GBK DynamicArray.c -o DynamicArray
	当所申请的内存不足时，可使用realloc()函数重新指定动态数组的个数
*/

int main(int argc, char const *argv[])
{
	int *a,n = 10;
	//动态申请n个int类型的内存空间，返回首地址
	a = (int *)calloc(n,sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		a[i] = i + 1;//数组元素赋值
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);//显示
	}
	free(a);//释放内存
	return 0;
}