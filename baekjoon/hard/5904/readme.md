# Moo 게임

 입력값이 10의 9승이다. MOO 문자열을 만든다고 칠 때 유니코드가 아닌 아스키 코드로 만들어도 1,000,000,000 바이트, 10억 바이트다. 문자열을 만들기만 해도 1GB의 메모리를 잡아먹기 때문에, 메모리 제한 128MB를 만족시킬 수 없다. 그래서 오일러 프로젝트 문제를 푼 경험을 살려 조금 논리적으로 풀어보기로 했다.

 문자는 어차피 'm' 아니면 'o'이다. m이 그나마 적게 나오니 m이 얼마마다 나오는 규칙이 있는지 알아보기로 했다.

moo code
```
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
    int idx = 3, i, j, cnt = 6;
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
    
    for (int i = 0; i < strlen(newStr); i++)
    {
        if (newStr[i] == 'm')
        {
            printf("%d ", i);
        }
    }

    return 0;
}
```

moo 문자열을 만들고 m의 모든 위치를 알려주는 프로그램이다.
결과
```
0 3 7 10 15 18 22 25 31 34 38 41 46 49 53 56 63 66 70 73 78 81 85 88 94 97 101 104 109 112 116 119 127 130 134 137 142 145 149 152 158 161 165 168 173 176 180 183 190 193 197 200 205 208 212 215 221 224 228 231 236 239 243
```

해석>

```
1 (moomooomoo)
0 3 7
  3 4
2 (moomooomoomoooomoomooomoo)
0 3 7 10 15 18 22
  3 4 3  5  3  4
3 (moomooomoomoooomoomooomoomooooomoomooomoomoooomoomooomoo)
0 3 7 10 15 18 22 25 31 34 38 41 46 49 53
  3 4 3  5  3  4  3  6  3  4  3  5  3  4
```

더해지는 수가 올라갔다 내려갔다. 올라갔다 내려가는건 n까지 반복된다.

m의 위치 또한 moo 문자열처럼 증가하는 것을 알게되었다. 이젠 moo 문자열을 구하지 않고 n번째 m이 어디인지 구하는 프로그램을 작성해보았다.

(원래 하려고 했던 것)

핵심은 다음 m이 나오는 위치가 n까지 1씩 더해졌다 빼졌다를 반복하는 것이다.
그리고 이정도는 재귀함수를 사용했다. 이미 문자열을 만들지 않는 것만 해도 메모리를 수 MB는 아꼈을 것이다.

`arr[n]`에 n번째 moo의 위치가 저장되는 프로그램이다.


근데 약간 다른 풀이법이 생각났다.

34 35 34 36 34 35 34

두 개씩 묶으면 배열이 이렇게 된다. 어차피 int형 배열인거 최대한 멀리까지 가보자. 재귀로 풀까 하다가 그냥 위에 for문을 사용한 moo랑 비슷하게 풀었다. 명심하자. 같은 방식이면 최대한 재귀를 안쓰는 게 유리하다.

34 / 10을 넣고, 34 % 10을 넣으려 했는데 생각해보니 40이 넘어가면 이 방식이 안된다.
3 10을 표현을 못한다.. 아니다 30을 빼줄까? 빼주면 될 듯하다.

그렇게 작성한 프로그램...

```
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
```

근데 이렇게 해도 40만번째 언저리의 M까지밖에 구하지 못한다.
그러던 중 다른 방법이 생각났다. 배열을 펼쳐서 (반을 오른쪽 위치에 복사해서) moo 배열을 만든 것처럼, 수를 받으면 반씩 접어가며 해당 위치의 글자를 알아낼 수 있지 않을까? 근데 이거 생각보다 어렵다. 그래서 다음 방법은 음...





