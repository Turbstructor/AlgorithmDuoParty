// baekjoon 11055 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 1000
int N, maximum_A;
int A[MAX_N];
int valA[MAX_N];

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)	scanf("%d", &A[i]);
	valA[0]=A[0];
	maximum_A=A[0];
	for(int i=1; i<N; i++){
		int tmp = A[i];
		for(int j=0; j<i; j++){
			if(A[j] < A[i]) tmp = max(tmp, valA[j]+A[i]);
		}
		valA[i] = tmp;
		maximum_A = max(maximum_A, tmp);
	}
	printf("%d", maximum_A);
}