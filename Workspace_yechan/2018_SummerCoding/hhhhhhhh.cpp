#include <cstdio>
#include <vector>
using namespace std;

int MOD = 20170805;

vector<vector<int> > dp;
vector<vector<int> > g_city_map;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
// n =가로, m=세로

int find_dp(int x, int y, int dx, int dy) {
	if (x < 0 || y < 0) return 0;
	if (g_city_map[x][y] == 1) return 0;
	if (g_city_map[x][y] == 0) return dp[x][y];
	else return find_dp(x+dx, y+dy, dx, dy);
}

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    g_city_map = city_map;
    dp = vector<vector<int> >(m, vector<int>(n, 0));

    dp[0][0]=1;
    for (int i=0; i<m; i++) {
    	for (int j=0; j<n; j++) {
    		if (i == 0 && j == 0) continue;
    		if (g_city_map[i][j]==1) continue;
			dp[i][j] = (find_dp(i, j-1, 0, -1) + find_dp(i-1, j, -1, 0)) % MOD;
		}
    }
    answer = dp[m-1][n-1];
    return answer;
}

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	vector<vector<int> > city_map(m, vector<int>(n));
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			scanf("%d", &city_map[i][j]);

	printf("%d\n", solution(m, n, city_map));
}