// Summer Coding Number_Game yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> A_match, B_match;
vector<bool> visited;

bool dfs(int a) {
	visited[a] = true;
	for (int b: adj[a]) {
		if (!B_match[b] || !visited[B_match[b]] && dfs(B_match[b])) {
			A_match[a] = b;
			B_match[b] = a;
			return true;
		}
	}
	return false;
}

int solution(vector<int> A, vector<int> B) {
	int N = A.size();
	
	adj = vector<vector<int>>(A.size()+1);
	for (int i=0; i < adj.size(); i++) {
		for (int j=0; j<B.size(); j++) {
			if (B[j] > A[i]) {
				adj[i+1].push_back(j+1);
			}
		}
	}

	int cnt = 0;
	A_match = vector<int>(N+1, 0);
	B_match = vector<int>(N+1, 0);

	for (int i=1; i<=N; i++) {
		visited = vector<bool>(N+1, false);
		if (dfs(i)) cnt++;
	}
	return cnt;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<int> A(N);
	vector<int> B(N);

	for (int i=0; i<N; i++)
		scanf("%d", &A[i]);
	for (int i=0; i<N; i++)
		scanf("%d", &B[i]);
	printf("%d\n", solution(A, B));
}