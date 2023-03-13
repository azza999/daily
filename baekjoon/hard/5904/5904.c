#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// strcpy custom
// str에 start 지점부터 cpy(대상)을 복사
void strcpy_c(char * str, char cpy[500], int start)
{
	int i = 0;
	for (i = 0; i < strlen(cpy); i++)
	{
		str[i + start] = cpy[i];
	}
	str[i + start] = '\0';
}

int main(int argc, char const *argv[])
{
	int idx = 3, i, j, cnt;
	scanf("%d", &cnt);
	cnt += 1;
	char mooStr[500] = "moo", middle[500], newStr[500];
	
	for (i = 1; i < cnt; i++)
	{
		middle[0] = 'm';
		for (j = 1; j < i + 3; j++)
		{
			middle[j] = 'o';
		}
		middle[j] = '\0';

		strcpy_c(newStr, mooStr, 0);
		strcpy_c(newStr, middle, strlen(newStr));
		strcpy_c(newStr, mooStr, strlen(newStr));

		strcpy_c(mooStr, newStr, 0);

	}

	printf("%s\n", mooStr);
	
	for (int i = 0; i < strlen(mooStr); i++)
	{
		if (mooStr[i] == 'm')
		{
			printf("%d ", i);
		}
	}

	return 0;
}