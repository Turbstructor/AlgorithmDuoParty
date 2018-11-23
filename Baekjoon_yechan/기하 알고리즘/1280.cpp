// baekjoon 1280 yechan (*** TIME LIMIT ***)
#include <cstdio>
#include <vector>
#define MAX_N 200000
#define DIV_NUM 1000000007

using namespace std;

typedef long long ll;

ll sum(vector<ll> &tree, int i) {
	ll ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(vector<ll> &tree, int i, ll diff) {
	while ( i < tree.size()) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int main() {
	int n;
	ll tmp, result = 0, max_sum = 0, dist = 0;
	ll tmp_left_num, tmp_tree;
	scanf("%d", &n);

	vector<ll> tree(MAX_N+1);
	vector<ll> tree_num(MAX_N+1);

	scanf("%lld", &tmp);
	update(tree, tmp, tmp);
	update(tree_num, tmp, 1);
	max_sum += tmp;

	scanf("%lld", &tmp);
	tmp_left_num = sum(tree_num, tmp);
	tmp_tree = sum(tree, tmp);
	dist = tmp*tmp_left_num - tmp_tree;
	dist = dist + max_sum - tmp_tree - tmp*(1-tmp_left_num);
	result = dist;
	update(tree, tmp, tmp);
	update(tree_num, tmp, 1);
	max_sum += tmp;

	for (int i = 2; i < n; i++) {
		scanf("%lld", &tmp);
		tmp_left_num = sum(tree_num, tmp);
		tmp_tree = sum(tree, tmp);
		dist = tmp*tmp_left_num - tmp_tree;
		dist = dist + max_sum - tmp_tree - tmp*(i-tmp_left_num);
		result = (result*(dist%DIV_NUM))%DIV_NUM;
		update(tree, tmp, tmp);
		update(tree_num, tmp, 1);
		max_sum += tmp;
	}
	printf("%lld", result);
}