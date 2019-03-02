// baekjoon 1713 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=20;
const int MAX_NUM=101;
struct picture{
	int vote;
	int stdNum;
	int day;
	picture():picture(0,0,0){};
	picture(int v, int s, int d):vote(v), stdNum(s), day(d){}
};

bool cmpSN(const picture &a, const picture &b) {
	return a.stdNum < b.stdNum;
}
bool cmpV(const picture &a, const picture &b) {
	if (a.vote == b.vote) {
		return a.day>b.day;
	}
	return a.vote>b.vote;
}

int N, K, x;
int main() {
	scanf("%d%d", &N, &K);
	for (int i=0; i<K; i++) {
		scanf("%d", &x);
	}
	return 0;
}