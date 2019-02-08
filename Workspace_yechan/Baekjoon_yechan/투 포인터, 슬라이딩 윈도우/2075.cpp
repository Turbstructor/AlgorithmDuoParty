// baekjoon 2075 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int N, x;

int main() {
	priority_queue<int, vector<int>, greater<int> > pq;
	scanf("%d", &N);
	for (int i=0; i<N; i++){
		scanf("%d", &x);
		pq.push(x);
	}

	for (int i=0; i<N*(N-1); i++) {
		scanf("%d", &x);
		pq.push(x);
		pq.pop();
	}
	printf("%d\n",pq.top());
	return 0;
}