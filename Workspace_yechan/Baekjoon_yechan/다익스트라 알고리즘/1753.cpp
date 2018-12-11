// baekjoon 1753 yechan
#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
const int MAX_V = 20000;
const int INF = 1000000000;
typedef pair<int, int> P;

int main()
{
	int V, E, K;
	scanf("%d %d %d", &V, &E, &K);
	K--;
	vector<P> adj[MAX_V];
	for(int i=0; i<E; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u-1].push_back(P(v-1, w));
	}
	int dist[MAX_V];
	fill(dist, dist+MAX_V, INF);
	bool visited[MAX_V] = {0};
	priority_queue<P, vector<P>, greater<P>> PQ;
	dist[K] = 0;
	PQ.push(P(0, K));
	while(!PQ.empty()){
		int curr;
		do{
			curr = PQ.top().second;
			PQ.pop();
		}while(!PQ.empty() && visited[curr]);
		if(visited[curr]) break;
		visited[curr] = true;
		for(auto &p: adj[curr]){
			int next = p.first, d = p.second;
			if(dist[next] > dist[curr] + d){
				dist[next] = dist[curr] + d;
				PQ.push(P(dist[next], next));
			}
		}
	}
	for(int i=0; i<V; i++){
		if(dist[i] == INF) puts("INF");
		else printf("%d\n", dist[i]);
	}
}