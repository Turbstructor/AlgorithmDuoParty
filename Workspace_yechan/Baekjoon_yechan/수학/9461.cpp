// baekjoon 9461 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 101;
typedef long long ll;

int T, N;
ll dp[MAX_N];

int main() {
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	for (int i=6; i<=100; i++)
		dp[i] = dp[i-1] + dp[i-5];

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%lld\n", dp[N]);
	}
	return 0;
}