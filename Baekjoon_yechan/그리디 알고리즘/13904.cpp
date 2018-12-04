// baekjoon 13904 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
#define MAX_N 1001

typedef pair<int, int> P;

int N, d, w;

int main() {
	scanf("%d", &N);
	priority_queue<P, vector<P>, less<P>> pq;
	priority_queue<int, vector<int>, less<int>> q;
	for (int i=0; i<N; i++) {
		scanf("%d %d", &d, &w);
		pq.push(P(d, w));
	}

	int prev = pq.top().first;
	int result = 0;
	while (prev) {
		while (!pq.empty() && pq.top().first >= prev) {
			q.push(pq.top().second);
			pq.pop();
		}
		if (!q.empty()){
			result += q.top();
			q.pop();
		}
		prev--;
	}
	printf("%d", result);
	return 0;
}