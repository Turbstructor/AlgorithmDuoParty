#include <cstdio>
#include <algorithm>

using namespace std;
#define MAX_N 100000

int N, M, curr, result;
char Nbuf[MAX_N + 1];
char Mbuf[MAX_N + 1];

int cache[MAX_N + 1];

int IsRightWin(char l, char r)
{
	if(r=='R' && l=='S') return 1;
	if(r=='P' && l=='R') return 1;
	if(r=='S' && l=='P') return 1;
	return 0;
}


int main()
{
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf(" %c", &Nbuf[i]);
	for(int i=0; i<M; i++)
		scanf(" %c", &Mbuf[i]);

	printf("%s\n", Nbuf);
	printf("%s\n", Mbuf);

	curr = 0;
	for(int i=0; i<M; i++)
	{
		int tmp=IsRightWin(Nbuf[i], Mbuf[i]);
		curr += tmp;
		cache[i] = tmp;
	}
	for(int i=M; i<N; i++)
	{
		int tmp=IsRightWin(Nbuf[i], Mbuf[i]);
		curr += (tmp-cache[i-M]);
		cache[i] = tmp;
		result = max(result, curr);
		printf("i: %d, rst: %d\n", i, result);
	}
	for(int i=0; i<N; i++)
		printf("%d ", cache[i]);
	printf("%d", curr);
}