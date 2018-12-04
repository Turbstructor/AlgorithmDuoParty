// baekjoon 10448 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_T 46

int T, N, triangle[MAX_T];

int main() {
	for (int i=1; i<MAX_T; i++) triangle[i] = i*(i+1)/2;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		int flag = 0;
		for (int i=1; i<MAX_T; i++) {
			for (int j=1; j<MAX_T; j++) {
				int tmp = triangle[i]+triangle[j];
				for (int k=1; k<MAX_T; k++) {
					if(tmp + triangle[k] == N) flag=1;
				}
			}
		}
		printf("%d\n", flag);
	}
	return 0;
}