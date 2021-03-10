// Elevetor
/* The highest building in our city has only one elevator. A request list is made up with N positive numbers. 
The numbers denote at which floors the elevator will stop, in specified order. 
It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. 
The elevator will stay for 5 seconds at each stop.
For a given request list, you are to compute the total time spent to fulfill the requests on the list. 
The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.*/

#include <iostream>
using namespace std;

#define UP 6
#define DOWN 4
#define STAY 5

int main()
{
    int i, n, a[100];
    int stay_time, up_time = 0, down_time = 0;

    cin >> n;
    for ( i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    stay_time = n * STAY;

    up_time += a[0] * UP;
    for ( i = 1; i < n; i++)
    {
        if (a[i] > a[i-1])
        {
            up_time += (a[i] - a[i - 1]) * UP;
        }
        else
        {
            down_time += (a[i - 1] - a[i]) * DOWN;
        }
    }
    
    int total_time;

    total_time = up_time + down_time + stay_time;
    // total_time = up_time + down_time ;

    cout << total_time << endl;

    return 0;
}