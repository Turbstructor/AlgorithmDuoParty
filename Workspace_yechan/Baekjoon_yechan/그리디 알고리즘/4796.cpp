// baekjoon 4796 yechan
#include <cstdio>
using namespace std;

int P, L, V, result, count=1;

int main() {
	do {
		// scanf("%d %d %d", &P, &L, &V);
		scanf("%d %d %d", &P, &L, &V);
		if (P || L || V){
			result=(V/L)*P;
			if (V%L < P){
				result += V%L;
			}
			else {
				result += P;
			}
			printf("Case %d: %d\n", count, result);
			count++;
		}
	} while(P || L || V);
	return 0;
}