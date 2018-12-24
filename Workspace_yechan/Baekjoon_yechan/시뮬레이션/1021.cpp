// baekjoon 1021 yechan
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int N, M, data;
deque<int> dq;
deque<int>::iterator it;

int main() {
	scanf("%d%d", &N, &M);

	for (int i=1; i<=N; i++)
		dq.push_back(i);

	int index=0, count=0, left, right;

	for (int i=0; i<M; i++) {
		scanf("%d", &data);

		if (dq.front() == data) {
			dq.pop_front();
		}
		else {
			index = 1;
			for (it = dq.begin(); it < dq.end(); it++) {
				if (*it == data) {
					break;
				}
				index++;
			}
			left = index - 1;
			right = dq.size() - index + 1;

			if (left >= right) {
				for (int j=0; j < right; j++) {
					dq.push_front(dq.back());
					dq.pop_back();
				}
				count += right;
				dq.pop_front();
			}
			else if (left <= right){
				for (int j=0; j < left; j++) {
					dq.push_back(dq.front());
					dq.pop_front();
				}
				count += left;
				dq.pop_front();
			}
		}
	}

	printf("%d\n", count);

	return 0;
}