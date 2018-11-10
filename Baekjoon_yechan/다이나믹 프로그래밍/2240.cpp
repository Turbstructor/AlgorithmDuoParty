// baekjoon 2240
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_T 1001
#define MAX_W 31

int T, W, tree[MAX_T];
int dp[MAX_W][2];

// int eatjadoo(int p, int w, int t)
// {
// 	if(t > T) return 0;
// 	if(~dp[w][t]) return dp[w][t];
// 	int tmp = 0;
// 	tmp = eatjadoo(p,w,t+1);
// 	if(w <= W) tmp = max(tmp, eatjadoo( p%2+1, w+1, t+1));
// 	if(p == tree[t]) tmp++;
// 	dp[w][t] = tmp;
// 	return tmp;
// }

int main()
{
	scanf("%d %d", &T, &W);
	for(int i=1; i<=T; i++)
		scanf("%d", &tree[i]);

	// for(int i=0; i<MAX_W; i++)
	// 	for(int j=0; j<MAX_T; j++)
	// 		dp[i][j] = -1;

	for(int i=1; i<=T; i++){
		if(tree[i] == 1) dp[0][0]++;

		for(int j=1; j<=W; j++){
			dp[j][0] = dp[j-1][1]; 
			dp[j][1] = dp[j-1][0];
			if(tree[i] == 1) 	dp[j][0]++;
			else 			 	dp[j][1]++;
		}
	}

	int max_fruit = 0;
	for(int j=0; j<=W; j++)
		for(int i=0; i<2; i++)
			max_fruit = max(max_fruit, dp[j][i]);

	// int result = eatjadoo(1, 0, 1);
	printf("%d", max_fruit);
	return 0;
}