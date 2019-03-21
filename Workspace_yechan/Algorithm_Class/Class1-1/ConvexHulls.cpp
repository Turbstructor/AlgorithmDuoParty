#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX_N=100001;
const ll INF=100000000000LL;

struct Point {
	ll x, y;
	Point(){}
	Point(ll x, ll y):x(x), y(y){}
};

bool cmp_x(const Point& a, const Point& b) {
	return a.x < b.x;
}

bool cmp_y(const Point& a, const Point& b) {
	return a.y < b.y;
}

inline ll getDist(const Point& a, const Point& b) {
	return abs(a.x-b.x) + abs(a.y-b.y);
}

int T, N;
ll X, Y;
Point posX[MAX_N], posY[MAX_N];

ll bruthForce(int from, int to) {
	ll ret=INF;
	for (int i=from; i<to; i++)
		for (int j=i+1; j<=to; j++)
			ret = min(ret, getDist(posX[i], posX[j]));
	return ret;
}

ll closest(int from, int to) {
	if (to-from < 4) return bruthForce(from, to);

	int mid=(from+to)/2;
	ll diff = min(closest(from, mid), closest(mid, to));
	ll ret = diff;

	vector<int> v;
	for (int i=0; i<N; i++)
		if (abs(posY[i].x-posX[mid].x) < diff)
			v.push_back(i);

	for (int i=0; i<v.size()-1; i++) {
		for (int j=i+1; j<v.size(); j++) {
			if (posY[v[j]].y - posY[v[i]].y > diff) break;
			ret = min(ret, getDist(posY[v[i]], posY[v[j]]));
		}
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i=0; i<N; i++) {
			scanf("%lld %lld", &X, &Y);
			posX[i]=Point(X, Y);
			posY[i]=Point(X, Y);
		}
		sort(posX, posX+N, cmp_x);
		sort(posY, posY+N, cmp_y);
		printf("%lld\n", closest(0, N-1));
	}
	return 0;
}