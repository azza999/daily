#include <stdio.h>

int put (int i, int max, int * weight, int * value, int len)
{
	int currentValue, left, right;
	if (i <= 0 || max <= 0)
		return 0;
	if (weight[i] > max)
	{
		currentValue = put(i - 1, max, weight, value, len);
		// printf("%5d %5d %5d\n",i-1,max,currentValue);
		return currentValue;
	}
	else
	{
		left = put(i - 1, max, weight, value, len);
		// printf("%5d %5d %5d\n",i-1,max,left);
		right = put(i - 1, max - *(weight-i), weight, value, len);
		// printf("%5d %5d %5d\n",i-1,max - *(weight-i),right);
		return left < right + *(value+i) ? right + *(value+i) : left;
	}

}

int main(void)
{
	int row, max;
	int weight[100], value[100];

	scanf("%d %d", &row, &max);

	for (int i = 0; i < row; i++)
	{
		scanf("%d %d", &weight[i], &value[i]);
	}

	int result = put(row, max, weight, value, row);
	printf("%d",result);

	return 0;
}