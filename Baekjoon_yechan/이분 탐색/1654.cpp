// baekjoon 1654 yechan
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_K 10001
typedef long long LL;
int K, N;
LL lo, hi, mid, rst, plug[MAX_K];

int main() {
	scanf("%d %d", &K, &N);

	for (int i=0; i<K; i++) scanf("%lld", &plug[i]);

	lo = 0, hi = LLONG_MAX;

	while (lo <= hi) {
		int ans = 0;

		mid = (lo + hi)/2;

		for (int i=0; i<K; i++)
			ans += plug[i]/mid;

		if (ans >= N) {
			lo = mid+1;
			rst = max(rst, mid);
		}
		else
			hi = mid-1;
	}
	printf("%lld", rst);
	return 0;
}