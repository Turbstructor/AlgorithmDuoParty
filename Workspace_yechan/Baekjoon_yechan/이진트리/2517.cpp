// baekjoon 2517 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<int> v;

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		int x; scanf("%d", &x);
		int start = lower_bound(v.begin(), v.end(), x+1)- v.begin();
		printf("%d\n", v.size()-start+1);
		v.insert(v.begin()+start,x);
	}
	return 0;
}