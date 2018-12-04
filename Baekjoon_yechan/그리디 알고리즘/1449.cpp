// baekjoon 1449 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, L, prevous, data[1001], result=1;

int main() {
	scanf("%d %d", &N, &L);
	for (int i=0; i<N; i++) {
		scanf("%d", &data[i]);
	}

	sort(data, data+N);
	for (int i=0; i<N; i++) {
		if (!prevous) {
			prevous=data[i];
		}
		if (data[i]-prevous >= L) {
			prevous=data[i];
			result++;
		}
	}

	printf("%d", result);
	return 0;
}