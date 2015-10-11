#include <stdio.h>
#include <assert.h>

#define MAX 101010
#define DEBUG 0

char A[MAX];
char B[MAX];
int  N[MAX];
int  maxV[MAX];

int GetANS()
{
    int ans = 0,i;
    for(i = 0; A[i] != '\0'; ++i)
    {
        if(A[i] == B[i])
            ++ans;
    }
    return ans;
}

int Process(int n)
{
   int ans = GetANS(),i;
   if(ans > n)
       assert(0);

   if(ans == n)
       return N[n];

   int maxV = -1;
   for(i = 0; i <= ans ; ++i)
   {
       if(N[i] > maxV)
           maxV = N[i];
   }
   return maxV;
}

int main()
{
    int T,n,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",A);
        fflush(stdin);
        scanf("%s",B);

        for(i = 0; i <= n; ++i)
            scanf("%d",&N[i]);

        printf("%d\n",Process(n));

    }
    return 0;
}
