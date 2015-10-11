#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>

#define MAX 100001
using namespace std;

typedef long long int INT;

bool myfunction (INT i,INT j) 
{ 
	return ( i < j ); 
}

INT A[MAX];
int main () 
{

	int T,n;
	map< INT,int > Hash;
	scanf("%d",&T);
	int count = 0;
	while(T--) 
	{
		Hash.clear();
		scanf("%d",&n);
		count = 0;
		for(int i = 0; i<n; i++) 
		{
			scanf("%lld",&A[i]);
			if(Hash[A[i]] == 0) 
			{
				Hash[A[i]] = 1;
				count++;
			}
		}
		

		if( count == 0 || count == 1) 
			printf("0\n");
		else
		{
			INT ans = 1;
			if( count % 2 == 0) 
			{
				ans = count / 2;
				ans = ( count - 1) * ans;
			}
			else
			{
				ans = (count - 1) / 2;
				ans = count * ans;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
