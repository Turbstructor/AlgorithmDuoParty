// baekjoon 2872 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=300001;
int N, x, cnt, start=1;

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &x);
		if (x==start) start++;
		else cnt++;
	}
	printf("%d", cnt);
	return 0;
}	