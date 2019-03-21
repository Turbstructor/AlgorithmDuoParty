// algo postech Assignment #3 1.cpp
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MAX_N=3001;
const ll MAX_INF=0x3c3c3c3c3c3c3c3c;


int T, V, E;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &V, &E);
		ll ret = 0;
		vector<P> adj(V);
		vecotr<int> indegree()
		for (int i=0; i<V; i++) {
			ll u, v, w;
			scanf("%lld%lld%lld", &u, &v, &w);
			adj[u].push_back(P(v,w));
		}

	}
	return 0;
}