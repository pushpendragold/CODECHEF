// FACT : hypotenuses will be including prime number which can be shown as 4n+1; 

#include <cstdio>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>

#define MAX 5001001
#define DEBUG if(0)

using namespace std;
typedef long long int int32;

vector<int32>  seive;
vector<int32>  P;

void init()
{
    int range = MAX+100;//sqrt(MAX) + 1;

    seive.resize(range+1);
    seive[1] = 1;
    for(int i = 2; i <= range; i++)
    {
        if( seive[i] == 0 )
        {
            P.push_back(i);
            if( i % 4 == 1 )
                seive[i] = 4;

            for(int j = i*2; j <= range; j+=i )
                seive[j] = 1;
        }
    }

    DEBUG
    {
        for(int i = 0; i < 20 ; ++i)
            cout << i << " : "<< seive[i] << endl;
        cout << seive.size() << endl;
        cout << P.size() << endl;
    }
}

bool Process(int N)
{
    if( seive[N] == 4 ) // A prime
        return true;
    
    if(seive[N] == 0 )
        return false;

    int i = 0;

    while(true)
    {
        if( seive[N] == 0 || N == 1 )
            return false;
        
        if(seive[N] == 4)
            return true;

        if( N % P[i] == 0 )
        {
            if(seive[P[i]] == 4)
                return true;

            while(N % P[i] == 0)
            {
                N = N/P[i];
                DEBUG cout << N << endl;
                if( seive[N] == 0 )
                    return false;

                if(seive[N] == 4)
                    return true;
            }
        }

        ++i;

        if( i > P.size())
            break;
    }

    if(seive[N] == 4)
        return true;
    return false;
}
/*

bool Process(int32 N)
{
    int32 H = N;
    int32 Bmax = 2*N;
    int32 B,P;

    for(B = 1; B < N ; B++ )
    {
        P = sqrt(H*H - B*B);
        if( P && (P * P == H*H - B*B))
        {
            DEBUG << "P:" << P << " H: " << H << " B: " << B << endl;
            return true;
        }

    }
    return false;
} 
 
*/

int main()
{
    int32 T,n;
    init();
    
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        Process(n) ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}
