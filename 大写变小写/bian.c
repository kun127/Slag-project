//��д��Сд
#include<stdio.h>
int main()
{
	int i, j, k = 0;
	char a[20];
	printf("\n����������(�Է���@��β):");
	while ((a[k] = getchar()) != '@')
		k++;
	for (j = 0; a[j] != '@'; j++)
	{
		if (a[j] <= 'Z' && a[j] >= 'A')
		{
			a[j] += 32;
		}
		if (a[j] >= 'a' && a[j] <= 'w')
			a[j] += 3;
		else if (a[j] == 'x' || a[j] == 'y' || a[j] == 'z')
			a[j] -= 23;
	}
	printf("����:");
	for(i = 0; a[i] != '@'; i++)
		printf("%c", a[i]);
	printf("\n");
}