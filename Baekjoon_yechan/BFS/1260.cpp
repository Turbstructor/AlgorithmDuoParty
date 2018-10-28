// baekjoon 1260 yechan
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
bool visited[1001];
bool vertex[1001][1001];

void dfs(int curr)
{
	visited[curr] = true;
	printf("%d", curr);
	for(int i=0; i<N+1; i++){
		if(vertex[curr][i] && !visited[i]){
			printf(" ");
			dfs(i);
		}
	}
}

void bfs(int curr)
{
	queue<int> q;
	q.push(curr);
	while(!q.empty()){
		int p = q.front();
		q.pop();
		if(!visited[p]){
			if(p == curr) 	printf("%d", p);
			else 			printf(" %d", p);
			visited[p] = true;
			for(int i=0; i<N+1; i++){
				if(vertex[p][i] && !visited[i]) q.push(i);
			}
		}
	}
}

int main()
{
	int u,v;
	scanf("%d %d %d", &N, &M, &V);
	for(int i=0; i<M; i++){
		scanf("%d %d", &u, &v);
		vertex[u][v] = true;
		vertex[v][u] = true;
	}
	fill(visited+1, visited+N+1, false);
	dfs(V);
	printf("\n");
	fill(visited+1, visited+N+1, false);
	bfs(V);
}