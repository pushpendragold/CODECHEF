#include <cstdio>
#include <iostream>
#include <cmath>
#define MAX 10100
using namespace std;

int main()
{
    int count = 0;
    for(int i = 3; i < MAX; ++i)
    {
        for(int j = 1; j < i; j+=2 )
        {
            if(i == j)
                continue;

            int p = sqrt(i*i - j*j);
            if(p*p == (i*i - j*j))
            {
                count++;
                printf("%d\n",i);
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
