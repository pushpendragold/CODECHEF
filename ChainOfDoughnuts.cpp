#include <cstdio>
#include <assert.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define DEBUG if(0)

using namespace std;
typedef long long int int32;

int Ans(vector<int32> &input,int32 total)
{
    int si = 0; 
    int ei = input.size() - 1;
    int ans = 0;
    int32 len = 0;

    while( true )
    {
        if(len >= total)
            break;

        int left = ei - si;
        DEBUG cout << left << endl;

        if(len == 0)
        {
            len += input[ei];
            --ei;
        }
        else
        {
            
            if(input[si] == 0) si++;
            //if(si == ei) break;
            len += (input[ei] + 1);
            
            ++ans;
            --ei;
            --input[si];
        }
    }

    return ans;
}

int main()
{
    int T;
    int32 t,total,n,nonOnes,ones;
    vector<int32> input;
    cin >> T;
    while(T--)
    {
        cin >> total >> n;
        ones = 0;
        nonOnes = 0;
        input.resize(n);
        for(int i = 0; i < n; ++i)
            cin >> input[i];
     
        sort(input.begin(),input.end());
        cout << Ans(input,total) << endl;
    }
    return 0;
}
