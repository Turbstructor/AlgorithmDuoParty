// baekjoon 8979 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1000

typedef struct _TAG_DATA{
	int g, s, c;
}__DATA

bool comp(const __DATA &a, const __DATA &b){
	if (a.g > b.g) {
		return true;
	}
	if (a.g == b.g) {
		if (a.s > b.s) {
			return true;
		}
		if (a.s == b.s) {
			return a.c < b.c;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {

}