// baekjoon 2503 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
bool visited[1000];

bool CheckNumber(int x, int y, int z, int n1, int n2, int n3, int strike, int ball) {
	int stmp = 0, btmp = 0;
	if (x == n1) stmp++;
	if (y == n2) stmp++;
	if (z == n3) stmp++;

	if (x == n2) btmp++;
	if (x == n3) btmp++;

	if (y == n1) btmp++;
	if (y == n3) btmp++;

	if (z == n1) btmp++;
	if (z == n2) btmp++;

	if (stmp==strike && btmp==ball) return true;
	return false;
}


int main() {
	for(int i=1; i<10; i++) {
		for (int j=1; j<10; j++) {
			for (int k=1; k<10; k++) {
				if(i!=j && j!=k && i!=k){
					visited[i*100+j*10+k]=true;
				}
			}
		}
	}
	scanf("%d", &N);

	while (N--) {
		int num, strike, ball;
		scanf("%d %d %d", &num, &strike, &ball);
		int n1 = num/100, n2 = (num/10)%10, n3 = num%10;
		for (int i=1; i<10; i++) {
			for (int j=1; j<10; j++) {
				for (int k=1; k<10; k++) {
					if(visited[i*100+j*10+k]) {
						if(!CheckNumber(i, j, k, n1, n2, n3, strike, ball))
							visited[i*100+j*10+k]=false;
					}
				}
			}
		}
	}

	int result=0;
	for (int i=0; i<1000; i++)
		if (visited[i]) result++;

	printf("%d\n", result);

	return 0;
}