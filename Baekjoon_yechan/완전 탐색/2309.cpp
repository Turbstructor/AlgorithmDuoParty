// baekjoon 2309 yechan
#include <cstdio>
#include <algorithm>

int main() {
	int height[9];
	int total=0;
	for (int i=0; i<9; i++) {
		scanf("%d", &height[i]);
		total += height[i];
	}
	std::sort(height, height+9);
	int x, y;
	for (int i=0; i<9; i++) {
		int tmp = total-height[i];
		for (int j=i+1; j<9; j++) {
			if (tmp-height[j] == 100) {
				x=i;
				y=j;
			}
		}
	}
	for (int i=0; i<9; i++)
		if (i != x && i != y)
			printf("%d\n", height[i]);
}