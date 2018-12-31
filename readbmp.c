# include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	// 第一个参数是文件名
	FILE * bmp;
	unsigned char buf[1024];
	long sum = 0;
	int length = 0;
	unsigned char offset = 18;
	int width,height,bit;
	if (argv[1])
	{
		bmp = fopen(argv[1],"rb");
	}else{
		printf("请输入文件名");
		return 0;
	}
	
	while( (length = fread(buf,sizeof(unsigned char), 1024,bmp)) != 0 )
    {
    	if (sum == 0)
    	{
    		//文件标识 图像宽度 图像高度 像素位数 
    		printf("%c %c\n", buf[0],buf[1]);
    		width = buf[offset] | (buf[offset + 1] << 8) | (buf[offset + 2] << 16) | (buf[offset + 3] << 24);
    		height = buf[offset + 4] | (buf[offset + 5] << 8) | (buf[offset + 6] << 16) | (buf[offset + 7] << 24);
    		bit = buf[offset + 10] | buf[offset + 11] << 8;
    		printf("width:%d\theight:%d\tbit:%d\n", width,height,bit);
    	}
       sum = sum + length;
	} 
	printf("%d\n", sum);
	printf("%d\n", sum/1024);
	fclose(bmp);
	return 0;
}