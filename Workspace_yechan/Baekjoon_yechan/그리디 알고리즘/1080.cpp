// baekjoon 1080 yechan
#include <cstdio>
using namespace std;

int main(){
	int i, j, x, y, ans = 0, n, m;
	char a[51][51], b[51][51];
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) scanf("%s", a[i]);
	for (i = 0; i < n; i++) scanf("%s", b[i]);
	for (i = 0; i < n - 2; i++) {
		for(j = 0; j < m - 2; j++){
			if(a[i][j] == b[i][j]) continue;
			ans++;
			for (x = i; x < i + 3; x++) {
				for (y = j; y < j + 3; y++) {
					if(a[x][y] == '0') a[x][y] = '1';
					else a[x][y] = '0';
				}
			}
		}
	}
	for (i = 0; i < n; i++) for (j = 0; j < m; j++)
		if(a[i][j] != b[i][j]) { puts("-1"); return 0; }
	printf("%d", ans);
	return 0;
}