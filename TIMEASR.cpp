#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef struct Time {
    int H,M;
    double ans;
}Time;

vector<Time> TANS;

double Calculate(double h,double m)
{
    double diff = 30*h - 5.5 *m;

    if(diff < 0)
        diff = (-1)*diff;

    if(diff > 180 )
        diff = 360 - diff;

    return diff;
}

void init()
{
    Time d;
    for(int h = 0; h < 12; ++h)
    {
        for(int m = 0; m < 60; m++)
        {
            d.ans = Calculate(h,m);d.H = h;d.M = m;
            TANS.push_back(d);
        }
    }
}

void PrintTime(Time &t)
{
    if( t.H < 10 )
        printf("0%d:",t.H);
    else
        printf("%d:",t.H);
    if(t.M < 10)
        printf("0%d\n",t.M);
    else
        printf("%d\n",t.M);
}

int main()
{
    int T;
    double n;
    scanf("%d",&T);
    init();
    while(T--)
    {
        scanf("%lf",&n);
        for(int i = 0; i < TANS.size() ; ++i)
        {
            if(TANS[i].ans == n || (TANS[i].ans - 0.008333333 <= n ) && (TANS[i].ans + 0.008333333 >= n ))
                PrintTime(TANS[i]);
        }
    }
    return 0;
}
