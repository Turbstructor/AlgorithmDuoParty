// baekjoon 2512 yechan
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
#define MAX_N 10001
typedef long long LL;
int N, M;
LL ans, lo, hi, mid, rst, budget[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%lld", &budget[i]);
		ans += budget[i];
		rst = max(rst, budget[i]);
	}
	scanf("%d", &M);
	if(ans <= M) {
		printf("%lld", rst); return 0;
	}
	rst = 0;
	lo = 0, hi = LLONG_MAX;
	while (lo <= hi) {
		ans = 0; mid = (lo + hi)/2;
		for (int i=0; i<N; i++) {
			if (budget[i] < mid) 	ans += budget[i];
			else 					ans += mid;
		}
		if (ans == M) { rst = mid; break; }
		if (ans > M) {
			hi = mid-1;
		}
		else {
			lo = mid+1;
			rst = max(rst, mid);
		}
	}
	printf("%lld", rst);
	return 0;
}