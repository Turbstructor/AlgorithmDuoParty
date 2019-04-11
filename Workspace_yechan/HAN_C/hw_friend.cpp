// hw_friend yechan
#include <stdio.h>
#include <stdlib.h>

int N, data[10001], S[10001];
bool visited[10001];

int main() {
	int i, j;
	scanf("%d", &N);
	for (i=0; i<N; i++)
		scanf("%d", &S[i]);

	int count=0;
	bool ispossible=true;
	for (i=N-1; i>=0; i--) {
		count=0;
		for (j=0; j<N; j++) {
			if (!visited[j]) {
				count++;
				if (S[i] == count-1) {
					visited[j]=true;
					data[i]=j+1;
					break;
				}
			}
		}
		if (j == N) {
			ispossible=false;
			break;
		}
	}

	if (ispossible) {
		for (i=0; i<N; i++) {
			printf("%d ", data[i]);
		}
	}
	else {
		printf("-1\n");
	}

	return 0;
}