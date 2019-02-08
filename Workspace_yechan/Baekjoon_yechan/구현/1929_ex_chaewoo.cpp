#include<iostream>
#include<algorithm>
#include <time.h>
using namespace std;

bool isPrimeDoor[1000001];

double what_time_is_it_now() {
    struct timespec now;
    clock_gettime(CLOCK_REALTIME, &now);
    return now.tv_sec + now.tv_nsec*1e-9;
}

void eratosInit()
{
    fill(isPrimeDoor, isPrimeDoor + 1000001, true);
    isPrimeDoor[1] = isPrimeDoor[0] = false;
    for(int i = 2; i <= 1000; i++)
    {
        if(!isPrimeDoor[i]) continue;

        for(int j = i; j <= 1000000; j += i) isPrimeDoor[j] = false;
        isPrimeDoor[i] = true;
    }
}

int main()
{
    int m, n;
    int cnt = 0;
    double start, end;
    start=what_time_is_it_now();
    eratosInit();
    end=what_time_is_it_now();
    printf("TIME: %f\n", end-start);

    cin >> m >> n;

    if(m > n) swap(m, n);

    for(int i = m; i <= n; i++)
    {
        // if(isPrimeDoor[i]) cout << i << endl;
        if(isPrimeDoor[i]) cnt++;
    }
    end=what_time_is_it_now();
    printf("TIME: %f\n", end-start);
    
    return 0;
}