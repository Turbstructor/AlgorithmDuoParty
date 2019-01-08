// baekjoon 1712 yechan
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
ll A, B, C, result;

int main() {
	scanf("%lld%lld%lld", &A, &B, &C);
	if (B >= C) puts("-1");
	else {
		result = ceil((double)(A+1)/(C-B));
		printf("%lld\n", result);
	}
	return 0;
}