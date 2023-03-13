#include <stdio.h>
#include <stdlib.h>
#define MOO_MAX 100000


void printMpos(int mpos[MOO_MAX], int idx)
{
	int m = 0;
	for (int i = 0; i < idx; i++)
	{
		m += mpos[i];
		printf("%d ",m);
	}
}

// mpos를 복사하는 역할. mpos 주소값과 시작부터 어디까지 복사할 지 정하고 새로운 idx값을 반환
int moocpy (int mpos[MOO_MAX], int idx)
{
	int dest = idx - 2;
	if(idx >= MOO_MAX-1) return idx;
	for (int i = 0; i < dest; i++)
	{
		if(idx >= MOO_MAX-1) return idx;
		mpos[idx++] = mpos[i];
	}
	return idx;
}

int main(int argc, char const *argv[])
{

	const int fixed = 3;
	int mpos[MOO_MAX] = {3,4}, i, j, cnt, idx = 2, now = 35;

	scanf("%d", &cnt);
	
	for (i = 0; i < cnt; i++)
	{
		mpos[idx++] = now/10;
		mpos[idx++] = now - 30;
		now++;
		printf("%d\n", idx);
		idx = moocpy(mpos, idx);
	}


	printMpos(mpos, idx);

	return 0;
}