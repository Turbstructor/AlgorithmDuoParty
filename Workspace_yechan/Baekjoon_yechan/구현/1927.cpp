// baekjoon 1927 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int N;

int main() {
	scanf("%d", &N);
	priority_queue<int, vector<int>, greater<int>> PQ;
	while (N--) {
		int x; scanf("%d", &x);
		if (x) PQ.push(x);
		else {
			if (PQ.empty()) puts("0");
			else printf("%d\n", PQ.top()), PQ.pop();
		}
	}

	return 0;
}