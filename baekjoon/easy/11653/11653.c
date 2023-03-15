#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, i;
	scanf("%d", &n);

	for (int i = 2; i < n/2+1; i++)
	{
		if (n % i == 0)
		{
			printf("%d\n", i);
			n /= i;
			i = 1;
		}
	}
	if (n > 1)
	{
		printf("%d\n", n);
	}
	
	return 0;
}