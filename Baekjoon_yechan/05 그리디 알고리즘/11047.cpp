// baekjoon 11047
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void)
{
	int N, K;
	int tmp = 0;
	int result = 0;
	cin >> N >> K;
	int *p = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> p[i];
	for (int i = 0; i < N; ++i){
		tmp = K/p[N-i-1];
		K -= tmp * p[N-i-1];
		result += tmp;
		if(K == 0) break;
	}
	cout << result;
	return 0;
}