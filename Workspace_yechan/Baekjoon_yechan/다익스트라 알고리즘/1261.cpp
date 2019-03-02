// baekjoon 4485 yechan
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
const int MAX_N = 125;
const int INF = 1e9;
const int dir[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
typedef pair<int, int> P;

int N, M;
char board[MAX_N][MAX_N];
vector<vector<int> > dist;
vector<vector<bool> > visited;

inline void encode(int x, int y, int &code) {
	code = (x<<7) | y;
}

inline void decode(int code, int &x, int &y) {
	x = code>>7;
	y = code & 0b1111111;
}

int Dijkstra(int sx, int sy, int dx, int dy) {
	priority_queue<P, vector<P>, greater<P> > PQ;
	dist[sx][sy]=board[sx][sy]-'0';
	int code;
	encode(sx, sy, code);
	PQ.push(P(0,code));

	while (!PQ.empty()) {
		int ccode;
		int cx, cy;
		do {
			ccode = PQ.top().second;
			decode(ccode, cx, cy);
			PQ.pop();
		} while (!PQ.empty() && visited[cx][cy]);
		if (visited[cx][cy]) break;
		visited[cx][cy]=true;
		for (int d=0; d<4; d++) {
			int nx = cx + dir[d][0];
			int ny = cy + dir[d][1];
			int ncode;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (dist[nx][ny] > dist[cx][cy] + board[nx][ny]-'0') {
				dist[nx][ny] = dist[cx][cy] + board[nx][ny]-'0';
				encode(nx, ny, ncode);
				PQ.push(P(dist[nx][ny], ncode));
			}
		}
	}

	return (dist[dx][dy] == INF) ? -1 : dist[dx][dy];
}

int main() {
	scanf("%d%d", &N, &M);
	visited = vector<vector<bool> >(N, vector<bool>(M, false));
	dist = vector<vector<int> >(N, vector<int>(M, INF));
	for (int i=0; i<N; ++i)
		scanf("%s", board[i]);

	printf("%d\n", Dijkstra(0, 0, N-1, M-1));
	return 0;
}