// baekjoon 11052 yechan 카드사기 
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_KARD 1001
int price[MAX_KARD];
int knum[MAX_KARD];
int main()
{
	int N;
	cin >> N;
	knum[0] = 0;
	price[0] = 0;
	for (int i = 1; i < N+1; ++i) cin >> price[i];

	for (int i = 1; i < N+1; ++i){
		int tmp = 0;
		for (int j = 0; j < i+1; ++j){
			tmp = max(tmp,knum[j]+price[i-j]);
		}
		knum[i] = tmp;
	}
	cout << knum[N];
}