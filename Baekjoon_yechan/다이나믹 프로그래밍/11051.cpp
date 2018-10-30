// baekjoon 11051 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

#define DIV_NUM 10007
#define MAX_N 	1000

int N, K;
int C[MAX_N+1][MAX_N+1];
// i : N, 	j : K
void comb(int i, int j){
	if(C[i][j] != 0) return;
	if(j == 0 || j == i){
		C[i][j] = 1; return;
	}
	if(C[i-1][j] == 0) comb(i-1, j);
	if(C[i-1][j-1] == 0) comb(i-1, j-1);
	C[i][j] = (C[i-1][j]+C[i-1][j-1])%DIV_NUM;
}

int main()
{
	scanf("%d %d", &N, &K);
	comb(N, K);
	printf("%d", C[N][K]);
}