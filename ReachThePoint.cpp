/*
 
Problem URL : http://www.codechef.com/JULY14/problems/RETPO
Status : AC 
 
Algo Type   : Math, Implementation
Time Complexity : O(1)
Space Complexity: O(1)

*/

#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

#define DEBUG 1
#define MAX   10000001
using namespace std;

int CaseAxis(int x,int y);

int Q_I(int x,int y)
{
    // Case 1. 
    if( x == y ) 
        return 2 * x;

    // Case 2.
    if( x < y ) 
    {
        int steps = 0;

        // Steps taken during moving origin
        steps = 2 * x; 

        // Move origit to (x,x)
        y = y - x;
        x = x - x;

        // Return total number of steps
        return steps + CaseAxis(x,y);
    }

    // Case 3.
    if( x > y ) 
    {
        int steps = 0;

        // Steps taken during moving origin
        steps = 2 * y;

        // Move origin to (x,x)
        x = x - y;
        y = y - y;

        // Return total number of steps
        return steps + CaseAxis(x,y);

    }
}
int CaseAxis(int x,int y)
{
    if( x == 0 && y == 0 ) 
        return 0;

    if( x == 0 ) // y-axis
    {
        y = y > 0 ? y : (-1)*y;
        if( y % 2 == 1 ) // y is odd
            return ( y - 1 ) * 2 + 1; 
        return ( y ) * 2;
    }
    else          // x - axis
    {
        x = x > 0 ? x : (-1)*x;
        if( x % 2 == 1 ) 
            return ( x - 1 ) * 2 + 3;
        return ( x ) * 2;
    }
}
int ProcessInput(int x,int y)
{
    // 1. Check if point is on any axis
    if( x == 0 || y == 0) 
        return CaseAxis(x,y);

    x = x > 0 ? x : (-1)*x;
    y = y > 0 ? y : (-1)*y;
    return Q_I(x,y);
    
}

int main()
{
    int T,x,y;
    scanf("%d",&T);
    while(T--) 
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",ProcessInput(x,y));
    }
    return 0;
}
