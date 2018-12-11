#include <cstdio>
#include <algorithm>
using namespace std;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int N, result;
char board[50][51];

int EatCandy(int x, int y, int d) {
	int tmp=1;
	char candy=board[x][y];
	while(1) {
		x=x+dx[d], y=y+dy[d];
		if (x < 0 || x >= N || y < 0 || y >= N) break;
		if (candy != board[x][y]) break;
		tmp++;
	}
	return tmp;
}

int CheckBoard() {
	int tmp=0;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			for (int d=0; d<4; d++)
				tmp = max(tmp, EatCandy(i, j, d));
	return tmp;
}

void ChangeBoard(int x1, int y1, int x2, int y2) {
	char tmp=board[x1][y1];
	board[x1][y1]=board[x2][y2];
	board[x2][y2]=tmp;
}

int main() {
	scanf("%d",&N);
	for (int i=0; i<N; i++)
		scanf("%s", board[i]);

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			for (int d=0; d<2; d++) {
				int x = i + dx[d], y = j + dy[d];
				if (x < 0 || x >= N || y < 0 || y >= N) continue;
				ChangeBoard(i, j, x, y);
				result = max(result, CheckBoard());
				ChangeBoard(i, j, x, y);
			}
		}
	}
	printf("%d\n", result);
	return 0;
}

/* reference Code (Short Time)
#include <cstdio>
#include <algorithm>
using namespace std;
int n,sol;
char arr[52][52];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int func(int cx,int cy,int nx,int ny) {
	if(!arr[cy][cx]) return 0;
	if(arr[cy][cx]==arr[cy+ny][cx+nx]) return 1+func(cx+nx,cy+ny,nx,ny);
	else return 1;
}
int main() {
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++) gets(&arr[i][1]);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			sol=max(sol,func(j,i,-1,0)+func(j,i,1,0)-1);
			sol=max(sol,func(j,i,0,-1)+func(j,i,0,1)-1);
			for(int k=0;k<4;k++) {
				swap(arr[i][j],arr[i+dy[k]][j+dx[k]]);
				sol=max(sol,func(j,i,-1,0)+func(j,i,1,0)-1);
				sol=max(sol,func(j,i,0,-1)+func(j,i,0,1)-1);
				swap(arr[i][j],arr[i+dy[k]][j+dx[k]]);
			}
		}
	}
	printf("%d",sol);
	return 0;
}
*/