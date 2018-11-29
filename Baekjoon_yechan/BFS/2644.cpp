// baekjoon 2644 yechan
#include <cstdio>
#include <queue>
using namespace std;
int n, start, finish, m, adj[101][101], dist[101];

int main() {
	scanf("%d %d %d %d", &n, &start, &finish, &m);
	for (int i=0; i<m; i++) {
		int x=0, y=0;
		scanf("%d %d", &x, &y);
		adj[x][y]=adj[y][x]=1;
	}

	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i=1; i <= n; i++) {
			if (adj[now][i] && !dist[i]) {
				dist[i] = dist[now] + 1;
				q.push(i);
			}
		}
	}
	printf("%d\n", (dist[finish] == 0)? -1 : dist[finish]);
}