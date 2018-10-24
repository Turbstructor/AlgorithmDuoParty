// baekjoon 1068
#include <stdio.h>
using namespace std;

void deleteChildNode(int num);
void findLeafNode(int num);

int n;
int* tree;
int result = 0;

int main(void)
{
	scanf("%d", &n);

	tree = new int[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &tree[i]);

	int deleteNode;
	scanf("%d", &deleteNode);

	deleteChildNode(deleteNode);

	for (int i = 0; i < n; ++i)
		if(tree[i] != -1)
			findLeafNode(i);

	printf("%d", result);
	return 0;
}

void deleteChildNode(int num){
	tree[num] = -1;
	for (int i = 0; i < n; ++i){
		if(tree[i] == num){
			tree[i] = -1;
			deleteChildNode(i);
		}
	}
}

void findLeafNode(int num){
	for (int i = 0; i < n; ++i)
		if(tree[i] == num)
			return;
	result++;
}