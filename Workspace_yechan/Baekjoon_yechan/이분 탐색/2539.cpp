// baekjoon 2539 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=1001;

int H, W, K, N, ret=1e6;
pair<int, int> paper[MAX_N];
bool visited[MAX_N];

int main() {
	scanf("%d%d", &H, &W);
	scanf("%d", &K);

	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d%d", &paper[i].second, &paper[i].first);
	sort(paper, paper+N);

	int left=0, right=1e6;
	while (left <= right) {
		int mid = (left + right) / 2;
		int num = 0;
		memset(visited, 0, sizeof(visited));
		for (int i=0; i<N; i++) {
			if (visited[i]) continue;
			num++;
			for (int j=i; j<N; j++)
				if (paper[i].first <= paper[j].first && paper[j].first < paper[i].first+mid && paper[i].second <= paper[j].second && paper[j].second < paper[i].second+mid)
					visited[j]=true;
		}
		if (num <= K) ret = min(ret, mid), right = mid-1;
		else left = mid+1;
	}
	printf("%d\n", ret);
	return 0;
}