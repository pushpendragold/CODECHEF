#include <cstdio>
#include <cstring>

int main()
{
    int T,X,Y,K,N;
    int a,b;
    bool lucky = false;
    scanf("%d",&T);
    while(T--)
    {
        lucky = false;
        scanf("%d %d %d %d",&X,&Y,&K,&N);
        if( Y >= X )
            lucky = true;
        for(int i = 0; i < N; ++i)
        {
            scanf("%d %d",&a,&b);
            if(!lucky)
            {
                if(X - Y <= a && K >= b )
                    lucky = true;
            }
        }
        if(lucky)
            printf("LuckyChef\n");
        else
            printf("UnluckyChef\n");
    }
    return 0;
}
