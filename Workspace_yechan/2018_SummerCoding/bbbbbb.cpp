#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int Aidx = 0, Bidx = 0;
    while (Aidx < A.size() && Bidx < B.size()) {
        while (A[Aidx] >= B[Bidx]) { 
            Bidx++;
            if( Bidx >= B.size()) break;
        }
        if(Bidx >= B.size()) break;
        printf("%d %d\n", Aidx, Bidx);
        Aidx++;
        Bidx++;
    }
    return answer = Aidx;
}

int main() {
    int N; scanf("%d", &N);
    vector<int> A;
    vector<int> B;
    for (int i=0; i<N; i++) {
        int x; scanf("%d", &x);
        A.push_back(x);
    }
    for (int i=0; i<N; i++) {
        int x; scanf("%d", &x);
        B.push_back(x);
    }
    printf("%d\n",solution(A, B));
}