// baekjoon 1780 yechan
#include <cstdio>
#include <algorithm>

using namespace std;
#define MAX_N 2187

int N, matrix[MAX_N][MAX_N], result[3];

bool CheckPaper(int x, int y, int num)
{
	int tmp = matrix[x][y];
	for (int i=x; i<x+num; i++)
		for (int j=y; j<y+num; j++)
			if (tmp != matrix[i][j])
				return false;
	return true;
}

void DividePaper(int x, int y, int num)
{
	if (CheckPaper(x, y, num)) {
		result[matrix[x][y]+1]++;
		return;
	}
	
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			DividePaper(x+i*(num/3), y+j*(num/3), num/3);
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf(" %d", &matrix[i][j]);

	DividePaper(0, 0, N);

	for (int i=0; i<3; i++)
		printf("%d\n", result[i]);

	return 0;
}
