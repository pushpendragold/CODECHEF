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

main()
{
	int N,tmp;
	int max = 0,cur = 0;
	scanf("%d",&N);
	for(int i = 0; i < N; i++) 
	{
		scanf("%d",&tmp);
		if( tmp > 0 ) 
		{
			cur++;

			if( max < cur ) 
				max = cur;
		}
		else
		{
			cur = 0;
		}
	}
	printf("%d",max);
	return 0;
}
