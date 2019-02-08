// baekjoon 1300 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 1e9
int main() {
	int N, K; scanf("%d %d", &N, &K);
	int l=1, r=INF, result = 0;
	while (l <= r) {
		long long cnt = 0;
		int mid = (l+r)/2;
		for (int i=1; i<=N; i++) cnt += min(N,mid/i);
		if (cnt < K) l=mid+1;
		else result=mid, r=mid-1;
	}
	printf("%d\n", result);
	return 0;
}