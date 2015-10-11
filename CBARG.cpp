#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long int int32;

int main()
{
    int32 T,N,tmp,ans = 0,cM = 0;
    scanf("%lld",&T);
    while(T--)
    {
         scanf("%lld",&N);
         ans = 0;cM = 0;
         for(int32 i = 0; i < N; ++i)
         {
              scanf("%lld",&tmp);
              if(cM == 0)
                   ans = cM = tmp;
              else if(tmp > cM)
                  ans += (tmp - cM);
              cM = tmp;
         }
         printf("%lld\n",ans);
    }
    return 0;    
}
