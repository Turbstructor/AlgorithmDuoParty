// baekjoon 1107 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M, result=987654321;
bool button[10];

void genNumber(int num, int curr_sum) {
	result=min(result, num+abs(curr_sum-N));
	if (num == 7) return;

	for (int i=0; i<10; i++)
		if (!button[i])
			genNumber(num+1, curr_sum*10+i);
}

int main() {
	int num = 100, b;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i=0; i<M; i++)
		scanf("%d", &b), button[b]=true;

	result=abs(num-N);
	for (int i=0; i<10; i++) {
		if (!button[i]) {
			genNumber(1, i);
		}
	}
	printf("%d", result);
	return 0;
}