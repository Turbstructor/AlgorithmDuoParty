// baekjoon 2447 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 2187

int N;
char matrix[MAX_N][MAX_N+1];

void DividePrint(int x, int y, int num, char c) {
	if (num==1) {
		matrix[x][y] = c;
		return;
	}
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (i==1 && j==1) {
				DividePrint(x+i*(num/3), y+j*(num/3), num/3, ' ');
			}
			else {
				DividePrint(x+i*(num/3), y+j*(num/3), num/3, c);
			}
		}
	}

}

int main() {
	scanf("%d", &N);
	DividePrint(0, 0, N, '*');
	for (int i=0; i<N; i++)
		printf("%s\n", matrix[i]);
	return 0;
}