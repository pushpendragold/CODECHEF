/*
Problem URL : http://www.codechef.com/AUG14/problems/PRGIFT
Algo Type   : implementation
Time Complexity : O(n)
Space Complexity: 
Status :  
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

int A[MAX];

bool ProcessInput(int n,int k)
{
    int c = 0;
    if( k == 0 ) 
    {
        // should contains atleast one odd number
        for( int i = 0; i < n; ++i ) 
        {
            if( A[i] % 2 ) 
                return true;
        }
        return false;
    }

    for( int i = 0; i < n; ++i ) 
    {
        if( A[i] % 2 == 0 ) 
        {
            c++;
            if(  c == k ) return true;
        }
    }
    return false;
}

int main()
{
    int T,n,k;
    scanf("%d",&T);
    while(T--) 
    {
        scanf("%d %d",&n,&k);
        for(int i = 0;i < n; ++i) 
           scanf("%d",&A[i]);
        ProcessInput(n,k) ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}

