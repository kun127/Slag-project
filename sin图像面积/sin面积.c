#include<stdio.h>
#include<math.h>

#define pi 3.1415926

int main()
{

	int j, i;
	printf("将图像分为几份？\n");
	scanf_s("%d", &i);
	double x[1000], y[1000];
	double width, hsum , s;
	i = 1000;
	hsum = 0;
	s = 0;
	width = (2 * pi) / i;
	for (j = 0; j < i; j++)
	{
		x[j] = width * j;
		y[j] = fabs(sin(x[j]));
		hsum = hsum + y[j];
		//printf("sin->y[%d]=%lf\n", j, y[j]);
		//printf("sum=%lf\n", hsum);
	}
	s = hsum * width;
	printf("面积S = %lf", s);
	return 0;
}