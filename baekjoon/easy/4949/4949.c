#include <stdio.h>
#define STACK_MAX 101

typedef struct _stack
{
	char arr[STACK_MAX];
	char * cursor;
} Stack;

void push (Stack * stack, char cha)
{
	*((*stack).cursor) = cha;
	((*stack).cursor) += sizeof (char);
}

char pop (Stack * stack)
{
	if ((*stack).cursor <= (*stack).arr)
	{
		return -1;
	}
	(*stack).cursor--;
	return *((*stack).cursor);
}

int main(void)
{
	char str[STACK_MAX];
	int i, okFlag = 0;
	char tmp;

	while(1)
	{
		i=0;
		gets(str);
		okFlag = 1;
		Stack brkts;
		brkts.cursor = brkts.arr;
		if (str[0] == '.')
		{
			return 0;
		}
		while (str[i] != '.')
		{
			if (str[i] == '(' || str[i] == '[')
			{
				push(&brkts, str[i]);
			}
			if (str[i] == ')' && pop(&brkts) != '(')
			{
				okFlag = 0;
			}
			if (str[i] == ']' && pop(&brkts) != '[')
			{
				okFlag = 0;
			}
			i++;
		}

		if(brkts.cursor == brkts.arr && okFlag == 1) printf("yes\n");
		else printf("no\n");
	}


	
	return 0;
}