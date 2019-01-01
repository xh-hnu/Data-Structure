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

int main(int argc, char const *argv[])
{
	DataType a[] = {{9,'a'},
					{3,'b'},
					{7,'c'},
					{5,'d'},
					{1,'e'}};
	printf("排序之前：");
	printDataTypeList(a,sizeof(a) / sizeof(DataType));
	insertSort(a,sizeof(a) / sizeof(DataType));
	printf("排序之后：");
	printDataTypeList(a,sizeof(a) / sizeof(DataType));
	return 0;
}