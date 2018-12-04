// baekjoon 2231 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1000000

int N;

int getDivSum(int num) {
	int tmp=num;
	while (num) {
		tmp += num%10;
		num /=10;
	}
	return tmp;
}

int main() {
	scanf("%d", &N);
	int result=0;

	for (int i=1; i <= MAX_N; i++) {
		if(getDivSum(i) == N) {
			if(!result) result = i;
		}
	}
	printf("%d", result);

	return 0;
}