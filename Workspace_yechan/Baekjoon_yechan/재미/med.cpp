#include <cstdio>
#include <algorithm>
#include <ctime>
using namespace std;
#define MAX_N 10001
#define MAX_M 100001
typedef struct _Tag_MedPair{
	int m1, m2;
}__MP;

int N, M, opt_days, cnteat[MAX_N], eats[MAX_N];
bool med[MAX_N][MAX_N];
__MP days[MAX_M];

void find_day(int d)
{
	int m1 = days[d].m1;
	int m2 = days[d].m2;
	if(cnteat[m1] && cnteat[m2]){
		opt_days = max(opt_days, d);
		return;
	}
	if(!cnteat[m1]){
		if(!eats[m1]){
			for(int i=1; i<=N; i++)
				if(med[m1][i]) cnteat[i]++;
		}
		eats[m1]++;
		find_day(d+1);
		eats[m1]--;
		if(!eats[m1]){
			for(int i=1; i<=N; i++)
				if(med[m1][i]) cnteat[i]--;
		}else{
			return;
		}
	}
	if(!cnteat[m2]){
		if(!eats[m2]){
			for(int i=1; i<=N; i++)
				if(med[m2][i]) cnteat[i]++;
		}
		eats[m2]++;
		find_day(d+1);
		eats[m2]--;
		if(!eats[m2]){
			for(int i=1; i<=N; i++)
				if(med[m2][i]) cnteat[i]--;
		}else{
			return;
		}
	}
}

int main()
{
	scanf("%d", &N);
	scanf("%d", &M);
	for(int i=1; i<=M; i++){
		scanf("%d %d", &days[i].m1, &days[i].m2);
		med[days[i].m1][days[i].m2]=true;
		med[days[i].m2][days[i].m1]=true;
	}
	find_day(1);
	printf("%d", opt_days);
	return 0;
}