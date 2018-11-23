// baekjoon 1074 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int R, C, N;

int div_pos(int r, int c, int n) {
	int tmp = 0;
	if(n == 1) {
		return r*2+c;
	}
	if(r >= pow(2,n-1)) {
		tmp += pow(2, n)*pow(2, n-1);
		r 	-= pow(2, n-1);
	}
	if(c >= pow(2,n-1)) {
		tmp += pow(2, n-1)*pow(2, n-1);
		c 	-= pow(2, n-1);
	}
	return tmp + div_pos(r, c, n-1);
}

int main() {
	scanf("%d %d %d", &N, &R, &C);
	printf("%d", div_pos(R,C,N));
	return 0;
}