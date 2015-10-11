#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define MAX 505
#define DEBUG if(0)

int input[MAX][MAX];

typedef struct Data{
    int i,j;
}Data;
Data M[MAX*MAX];


void Read(int n)
{
    int t;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cin >> t;
            input[i][j] = t;
            M[t].i = i;
            M[t].j = j;
        }
    }
}

int MovePos(Data &cPos,Data &nPos)
{
    int iS = 0; int jS = 0;
    if( cPos.i != nPos.i )
        iS = cPos.i > nPos.i ? cPos.i - nPos.i : nPos.i - cPos.i;
    if( cPos.j != nPos.j )
        jS = cPos.j > nPos.j ? cPos.j - nPos.j : nPos.j - cPos.j;
    return iS + jS;
}

int Ans(int n)
{
    //if(n == 1) return 0;
    Data cPos,nPos;


    cPos.i = M[1].i;
    cPos.j = M[1].j;

    int c = 2;
    int ans = 0;
    int cS = 0;

    while(c <= n*n)
    {
       nPos.i = M[c].i; nPos.j = M[c].j;
       cS = MovePos(cPos,nPos);
       DEBUG cout << cS << " (" << cPos.i << "," << cPos.j << ") (" << nPos.i << "," << nPos.j << ")" << endl;
       ans += cS;
       cPos.i = nPos.i; cPos.j = nPos.j;
       ++c;
    }

    return ans;
}

int main()
{
    int T,n;
    cin >> T;
    while(T--)
    {
        cin >> n;
        Read(n);
        cout << Ans(n) << endl;
    }
    return 0;
}
