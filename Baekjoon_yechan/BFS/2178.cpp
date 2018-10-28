// baekjoon 2178 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 987654321
const int roff[4] = {1, -1, 0, 0};
const int coff[4] = {0, 0, 1, -1};

int N, M, cnt;
bool visited[101][101];
bool board[101][101];

void bfs(int r, int c){
	queue<pair<int, int>> q;
	cnt = 1;
	q.push(make_pair(r,c));
	while(!q.empty()){
		int qSize = q.size();
		for(int s=0; s<qSize; s++){
			r = q.front().first;
			c = q.front().second;
			visited[r][c] = true;
			q.pop();
			for(int d=0; d<4; d++){
				int nr = r + roff[d];
				int nc = c + coff[d];
				if(nr < 0 || nc < 0 || nr >= N || nc >= M || !board[nr][nc] || visited[nr][nc]) continue;
				if(nr == N-1 && nc == M-1) return;
				q.push(make_pair(nr,nc));
			}
		}
		cnt++;
	}
}

int main()
{
	char c[101];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%s", c);
		for(int j=0; j<M; j++){
			if(c[j] == '1')
				board[i][j] = true;
		}
	}

	bfs(0, 0);
	printf("%d", cnt+1);
}