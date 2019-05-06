// baekjoon 2629 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_G=40001;

int N, K, x, weight[31];
bool visited[MAX_G], tmp[MAX_G];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &weight[i]);
	sort(weight, weight+N);

	visited[0]=tmp[0]=true;
	for (int i=0; i<N; i++) {
		for (int j=0; j<MAX_G; j++) {
			if (j - weight[i] > 0) tmp[j-weight[i]] |= visited[j];
			if (weight[i] - j > 0) tmp[weight[i]-j] |= visited[j];
			if (j + weight[i] < MAX_G) tmp[j+weight[i]] |= visited[j];
		}
		memcpy(visited, tmp, sizeof(visited));
	}

	scanf("%d", &K);
	for (int i=0; i<K; i++) {
		scanf("%d", &x);
		if (visited[x]) printf("Y ");
		else printf("N ");
	}
	return 0;
}