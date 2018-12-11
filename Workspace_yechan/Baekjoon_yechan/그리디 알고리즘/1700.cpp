// baekjoon 1700 yechan
#include <cstdio>
#include <vector>
using namespace std;
#define MAX_K 101

int N, K, result, data[MAX_K];
vector<int> plug;

int main() {
	scanf("%d %d", &N, &K);
	for (int i=0; i<K; i++) scanf("%d", &data[i]);

	for (int i=0; i<K; i++) {
		int flag = 0;
		for (int p=0; p < plug.size(); p++)
			if (plug[p] == data[i]) flag = 1;
		if (flag) 	continue;

		if (plug.size() < N) { plug.push_back(data[i]); continue; }

		int maxValue=0, maxIdx=0;
		for (int p=0; p<plug.size(); p++) {

			int tmpValue = 1e9;
			for (int j=i+1; j<K; j++) {
				if (plug[p]==data[j]) { tmpValue = j; break; }
			}
			if (tmpValue > maxValue) {
				maxValue = tmpValue;
				maxIdx = p;
			}
		}
		result++;
		plug[maxIdx]=data[i];
	}
	printf("%d", result);
}