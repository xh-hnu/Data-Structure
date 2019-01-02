#include <stdio.h>

#define N 8

/*
	这里需要注意的是，行和列我是从1开始
	而保存皇后值的数组下标从0开始
	所以行号也数组下标的关系是 row = i + 1
*/

int queens[N] = {0};
int count = 0;

void printQueen(void){
	for (int row = 0; row < N + 2; ++row)
	{
		for (int col = 0; col < N + 2; ++col)
		{
			if ((col == 0 || col == (N + 1)) && (row == 0 || row == (N + 1)))
			{
				printf("#");
			}else if (col == 0 || col == N + 1)
			{
				printf("%d", row);
			}else if (row == 0 || row == N + 1)
			{
				printf("%d", col);
			}else{
				if (queens[row - 1])//非零
				{
					if (col == queens[row - 1])
					{
						printf("*");
					}else{
						printf(" ");
					}
				}else{
					printf(" ");
				}
			}
			printf(" ");
		}
		printf("\n");
	}
}

int check(int row,int col){
	//遍历该行之前所有的行
	for (int i = 0; i < row - 1; ++i)
	{
		//依次取出前面行中皇后所在位置的列坐标
		int data = queens[i];
		if (data == col)//如果在同一列
		{
			//printf("data == col\n");
			return 0;
		}
		//此时，只有当前行之前的所有行才有皇后
		//如果当前位置的右斜上方有皇后，在一条斜线上，也不行        
		if ((i + data + 1) == (row + col)) {  
			//printf("右斜上方有皇后\n");          
			return 0;        
		}        
		//如果当前位置的左斜上方有皇后，在一条斜线上，也不行        
		if ((i - data + 1) == (row - col)) { 
			//printf("左斜上方有皇后\n"); 
			return 0;        
		}
	}
	return 1;//可以放
}

void findQueen(int row){
	if (row > 8)//分界
	{
		count++;
		//printf("%d %d\n", count, row);
		printQueen();
		return;
	}
	for (int col = 1; col < N + 1; col++)
	{
		if (check(row,col))//深度回溯，递归算法
		{
			queens[row - 1] = col;
			findQueen(row + 1);
			queens[row - 1] = 0;//找不到时，返回上一结点清零，以免有脏数据
		}
	}
}

int main(int argc, char const *argv[])
{
	findQueen(1);
	printf("解的个数%d\n", count);
	return 0;
}