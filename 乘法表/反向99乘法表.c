//反向99乘法表
#include<stdio.h>

int main()
{
	int i, j, k;
	char t = '	';
	for (i = 1; i <= 9; i++)
	{
		for (k = 1; k <= i - 1; k++)
		{
			printf("%c", t);
		}
		for (j = i; j <= 9; j++)
		{
			printf("%d*%d=%d\t", i, j, j * i);
		}
		printf("\n");
	}
	return 0;
}