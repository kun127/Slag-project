//本程序使用VS2019编写
#include<stdio.h>
#include<stdlib.h>

#define R1 4
#define C1 4
#define R2 4
#define C2 4

void Input_MAT(float MA[][C1], float MB[][C2]);
void Output_MAT(float out[][C1]);
void tran(float MA[][C1]);//矩阵转置函数//
void add(float MA[][C1], float MB[][C2]);//矩阵加法函数//
void sub(float MA[][C1], float MB[][C2]);//矩阵减法函数//
void mult(float MA[][C1], float MB[][C2]);//矩阵乘法函数//

float ME[C1][R1] = { 0 };

void main()
{
	float MA[R1][C1], MB[R2][C2];
	int c;

	while (1)
	{
		printf("---------------------\n");
		printf("|功  能  如  下     |\n");
		printf("|矩  阵  转  置    1|\n");
		printf("|矩  阵  相  加    2|\n");
		printf("|矩  阵  相  减    3|\n");
		printf("|矩  阵  乘  法    4|\n");
		printf("|结         束     0|\n");
		printf("|请选择你需要的操作 |\n");
		printf("--------------------\n");
		scanf_s("%d", &c);
		switch (c)
		{
		case 1:
			tran(MA);
			break;
		case 2:
			if ((R1 == R2) && (C1 == C2))
				add(MA, MB);
			else
				printf("Error\n");
			break;
		case 3:
			if ((R1 == R2) && (C1 == C2))
				sub(MA, MB);
			else
				printf("Error\n");
		case 4:
			if (C1 == R2)
				mult(MA, MB);
			else
				printf("Error\n");
		case 0:
			printf("结束!\n");
			exit(0);
			break;
		default:
			printf("对不起，你的输入不合法!\n");
			break;
		}
	}
}
void Input_MAT(float MA[][C1], float MB[][C2])//输入函数//
{
	int i, j;
	printf("请输入%d*%d矩阵MA(每行以回车结束):\n", R1, C1);//输入MA
	for (i = 0; i < R1; i++)
	{
		for (j = 0; j < C1; j++)
		{
			scanf_s("%f", &MA[i][j]);
		}
	}
	printf("请输入%d*%d矩阵MB(每行以回车结束):\n", R1, C1);//输入MB
	for (i = 0; i < R2; i++)
	{
		for (j = 0; j < C2; j++)
		{
			scanf_s("%f", &MB[i][j]);
		}
	}
}
void Output_MAT(float out[][C1])//输出函数//
{
	int i, j;
	for (i = 0; i < R1; i++)//输出结果
	{
		for (j = 0; j < C1; j++)
		{
			printf("%6.2f", out[i][j]);
		}
		printf("\n");
	}

}
void tran(float MA[][C1])//矩阵转置函数//
{
	int i, j;
	printf("请输入%d*%d矩阵MA(每行以回车结束):\n", R1, C1);
	for (i = 0; i < R1; i++)
	{
		for (j = 0; j < C1; j++)
		{
			scanf_s("%f", &MA[i][j]);
			ME[j][i] = MA[i][j];
		}
	}
	printf("转置后结果为：\n");
	Output_MAT(ME);
}
void add(float MA[][C1], float MB[][C2])//矩阵加法函数//
{
	int i, j;
	Input_MAT(MA, MB);
	for (i = 0; i < R1; i++)//相加
	{
		for (j = 0; j < C1; j++)
		{
			ME[i][j] = MA[i][j] + MB[i][j];
		}
	}
	printf("相加后结果为：\n");
	Output_MAT(ME);
}
void sub(float MA[][C1], float MB[][C2])//矩阵减法函数//
{
	int i, j;
	Input_MAT(MA, MB);
	for (i = 0; i < R1; i++)//相减
	{
		for (j = 0; j < C1; j++)
		{
			ME[i][j] = MA[i][j] - MB[i][j];
		}
	}
	printf("相减后结果为：\n");
	Output_MAT(ME);
}
void mult(float MA[][C1], float MB[][C2])//矩阵乘法函数//
{
	int i, j, m;
	Input_MAT(MA, MB);
	for (i = 0; i < R1; i++)
	{
		for (j = 0; j < R1; j++)
		{
			float sum = 0;
			for (m = 0; m < R1; m++)
			{
				sum = sum + MA[i][m] * MB[m][j];
			}
			ME[i][j] = sum;
		}
	}
	printf("相乘后结果为：\n");
	Output_MAT(ME);
}