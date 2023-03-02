#include <stdio.h>
#include <stdlib.h>

typedef struct _Pos
{
	int x;
	int y;
} Pos;

int solveCheck(Pos dest, Pos r, Pos b);
int tiltLeft (char board[10][10], Pos size, Pos dest, Pos r, Pos b, int cnt);
int tiltRight (char board[10][10], Pos size, Pos dest, Pos r, Pos b, int cnt);
int tiltDown (char board[10][10], Pos size, Pos dest, Pos r, Pos b, int cnt);
int tiltUp (char board[10][10], Pos size, Pos dest, Pos r, Pos b, int cnt);

void printBoard(char board[10][10], Pos size)
{
	printf("\n board \n\n");
	for (int yi = 0; yi < size.y; yi++)
	{
		for (int xi = 0; xi < size.x; xi++)
		{
			printf("%c",board[yi][xi]);
		}
		printf("\n");
	}
	printf("\n board End \n");
}

// 풀었으면 1, 아직 아니면 0, 파란공이 빠졌으면 -1
int solveCheck(Pos dest, Pos r, Pos b)
{
	if (dest.x == b.x && dest.y == b.y) return -1;
	if (dest.x == r.x && dest.y == r.y) return 1;
	return 0;
}



int tiltLeft (char board[10][10], Pos size, Pos dest, Pos r, Pos b, int cnt)
{
	if(cnt++ > 10) return -1;

	int rseq = 1;


	Pos * first = &r;
	Pos * second = &b;
	// 뭐가 더 왼쪽에 있나 확인
	if (first->x > second->x)
	{
		first = &b;
		second = &r;
		rseq = 2;
	}

	// 왼쪽 끝에 구슬 바로 놓기, 구슬부터 왼쪽으로 가면서 #을 만나는지 확인. 구슬은 만날 일이 없다. 더 왼쪽의 구슬이므로.
	// 구슬 바로 왼쪽이 #이면 움직이면 안됨. 따라서 구슬 위치에서 구슬 -1 위치를 확인하면서 간다.
	for (int xi = first->x; xi > 0; xi--)
	{
		if (board[first->y][xi-1] == '#')
		{
			first->x = xi;
			break;
		}
		if (board[first->y][xi-1] == 'O')
		{
			return rseq == 1 ? cnt : -1;
		}
	}

	for (int xi = second->x; xi > 0; xi--)
	{
		if (board[second->y][xi-1] == '#' || (second->y == first->y && xi - 1 == first->x))
		{
			second->x = xi;
			break;
		}
		if (board[second->y][xi-1] == 'O')
		{
			return rseq == 2 ? cnt : -1;
		}
	}
	printf("Left! r : %d, %d b : %d, %d, dest : %d, %d\n",r.y,r.x,b.y,b.x,dest.y,dest.x);



	int check = solveCheck(dest, r, b);
	if (check == 1) return cnt;
	if (check == -1) return -1;

	int uCnt = tiltUp(board, size, dest, r, b, cnt);
	int dCnt = tiltDown(board, size, dest, r, b, cnt);

	if (uCnt == -1 && dCnt == -1) return -1;
	if (uCnt < dCnt) return uCnt;
	return dCnt;
}

int tiltRight (char board[10][10], Pos size, Pos dest, Pos r, Pos b, int cnt)
{
	if(cnt++ > 10) return -1;
	int rseq = 1;


	Pos * first = &r;
	Pos * second = &b;
	if (first->x < second->x)
	{
		first = &b;
		second = &r;
		rseq = 2;
	}
	for (int xi = first->x; xi < size.x-1; xi++)
	{
		if (board[first->y][xi+1] == '#')
		{
			first->x = xi;
			break;
		}
		if (board[first->y][xi+1] == 'O')
		{
			return rseq == 1 ? cnt : -1;
		}
	}

	for (int xi = second->x; xi < size.x-1; xi++)
	{
		if (board[second->y][xi+1] == '#' || (second->y == first->y && xi + 1 == first->x))
		{
			second->x = xi;
			break;
		}
		if (board[second->y][xi+1] == 'O')
		{
			return rseq == 2 ? cnt : -1;
		}

	}
	printf("Right! r : %d, %d b : %d, %d\n",r.y,r.x,b.y,b.x);

	int check = solveCheck(dest, r, b);
	if (check == 1) return cnt;
	if (check == -1) return -1;

	int uCnt = tiltUp(board, size, dest, r, b, cnt);
	int dCnt = tiltDown(board, size, dest, r, b, cnt);
	
	if (uCnt == -1 && dCnt == -1) return -1;
	if (uCnt < dCnt) return uCnt;
	return dCnt;
}

