// baekjoon 5626 yechan
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int DIV_NUM=1000000007;
const int MAX_N=10001;
const int MAX_H=5001;

int N, H, x, start, length, ret;
int dp[MAX_N][MAX_H]; // [length][hight_diff]

int main() {
	dp[0][0]=1;
	for (int i=1; i<MAX_N; i++) {
		dp[i][0]+=dp[i-1][0];
		dp[i][0]+=dp[i-1][1];
		for (int j=1; j<MAX_H-1; j++) {
			for (int d=-1; d<2; d++) {
				dp[i][j]+=dp[i-1][d+j];
				dp[i][j]%=DIV_NUM;
			}
		}
		dp[i][0]+=dp[i-1][MAX_H-1];
		dp[i][0]+=dp[i-1][MAX_H];
	}
	scanf("%d", &N);
	scanf("%d", &start);
	if (start != -1 && start != 0) return !printf("0\n");
	ret=1; start=0;
	length++;
	for (int i=1; i<N-1; i++) {
		scanf("%d", &x);
		if (x == -1) { length++; continue; }
		ret=(ret*dp[start+length-1][x]*1LL)%DIV_NUM;
		start=x, length=1;
	}
	scanf("%d", &x);
	if (x != -1 && x != 0) return !printf("0\n");
	// printf("len: %d, diff: %d\n", length, abs(start));
	ret=(ret*dp[start+length-1][0]*1LL)%DIV_NUM;
	printf("%d\n", ret);
	return 0;
}