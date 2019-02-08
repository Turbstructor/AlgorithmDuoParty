// // baekjoon 2003 yechan
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// const int MAX_N = 10001;

// int N, M, A[MAX_N], s, e, d, ret;

// int main() {
// 	scanf("%d%d", &N, &M);
// 	for (int i=1; i<=N; i++) {
// 		scanf("%d", &A[i]);
// 		A[i]+=A[i-1];
// 	}
// 	s=e=1;
// 	while (e <= N) {
// 		d = A[e]-A[s-1];
// 		if (d == M) ret++;
// 		if (d >= M) s++;
// 		else e++;
// 	}
// 	printf("%d\n", ret);
// 	return 0;
// }
// 

#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, a[10001], sum, result, s;

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", a+i);
        sum += a[i];
        while(sum > m && s < n) 
            sum -= a[s++];
        if(sum == m)
            result++;
    }
    
    printf("%d\n", result);
    return 0;
} 