/*
Problem URL : http://www.codechef.com/JULY14/problems/CSUB 
Algo type   : Adhoc 
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

#define DEBUG 1
#define MAX 100001
using namespace std;

char input[MAX];

typedef long long int INT;

INT nC2(INT c)
{
    INT result = 0;
    if( c % 2 == 0 ) 
    {
        result = c / 2;
        result *= (c-1);
    }
    else
    {
        result = (c-1)/2;
        result *= c;
    }
    return result;
}

INT ProcessInput()
{
    int c = 0;
    for( int i = 0; input[i] != '\0'; ++i) 
    {
        if(input[i] == '1') ++c;
    }

    if( c == 0) 
        return 0;
    if( c == 1) 
        return 1;

    return nC2(c) + c;
}

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--) 
    {
        scanf("%d",&n);
        scanf("%s",input);
        printf("%lld\n",ProcessInput());
    }
    return 0;
}
