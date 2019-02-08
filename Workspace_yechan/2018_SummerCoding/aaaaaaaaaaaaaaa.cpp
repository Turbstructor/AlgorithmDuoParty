#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(string s) {
    int answer=1;
    int slen = s.length();
    vector<vector<int>> dp(slen+1, vector<int>(slen+1, 0));
    for (int i=0; i<slen; i++) {
    	for (int j=0; j<slen; j++) {
    		if (s[i] == s[slen-j-1]) dp[i+1][j+1] = dp[i][j]+1;
    		if ((i+j+2 > slen) && (i+j+2-slen) == dp[i+1][j+1]) answer = max(answer, dp[i+1][j+1]);
    	}
    }
    for (int i=0; i<slen; i++) {
        for (int j=0; j<slen; j++) {
            cout << dp[i+1][j+1];
        }
        cout << endl;
    }
    return answer;
}

int main() {
	string s;
	cin >> s;
	cout << solution(s) << endl;
	return 0;
}
