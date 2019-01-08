// baekjoon 1967 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 10001

struct Vertex{
	int v, w;
	Vertex(){}
	Vertex(int v, int w):v(v), w(w){}
};

struct Node{
	vector<Vertex> child;
};

int N, a, b, w, result;
Node node[MAX_N];

int dfs(int root) {
	int v1=0, v2=0, ret=0;
	for (Vertex nx : node[root].child) {
		ret = dfs(nx.v) + nx.w;
		if (ret > v1) { v2 = v1; v1 = ret; }
		else if (ret > v2) v2 = ret;
	}
	result = max(result, v1+v2);
	return max(v1, v2);
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d%d%d", &a, &b, &w);
		node[a].child.push_back(Vertex(b,w));
	}
	dfs(1);
	printf("%d\n", result);
	return 0;
}