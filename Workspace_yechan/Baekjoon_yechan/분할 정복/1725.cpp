// baekjoon 2104 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, A[100001];

// [start, end)
ll histogram(ll start, ll end) {
	if (start == end) return 0;
	if (start+1 == end) return A[start];
	ll mid = (start + end) / 2;
	ll result = max(histogram(start, mid), histogram(mid, end));

	ll w =1, h = A[mid], l=mid, r=mid;
	while (r-l+1 < end-start) {
		ll p = l>start ? min(A[l-1], h) : -1;
		ll q = r<end-1 ? min(A[r+1], h) : -1;
		if (p >= q) {
			h = p;
			l--;
		}
		else {
			h = q;
			r++;
		}
		result = max(result, (ll)(++w*h));
	}
	return result;
}

int main() {
	scanf("%lld", &N);
	for (int i=0; i<N; i++)
		scanf("%lld", A+i);
	printf("%lld", histogram(0, N));
	return 0;
}