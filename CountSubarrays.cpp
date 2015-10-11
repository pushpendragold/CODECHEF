#include <cstdio>
#include <iostream>
#define MAX 101010
using namespace std;

int A[MAX];

long long int GetAns(int n)
{
    long long int ans = 0;
    if( n%2 == 0 )
    {
        ans = n/2;
        ans *= (n+1);
        return ans;
    }
    ans = (n+1)/2;
    ans *= n;
    return ans;
}

long long int Process(int n)
{
    long long int ans = 0;
    int tN = 0;
    for(int i = 0; i < n; ++i)
    {
        if(i == 0)
        {
            //++ans;
            tN = 1;
        }
        else
        {
            if( A[i] >= A[i-1] )
            {
                ++tN;
            }
            else
            {
                ans += GetAns(tN);
                tN = 1;
            }
        }
    }
     ans += GetAns(tN);

    return ans;
}

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; ++i)
            scanf("%d",&A[i]);

        printf("%lld\n",Process(n));
    }
    return 0;
}
