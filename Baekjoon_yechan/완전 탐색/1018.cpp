// baekjoon 1018 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 51
int N, M, result=987654321;
char board[MAX_N][MAX_N];

void check(int sx, int sy) {
	int tmp=0;
	for (int i=sx; i<sx+8; i++) {
		for (int j=sy; j<sy+8; j++) {
			if ( (i+j)%2 == 0) {
				if (board[i][j] != 'W') tmp++;
			}
			else {
				if (board[i][j] != 'B') tmp++;
			}
		}
	}
	result = min(result, min(tmp, 64-tmp));
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++)
		scanf("%s", board[i]);

	for (int i=0; i<=N-8; i++) {
		for (int j=0; j<=M-8; j++) {
			check(i, j);
		}
	}
	printf("%d\n", result);
	return 0;
}