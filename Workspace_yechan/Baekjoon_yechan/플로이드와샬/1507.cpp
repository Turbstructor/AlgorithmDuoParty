// baekjoon 1507
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321
int main(void){
	int n;
	cin >> n;

	int node[20][20];
	int load_on[20][20];

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			if(i == j) 	load_on[i][j] = 0;
			else 		load_on[i][j] = 1;
		}
	}
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> node[i][j];
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(i==j || i == k || j == k) continue;
				if(node[i][j] == (node[i][k] + node[k][j])){
					load_on[i][j] = 0;
					load_on[j][i] = 0;
				}
				if(node[i][j] > (node[i][k] + node[k][j])){
					cout << -1;
					return 0;
				}
			}
		}
	}

	int result = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if(load_on[i][j]){
				result += node[i][j];
			}
		}
	}

	cout << result;
}