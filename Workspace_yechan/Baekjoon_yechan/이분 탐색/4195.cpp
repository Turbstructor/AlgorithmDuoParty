// baekjoon 4195 yechan
#include <cstdio>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
#define MAX_N 100000
int T, n, parent[MAX_N+1];

int find(int a) {
	if (parent[a] < 0) return a;
	return parent[a] = find(parent[a]);
}

int merge(int a, int b) {
	int u = find(a), v = find(b);
	if (u < v) swap(u, v);
	if (u != v) {
		parent[u] += parent[v];
		parent[v] = u;
	}
	return -parent[u];
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		char f1[22], f2[22];
		int num = 1;
		fill(parent, parent+n+1, -1);
		unordered_map<string, int> umap;
		for (int i=0; i<n; i++) {
			scanf("%s %s", f1, f2);
			if (!umap.count(f1)) umap[f1] = num++;
			if (!umap.count(f2)) umap[f2] = num++;
			printf("%d\n", merge(umap[f1], umap[f2]));
		}
	}
	return 0;
}