int tiltUp (char board[10][10], Pos size, Pos dest, Pos r, Pos b, int cnt)
{
	if(cnt++ > 10) return -1;
	int rseq = 1;


	Pos * first = &r;
	Pos * second = &b;
	if (first->y > second->y)
	{
		first = &b;
		second = &r;
		rseq = 2;
	}
	for (int yi = first->y; yi > 0; yi--)
	{
		if (board[yi-1][first->x] == '#')
		{
			first->y = yi;
			break;
		}
		if (board[yi-1][first->x] == 'O')
		{
			return rseq == 1 ? cnt : -1;
		}
	}

	for (int yi = second->y; yi > 0; yi--)
	{
		if (board[yi-1][second->x] == '#' || (yi - 1 == first->y && second->x == first->x))
		{
			second->y = yi;
			break;
		}
		if (board[yi-1][second->x] == 'O')
		{
			return rseq == 2 ? cnt : -1;
		}
	}
	printf("Up! r : %d, %d b : %d, %d\n",r.y,r.x,b.y,b.x);

	int check = solveCheck(dest, r, b);
	if (check == 1) return cnt;
	if (check == -1) return -1;

	int uCnt = tiltLeft(board, size, dest, r, b, cnt);
	int dCnt = tiltRight(board, size, dest, r, b, cnt);
	
	if (uCnt == -1 && dCnt == -1) return -1;
	if (uCnt < dCnt) return uCnt;
	return dCnt;
}

int tiltDown (char board[10][10], Pos size, Pos dest, Pos r, Pos b, int cnt)
{
	if(cnt++ > 10) return -1;
	int rseq = 1;


	Pos * first = &r;
	Pos * second = &b;
	if (first->y < second->y)
	{
		first = &b;
		second = &r;
		rseq = 2;
	}
	for (int yi = first->y; yi < size.y-1; yi++)
	{
		if (board[yi+1][first->x] == '#')
		{
			first->y = yi;
			break;
		}
		if (board[yi+1][first->x] == 'O')
		{
			return rseq == 1 ? cnt : -1;
		}
	}

	for (int yi = second->y; yi < size.y-1; yi++)
	{
		if (board[yi+1][second->x] == '#' || (yi + 1 == first->y && second->x == first->x))
		{
			second->y = yi;
			break;
		}
		if (board[yi+1][second->x] == 'O')
		{
			return rseq == 2 ? cnt : -1;
		}
	}
	printf("Down! r : %d, %d b : %d, %d\n",r.y,r.x,b.y,b.x);

	int check = solveCheck(dest, r, b);
	if (check == 1) return cnt;
	if (check == -1) return -1;

	int uCnt = tiltLeft(board, size, dest, r, b, cnt);
	int dCnt = tiltRight(board, size, dest, r, b, cnt);
	
	if (uCnt == -1 && dCnt == -1) return -1;
	if (uCnt < dCnt) return uCnt;
	return dCnt;
}

int main(int argc, char const *argv[])
{
	char board[10][10];
	int tiltNum = 0, prevDirection = 0, Direction = 0;
	// Direction => 0 : left, 1 : right, 2 : up, : 3 : down
	Pos size, dest, r, b;
	int answer = -1;

	scanf("%d %d",&size.x, &size.y);
	getchar();

// 입력받기
	for (int yi = 0; yi < size.y; yi++)
	{
		for (int xi = 0; xi < size.x; xi++)
		{
			scanf("%c",&board[yi][xi]);
			if (board[yi][xi] == 'O')
			{
				dest.x = xi;
				dest.y = yi;
			}
			if (board[yi][xi] == 'R')
			{
				r.x = xi;
				r.y = yi;
			}
			if (board[yi][xi] == 'B')
			{
				b.x = xi;
				b.y = yi;
			}
		}
		getchar();
	}

	// printBoard(board,size);

	answer = tiltLeft(board, size, dest, r, b, 0);
	int tilt1 = tiltRight(board, size, dest, r, b, 0);
	int tilt2 = tiltUp(board, size, dest, r, b, 0);
	int tilt3 = tiltDown(board, size, dest, r, b, 0);

	printf("%d %d %d %d\n",answer, tilt1, tilt2, tilt3);

	answer = answer == -1 ? 100 : answer;
	tilt1 = tilt1 == -1 ? 100 : tilt1;
	tilt2 = tilt2 == -1 ? 100 : tilt2;
	tilt3 = tilt3 == -1 ? 100 : tilt3;

	answer = tilt1 < answer ? tilt1 : answer;
	answer = tilt2 < answer ? tilt2 : answer;
	answer = tilt3 < answer ? tilt3 : answer;

	printf("%d",answer);

	return 0;
}