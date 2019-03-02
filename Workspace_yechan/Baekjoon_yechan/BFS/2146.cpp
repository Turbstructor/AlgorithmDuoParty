// baekjoon 2146 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
const int MAX_N = 101;
const int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
typedef pair<int, int> P;
int N;
vector<P> land;
bool board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int main(){
	scanf("%d", &N);
	queue<P> q;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j]) 
				q.push(P(i,j));
		}
	}

	while (q.size()) {
		int qSize = q.size();
		while (qSize--) {
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			for (int d=0; d<4; d++) {
				i
			}
		}
	}

	return 0;
}