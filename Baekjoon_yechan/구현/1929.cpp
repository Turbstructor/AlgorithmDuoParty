// baekjoon 1929 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1000001
int M, N, rst, minb;
bool prime[1000001];

int main() {
	scanf("%d %d", &M, &N);
	prime[1] = true;
	for(int i=2; i < 1000001; i++) {
		if(prime[i]) continue;
		for(int j=i+i; j<1000001; j+=i) {
			prime[j]=true;
		}
	}
	for(int i=M; i<=N; i++) {
		if(!prime[i]) printf("%d\n", i);
	}
}