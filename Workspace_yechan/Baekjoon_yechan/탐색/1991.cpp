// baekjoon 1991 yechan
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Tree{
public:
	int N; // 정점의 개수
	vector<int> parent;
	vector<vector<int>> childern;

	Tree(): N(0){}
	Tree(int n): N(n){
		parent.resize(N, -1);
		childern.resize(N);
	}

	void print() {
		for (int i=0; i<N; i++) {
			printf("Node %d: parent(", i);
			if (parent[i] != -1) printf("%d", parent[i]);
			else printf("-");
			printf("), childern(");
			for (int j=0; j<childern[i].size(); j++) {
				printf("%d", childern[i][j]);
				if (j < childern[i].size()-1) printf(", ");
			}
			printf(")\n");
		}
	}

	void preorder_traversal(int root) {
		printf("%c", root);
		if (childern[root].size() == 0) return;
		if (childern[root][0] != '.') preorder_traversal(childern[root][0]);
		if (childern[root][1] != '.') preorder_traversal(childern[root][1]);
	}

	void inorder_traversal(int root) {
		if (childern[root].size() == 0) {
			printf("%c", root);
		}
		else {
			if (childern[root][0] != '.') inorder_traversal(childern[root][0]);
			printf("%c", root);
			if (childern[root][1] != '.') inorder_traversal(childern[root][1]);
		}
	}

	void postorder_traversal(int root) {
		if (childern[root].size() == 0) {
			if (childern[root][0] != '.') postorder_traversal(childern[root][0]);
			if (childern[root][1] != '.') postorder_traversal(childern[root][1]);
		}
		printf("%c", root);
	}
};

class Graph {
public:
	int N;
	vector<vector<int>> adj;

	Graph(): N(0){}
	Graph(int n): N(n) { adj.resize(N); }

	void addEdge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void sortList() {
		for (int i=0; i<N; i++)
			sort(adj[i].begin(), adj[i].end());
	}

	Tree makeTree(int root) {
		Tree T(N);
		vector<bool> visited(N, false);
		queue<int> Q;
		visited[root] = true;
		Q.push(root);
		while (!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			for (int next: adj[curr]) {
				if (!visited[next]) {
					visited[next] = true;
					Q.push(next);
					T.parent[next] = curr;
					T.childern[curr].push_back(next);
				}
			}
		}
		return T;
	}
};

int main() {
	Graph G(7);
	G.addEdge('A', 'B');
	G.addEdge('A', 'C');
	G.addEdge('B', 'D');
	G.addEdge('B', '.');
	G.addEdge('C', 'E');
	G.addEdge('C', 'F');
	G.addEdge('E', '.');
	G.addEdge('E', '.');
	G.addEdge('F', '.');
	G.addEdge('F', 'G');
	G.addEdge('D', '.');
	G.addEdge('D', '.');
	G.addEdge('G', '.');
	G.addEdge('G', '.');
    Tree T = G.makeTree('A');
    T.preorder_traversal('A');
    puts("");
    T.inorder_traversal('A');
    puts("");
    T.postorder_traversal('A');
    puts("");
}