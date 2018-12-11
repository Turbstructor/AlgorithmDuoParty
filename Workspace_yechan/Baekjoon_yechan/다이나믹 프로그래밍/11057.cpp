// baekjoon 11057 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 1000

int N;
int num[10][MAX_N];

int main()
{
	scanf("%d", &N);
	for(int i=0; i<10; i++) num[i][0]=1;
	for(int i=1; i<N; i++){
		num[0][i] = num[0][i-1]%10007;
		for(int j=1; j<10; j++){
			num[j][i] = (num[j-1][i] + num[j][i-1])%10007;
		}
	}
	int result=0;
	for(int i=0; i<10; i++)
		result += num[i][N-1];
	printf("%d", result%10007);
	return 0;
}