#include <stdio.h>

typedef struct 
{
	int key;
	char data;	
}DataType;

void printDataTypeList(DataType a[],int n){
	for (int i = 0; i < n; ++i)
	{
		printf("{%d,%c} ",a[i].key,a[i].data);
	}
	printf("\n");
}

//特点
//每次比较相邻的key，是一种稳定的排序算法
void insertSort(DataType a[],int n){
	DataType temp;
	int j;
	for (int i = 1; i < n; i++)//第二个key开始
	{
		temp = a[i];
		j = i - 1;
		while(j > -1 && temp.key < a[j].key){
			//从后面开始比较，小的前移
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;//插入的位置
		printf("第%d次排序", i);
		printDataTypeList(a,n);
	}
}

//希尔排序的特点
//按增量分组进行的直接插入排序
//因此希尔排序是一种不稳定的排序算法
//时间复杂度比直接插入排序改善很多
void shellSort(DataType a[],int n,int d[],int numOfd){
	int d_value = 0;//增量
	DataType temp;
	int j;
	for (int i = 0; i < numOfd; ++i)//numOfd次排序
	{
		d_value = d[i];
		for (int k = 0; k < d_value; ++k)
		{
			for (int i = d_value; i < n - d_value + 1; i = i + d_value)
			//增量分组，直接插入排序
			{
				temp = a[i];
				j = i - d_value;
				while(j > -1 && temp.key < a[j].key){
					a[j + d_value] = a[j];
					j = j - d_value;
				}
				a[j + d_value] = temp;
			}
		}
	}
}

//特点 这是一种不稳定的排序算法
//但是可以改善稳定性
//方法：不直接交换起始值和最小值的位置，而是从最小值开始，到起始值结束
//前一个元素往后移动一个位置，这样不会改变相同关键字的元素的相对位置
void selectSort(DataType a[],int n){
	DataType min_temp;
	int min_index;
	for (int i = 0; i < n; ++i)
	{
		//每次循环开始，设置第i个位最小值
		min_temp = a[i];
		min_index = i;
		for(int j = i;j < n - 1;++j){
			//选出从第i个元素起后的最小值，并保存最小值的索引
			if (min_temp.key > a[j + 1].key)
			{
				min_temp = a[j + 1];
				min_index = j + 1;
			}
		}
		//当前起始值与最小值交换
		a[min_index] = a[i];
		a[i] = min_temp;
	}
}

//假设集合中有相同关键字的元素
//快速排序算法有可能会改变它们的相对位置
//所以快速排序是一种不稳定的排序算法
void quickSort(DataType a[],int low,int high){
	int i = low,j = high;//仿真指针
	DataType temp = a[low];
	while(i < j){//退出条件
		//直到右端发现一个小于标准值的元素
		while(i < j && temp.key <= a[j].key){
			j--;
		}
		//交换
		if (i < j)
		{
			a[i] = a[j];
			i++;
		}
		//知道左端发现一个大于标准值的元素
		while(i < j && temp.key > a[i].key){
			i++;
		}
		//交换
		if (i < j)
		{
			a[j] = a[i];
			j--;
		}
	}
	//一次排序的最后，把标准值放到中间，此时 i = j
	a[i] = temp;
	if (low < i){
		quickSort(a,low,i - 1);//对左端子集合进行递归排序
	}
	if (i < high)
	{
		quickSort(a,j + 1,high);//对右端子集合进行递归排序
	}
	{
		/* code */
	}
}

int main(int argc, char const *argv[])
{
	DataType a[] = {{9,'a'},{3,'b'},{7,'c'},
					{5,'d'},{1,'e'}};
	printf("直接插入排序之前：");
	printDataTypeList(a,sizeof(a) / sizeof(DataType));
	insertSort(a,sizeof(a) / sizeof(DataType));
	printf("直接插入排序之后：");
	printDataTypeList(a,sizeof(a) / sizeof(DataType));
	DataType test[] = {{9,'a'},{3,'b'},{7,'c'},
					{5,'d'},{1,'e'},{2,'f'},
					{8,'g'},{6,'h'},{4,'i'}};
	int d[] = {6,3,1};
	int numOfd = 3;
	printf("希尔排序之前：");
	printDataTypeList(test,sizeof(test) / sizeof(DataType));
	shellSort(test,sizeof(test) / sizeof(DataType),d,numOfd);
	printf("希尔排序之后：");
	printDataTypeList(test,sizeof(test) / sizeof(DataType));
	DataType selectSortTest[] = {{9,'a'},{3,'b'},{7,'c'},{5,'d'},
								{1,'e'},{15,'f'},{12,'g'}};
	printf("直接选择排序之前：");
	printDataTypeList(selectSortTest,sizeof(selectSortTest) / sizeof(DataType));
	selectSort(selectSortTest,sizeof(selectSortTest) / sizeof(DataType));
	printf("直接选择排序之后：");
	printDataTypeList(selectSortTest,sizeof(selectSortTest) / sizeof(DataType));
	DataType quickSortTest[] = {{9,'a'},{3,'b'},{7,'c'},{5,'d'},
								{1,'e'},{15,'f'},{12,'g'}};
	printf("快速排序之前：");
	printDataTypeList(quickSortTest,sizeof(quickSortTest) / sizeof(DataType));
	quickSort(quickSortTest,0,sizeof(quickSortTest) / sizeof(DataType) - 1);
	printf("快速排序之后：");
	printDataTypeList(quickSortTest,sizeof(quickSortTest) / sizeof(DataType));
	return 0;
}