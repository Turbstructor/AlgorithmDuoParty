// baekjoon 9335 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int T, N, adj[21], rst;

void backtracking(int curr, int count, int state) {
	if (curr == N) {
		if (state == (1<<N)-1) rst=min(rst, count);
		return;
	}
	backtracking(curr+1, count, state);
	backtracking(curr+1, count+1, state | adj[curr]);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		rst = 1e9;
		scanf("%d", &N);
		for (int i=0; i<N; i++) {
			int num; scanf("%d", &num);
			int connect = (1<<i);
			for (int j=0; j<num; j++) {
				int x; scanf("%d", &x);
				connect = connect | (1<<(x-1));
			}
			adj[i] = connect;
		}
		backtracking(0, 0, 0);
		printf("%d\n", rst);
	}
	return 0;
}