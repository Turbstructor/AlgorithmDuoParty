// baekjoon 9465 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 100000;
int n, sticker[2][MAX], dp[MAX][3];

// pos : 0 왼쪽 안띰, 1 왼쪽 상단 스티커 띤 상태, 2 왼쪽 하단 스티커 띤 상태
int calSticker(int x, int pos){
	if(x == n) return 0; // base case
	if(dp[x][pos] != -1) return dp[x][pos];

	int tmp = calSticker(x+1, 0);
	if(pos != 1)	tmp = max(tmp, calSticker(x+1, 1)+sticker[0][x]);
	if(pos != 2)	tmp = max(tmp, calSticker(x+1, 2)+sticker[1][x]);
	dp[x][pos] = tmp;
	return tmp;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		scanf("%d", &n);
		for(int j=0; j<2; j++) for(int z=0; z<n; z++)
			scanf("%d", &sticker[j][z]);

		for(int j=0; j<n; j++) for(int z=0; z<3; z++)
			dp[j][z] = -1;
		int rst = calSticker(0,0); // 시간 초과
		printf("%d\n", rst);
	}
}