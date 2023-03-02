#include <stdio.h>

int main(int argc, char const *argv[])
{
	int num, sum = 1, i = 0;
	scanf("%d", &num);

	while (1)
	{
		sum += i * 6;
		if (num <= sum)
		{
			printf("%d\n", i + 1);
			break;
		}
		i++;
	}

	return 0;
}