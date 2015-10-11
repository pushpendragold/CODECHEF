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

#define DEBUG 0
#define MAX 100000
#define NEGATIVE -2000000100LL
#define POSITIVE  2000000100LL

typedef long long int INT;

main()
{
	INT n,k,Max = NEGATIVE,Min = POSITIVE;
	INT A[ MAX ];

	scanf("%lld %lld",&n,&k);

	if( n > 1) 
	{
		scanf("%lld",&A[0]);
		Max = Min = A[0];
	}

	for(INT i = 1; i < n; i++ ) 
	{
		scanf("%lld",&A[i]);
		if( Max < A[i] ) Max = A[i];
		if( Min > A[i] ) Min = A[i];
	}

	if( k == 0 ) 
	{
		for(INT i = 0; i < n - 1; i++ ) 
				printf("%lld ", A[i] );
		printf("%lld\n",A[n - 1]);
	}
	else if( k == 1 )
	{
		for(INT i = 0; i < n-1; i++ ) 
			printf("%lld ",Max - A[i]);
		printf("%lld\n",A[n - 1]);
	}
	else
	{
		int n_Max;
		int n_Min;

		while( Min != 0 )
		{
			n_Min = n_Max = Max - A[0];
			
			for(INT i = 0; i < n; i++ ) 
			{
				A[i] = Max - A[i];
				if( n_Max < A[i]) n_Max = A[i];
				if( n_Min > A[i]) n_Min = A[i];
			}

			Max = n_Max;
			Min = n_Min;
			k--;

			if( k == 0) 
				break;
		}
		
		if( k == 0) 
		{
			for(INT i = 0; i < n - 1; i++ ) 
				printf("%lld ", A[i] );
			printf("%lld\n",A[n - 1]);
		}
		else
		{
			if( k % 2 == 1) // odd
			{
				for(INT i = 0; i < n - 1; i++ ) 
					printf("%lld ",Max - A[i]);
				printf("%lld\n",Max - A[n - 1]);
			}
			else
			{
				for(INT i = 0; i < n - 1; i++ ) 
					printf("%lld ", A[i] );
				printf("%lld\n",A[n - 1]);
			}
		}
	}
	return 0;
}
