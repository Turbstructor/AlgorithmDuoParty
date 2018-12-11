// baekjoon 10984 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int T, N;
float C, G, totalC, totalG;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		totalC = totalG = 0;
		for (int i=0; i<N; i++) {
			scanf("%f %f", &C, &G);
			totalC += C;
			totalG += G*C;
		}
		printf("%d %.1f\n", (int)totalC, totalG/totalC);
	}

	return 0;
}