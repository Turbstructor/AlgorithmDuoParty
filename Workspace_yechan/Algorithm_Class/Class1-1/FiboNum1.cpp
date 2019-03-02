#include <cstdio>
#include <algorithm>
using namespace std;

int FIB1(int n) {
	if (n==0) return 0;
	if (n==1) return 1;
	return FIB1(n-1)+FIB1(n-2);
}

int main() {
	while(1) {
		int N;
		printf("Enter a numer\n");
		scanf(" %d", &N);
		printf("%d\n", FIB1(N));
	}
	return 0;
}

/*
- Is it correct -> Base case, definition
- How mush time does it take, as a function of n?
- Can we do better
 */