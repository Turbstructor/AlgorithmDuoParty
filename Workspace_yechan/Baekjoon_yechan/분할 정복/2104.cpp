// baekjoon 2104 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, A[100001];

// [start, end)
ll divarray(ll start, ll end) {
	if (start == end) return 0;
	if (start+1 == end) return A[start]*A[start];
	ll mid = (start + end) / 2;
	ll result = max(divarray(start, mid), divarray(mid, end));

	ll w = A[mid], h = A[mid], l=mid, r=mid;
	while (r-l+1 < end-start) {
		ll p = l>start ? min(A[l-1], h) : -1;
		ll q = r<end-1 ? min(A[r+1], h) : -1;
		if (p >= q) {
			h = p;
			w += A[l-1];
			l--;
		}
		else {
			h = q;
			w += A[r+1];
			r++;
		}
		result = max(result, (ll)w*h);
	}
	return result;
}

int main() {
	scanf("%lld", &N);
	for (int i=0; i<N; i++)
		scanf("%lld", A+i);
	printf("%lld", divarray(0, N));
	return 0;
}