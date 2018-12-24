// bakejoon 1158 yechan
#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
#define MAX_N 5001;

int N, M;
deque<int> dq;
deque<int>::iterator it;

int main() {
	printf("<");
	scanf("%d %d", &N, &M);
	for (int i=1; i<=N; i++) 
		dq.push_back(i);

	int index=0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<(M-1); j++)
			dq.push_back(dq.front()), dq.pop_front();
		printf("%d", dq.front());
		if (dq.size() != 1) printf(", ");
		dq.pop_front();
	}
	printf(">");
	return 0;
}
