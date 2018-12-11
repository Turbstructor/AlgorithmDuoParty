#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;

    bool isNotPrime[246913] = {false};
    const int someNum = sqrt(246912);
    bool isPrime = false;

    for(int i = 2; i <= someNum; i++)
    {
        isPrime = true;
        for(int j = 2; j <= i/2; j++)
        {
            if(i % j == 0){ isPrime = false; break; }
        }
        for(int j = i * 2; isPrime && j <= 246912; j += i) isNotPrime[j] = true;
    }

    while(true)
    {
        cin >> n;
        if(n == 0) break;

        int cnt = 0;
        for(int i = n + 1; i <= n * 2; i++) if(!isNotPrime[i]) cnt++;

        cout << cnt << endl;

    }
    return 0;
}