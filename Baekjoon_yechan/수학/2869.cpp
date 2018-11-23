// baekjoon 2869 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int A, B, V, rst;

int main() {
	scanf("%d %d %d", &A, &B, &V);
	V -= A;
	if (V < 0) V=0;
	rst += (V+A-B-1)/(A-B) + 1;
	printf("%d", rst);
	return 0;
}