#include <cstdio>
#include <algorithm>
using namespace std;

int fibo[500];

int FIB2(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	fibo[0]=0, fibo[1]=1;
	for (int i=2; i<=n; i++) {
		fibo[i] = fibo[i-1] + fibo[i-2];
	}
	return fibo[n];
}

int main() {
	while(1) {
		int N;
		printf("Enter a Number (up to 92)\n");
		scanf(" %d", &N);
		printf("%d\n", fibo[N]);
	}
	return 0;
}