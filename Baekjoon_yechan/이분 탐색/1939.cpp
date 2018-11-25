// baekjoon 1939 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 10001

int N, M, A, B, C;
bool visit[MAX_N];

int main() {
	scanf("%d %d", &N, &M);
	for (int i=0; i<M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		node[A][B]=C;
		node[B][A]=C;
	}
	scanf("%lld %lld", &from, &to);
	lo=0; hi=LLONG_MAX;
	while (lo<=hi) {
		mid = (lo + hi)/2;
		queue<int> q;
		fill(visit, visit+N+1, false);
		q.push(from);
		visit[from]=true;
		while (!q.empty()) {
			int city = q.front();
			if(city == to) break;
			q.pop();
			for (int i=1; i<=N; i++) {
				if (!visit[i] && node[city][i] >= mid) {
					visit[i]=true;
					q.push(i);
				}
			}
		}
		if (visit[to]) {
			rst = max(rst, to);
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	printf("%lld", rst);
}