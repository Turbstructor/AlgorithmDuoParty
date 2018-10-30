// baekjoon 1699 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 100000

int N;
int dp[MAX_N+1];

int main()
{
	scanf("%d", &N);
	int j=0;
	int tmp=0;

	for(int i=1; i<N+1; i++){
		tmp = dp[i-1]+1; j=2;
		while(j*j <= i){
			tmp = min(tmp, dp[i-j*j]+1);
			j++;
		}
		dp[i]=tmp;
	}
	printf("%d", dp[N]);
	return 0;
}