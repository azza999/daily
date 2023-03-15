#include <stdio.h>
#define NAN_AMOUNT 9
#define REAL_AMOUNT 7

void select(int idx)
{

}

int main()
{
	int heights[NAN_AMOUNT], selected[REAL_AMOUNT];

	for (int i = 0; i < NAN_AMOUNT; ++i)
	{
		scanf("%d", &heights[i]);
	}

	for (int i = 0; i < REAL_AMOUNT; ++i)
	{
		select(i);
	}




	return 0;
}