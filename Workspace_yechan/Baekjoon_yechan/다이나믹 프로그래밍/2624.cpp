// baekjoon 2624 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> P;
const int MAX_N=100;
const int MAX_T=10001;

int T, N, cache[MAX_T];
P coins[MAX_N];

int main() {
	memset(cache, -1, sizeof(cache));
	scanf("%d%d", &T, &N);
	for (int i=0; i<N; i++)
		scanf("%d%d", &coins[i].first, &coins[i].second);
	findCoin()
	return 0;
}