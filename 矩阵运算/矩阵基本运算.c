//������ʹ��VS2019��д
#include<stdio.h>
#include<stdlib.h>

#define R1 4
#define C1 4
#define R2 4
#define C2 4

void Input_MAT(float MA[][C1], float MB[][C2]);
void Output_MAT(float out[][C1]);
void tran(float MA[][C1]);//����ת�ú���//
void add(float MA[][C1], float MB[][C2]);//����ӷ�����//
void sub(float MA[][C1], float MB[][C2]);//�����������//
void mult(float MA[][C1], float MB[][C2]);//����˷�����//

float ME[C1][R1] = { 0 };

void main()
{
	float MA[R1][C1], MB[R2][C2];
	int c;

	while (1)
	{
		printf("---------------------\n");
		printf("|��  ��  ��  ��     |\n");
		printf("|��  ��  ת  ��    1|\n");
		printf("|��  ��  ��  ��    2|\n");
		printf("|��  ��  ��  ��    3|\n");
		printf("|��  ��  ��  ��    4|\n");
		printf("|��         ��     0|\n");
		printf("|��ѡ������Ҫ�Ĳ��� |\n");
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
			printf("����!\n");
			exit(0);
			break;
		default:
			printf("�Բ���������벻�Ϸ�!\n");
			break;
		}
	}
}
void Input_MAT(float MA[][C1], float MB[][C2])//���뺯��//
{
	int i, j;
	printf("������%d*%d����MA(ÿ���Իس�����):\n", R1, C1);//����MA
	for (i = 0; i < R1; i++)
	{
		for (j = 0; j < C1; j++)
		{
			scanf_s("%f", &MA[i][j]);
		}
	}
	printf("������%d*%d����MB(ÿ���Իس�����):\n", R1, C1);//����MB
	for (i = 0; i < R2; i++)
	{
		for (j = 0; j < C2; j++)
		{
			scanf_s("%f", &MB[i][j]);
		}
	}
}
void Output_MAT(float out[][C1])//�������//
{
	int i, j;
	for (i = 0; i < R1; i++)//������
	{
		for (j = 0; j < C1; j++)
		{
			printf("%6.2f", out[i][j]);
		}
		printf("\n");
	}

}
void tran(float MA[][C1])//����ת�ú���//
{
	int i, j;
	printf("������%d*%d����MA(ÿ���Իس�����):\n", R1, C1);
	for (i = 0; i < R1; i++)
	{
		for (j = 0; j < C1; j++)
		{
			scanf_s("%f", &MA[i][j]);
			ME[j][i] = MA[i][j];
		}
	}
	printf("ת�ú���Ϊ��\n");
	Output_MAT(ME);
}
void add(float MA[][C1], float MB[][C2])//����ӷ�����//
{
	int i, j;
	Input_MAT(MA, MB);
	for (i = 0; i < R1; i++)//���
	{
		for (j = 0; j < C1; j++)
		{
			ME[i][j] = MA[i][j] + MB[i][j];
		}
	}
	printf("��Ӻ���Ϊ��\n");
	Output_MAT(ME);
}
void sub(float MA[][C1], float MB[][C2])//�����������//
{
	int i, j;
	Input_MAT(MA, MB);
	for (i = 0; i < R1; i++)//���
	{
		for (j = 0; j < C1; j++)
		{
			ME[i][j] = MA[i][j] - MB[i][j];
		}
	}
	printf("�������Ϊ��\n");
	Output_MAT(ME);
}
void mult(float MA[][C1], float MB[][C2])//����˷�����//
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
	printf("��˺���Ϊ��\n");
	Output_MAT(ME);
}