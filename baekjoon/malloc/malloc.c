#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char * str, * longerstr;
	int need;

	str = (char *)malloc(sizeof(char) * 5);

	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = 'd';
	str[4] = '\0';

	printf("how many do you need more? : ");

	scanf("%d", &need);

	longerstr = (char*)malloc(sizeof(char) * (need + 1));

	strcpy(longerstr, str);
	free(str);

	for (int i = 0; i < need; i++)
	{
		longerstr[4 + i] = 'a';
	}

	longerstr[need + 5 + 1] = '\0';

	printf("%s",longerstr);

	free(longerstr);



	return 0;
}