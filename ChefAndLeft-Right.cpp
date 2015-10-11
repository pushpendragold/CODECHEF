/*
Problem URL : http://www.codechef.com/SEPT14/problems/CHEFLR
Algo Type   : 
Time Complexity : 
Space Complexity:
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
#define MAX   100001
using namespace std;
typedef long long int INT;

char input[MAX];

INT ProcessInput()
{
    // Calculate the position of
    int c_level = 1;
    int i = 0;
    int currentElement = 1;
    INT lastEven = 0;
    INT lastOdd = 0;
    INT ans = 0;
    
    while( input[i] != '\0' )
    {
        if( input[i] == 'l' ) 
        {
            if( c_level == 1 )
            {
                lastOdd = 2;
                ans = 2;
            }
            else
            {

            }
        }
        else
        {
            if( c_level == 1 ) 
            {
                lastOdd = 1;
                ans = 4;
            }
            else
            {

            }
        }
        ++c_level;
        ++i;
    }
    
    return ans;
}

int main()
{
    int T;
    scanf("%d\n",&T);
    while(T--) 
    {
        gets(input);
        printf("%lld\n",ProcessInput());
    }
    return 0;
}
