// baekjoon 9337 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int max_n = 21;
const int max_color = 6;
const int dir[4][2] = { { 0, -1}, { 0, 1}, { -1, 0}, { 1, 0}};
int T, N, cnt;
char board[max_n][max_n];
vector<vector<bool> > mark;

void dfs(char color, int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= N) return;
	if (board[x][y] != color) return;
	if (mark[x][y]) return;

	mark[x][y] = true;
	cnt++;
	for (int d=0; d<4; d++){
		dfs(color, x+dir[d][0], y+dir[d][1]);
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		memset(board, 0, sizeof(board));
		for (int i=0; i<N; i++) 
			scanf("%s", board[i]);

		vector<vector<bool> > connected(N, vector<bool>(N, false));
		mark = vector<vector<bool> >(N, vector<bool>(N, false));
		cnt = 0;
		dfs(board[0][0], 0, 0);
		connected = mark;
		int maxcnt = cnt;
		vector<int> adjnum(max_color, 0);
		int totalCount = 0;
		while (maxcnt < N * N) {
			maxcnt = 0;
			int maxIdx = -1;
			vector<vector<bool> > maxMark(N, vector<bool>(N, false));
			for (int k=0; k < max_color; k++) {
				for (int i=0; i < N; i++)
					for (int j=0; j < N; j++)
						if (connected[i][j])
							board[i][j] = '1' + k;
				cnt = 0;
				mark = vector<vector<bool> >(N, vector<bool>(N, false));
				dfs(board[0][0], 0, 0);
				if (cnt > maxcnt) {
					maxcnt = cnt;
					maxIdx = k;
					maxMark = mark;
				}
			}
			adjnum[maxIdx]++;
			totalCount++;
			connected = maxMark;
		}
		printf("%d\n", totalCount);
		for (int i=0; i<max_color; i++)
			printf("%d ", adjnum[i]);
		puts("");
	}
	return 0;
}
