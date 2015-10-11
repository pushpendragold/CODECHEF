#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <cmath>
#include <set>

using namespace std;

#define DEBUG 1
typedef long long int INT;
int A[1000];

main()
{
	int T,n,k;
	scanf("%d",&T);
	while(T--) 
	{
		int tmpSum = 0;
		int freq = 0;
		int minNum = -1;
		scanf("%d %d",&n,&k);
		for(int i = 0; i < n; i++) 
		{
			scanf("%d",&A[i]);
		}
		for(int i = 0; i < n; i++) 
		{
			for(int j = i+1; j < n; j++) 
			{
				tmpSum = A[i] + A[j] - k;
				if(tmpSum < 0 ) 
					tmpSum = (-1) * tmpSum;
				if( tmpSum < minNum || minNum == -1 ) 
				{
					minNum = tmpSum;
					freq = 1;
				}
				else if( tmpSum == minNum ) 
					freq++;
			}
		}

		printf("%d %d\n",minNum,freq);
	}
	return 0;
}
