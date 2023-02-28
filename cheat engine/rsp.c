#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int computerS ()
{
	srand(time(NULL));
	return rand() % 3;
}

int checkWinner (int user, int computer)
{
	if(user == computer)
		return 0;

	if((user == 0 && computer == 1) || (user == 1 && computer == 2) || (user == 2 && computer == 0))
		return 1;

	return -1;
}

int main(void)
{
	char str[10];
	int user = 0;
	int computer = 0;
	int result = 0;
	char * rsp[3] = {"rock","scissors","paper"};

	while (1)
	{
		puts("0 : rock, 1 : scissors, 2 : paper");
		gets(str);
		
		if (!(str[0] == '0' || str[0] == '1' || str[0] == '2')) {
			puts("re enter\n");
			continue;
		}

		user = (int)str[0] - 48;
		computer = computerS();

		printf("you : %s, computer : %s \n\n", rsp[user], rsp[computer]);
		result = checkWinner(user, computer);
		if (result == 0)
			puts("draw");
		if (result == 1)
			puts("you win!");
		if (result == -1)
			puts("looser!");

		puts("\n\n ------------------------------------------------ \n\n");
	}


	return 0;
}