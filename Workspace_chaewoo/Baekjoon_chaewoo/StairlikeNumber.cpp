#include<iostream>
using namespace std;

int main()
{
    unsigned long int endingDigits[10] = {0,1,1,1,1,1,1,1,1,1};
    unsigned long int newEndingDigits[10] = {0,0,0,0,0,0,0,0,0,0};

    int n;
    cin >> n;

    for(int i = 1 ; i < n ; i++)
    {
        newEndingDigits[0] = endingDigits[1];
        for(int j = 1 ; j <= 8; j++) newEndingDigits[j] = endingDigits[j - 1] + endingDigits [j + 1];
        newEndingDigits[9] = endingDigits[8];

        for(int j = 0; j < 10; j ++) endingDigits[j] = newEndingDigits[j] % 1000000000;
    }

    int sum = 0;
    for(int i = 0; i < 10; i++) sum += endingDigits[i], sum %= 1000000000;

    cout << sum << endl;

    return 0;
}