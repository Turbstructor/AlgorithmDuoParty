#include<iostream>
using namespace std;
int main()
{
    int total;
    int prices[10] = {0};
    int pricesSum = 0;

    cin >> total;
    for(int i=0 ; i < 9; i++){ cin >> prices[i]; pricesSum += prices[i]; }

    cout << total - pricesSum << endl;

    return 0;
}