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
#define MAX 20000
#define MOD 1000000007LL
typedef long long int INT;

INT input[MAX];

INT A = 0x7fffffffffffff01;
INT B = 0x7fffffffffffff02;
INT M = 0x7fffffffffffff03;

INT addmod( INT x, INT y, INT m )
{
  x %= m;
  y %= m;
  INT sum = x-m+y;
  return sum < 0 ? sum + m : sum;
}

INT timesmod( INT x, INT y, INT m )
{
  x %= m;
  y %= m;
  INT a = x < y ? x : y; // min
  INT b = x < y ? y : x; // max
  INT product = 0;
  for (; a != 0; a >>= 1, b = addmod(b,b,m) )
    if (a&1) product = addmod(product,b,m);
  return product;
}

INT GCD ( INT a, INT b )
{
  INT c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

INT ProcessInput(int n)
{
	INT pro = 1;
	INT gcd = 1;
	for(int i = 0; i < n; i++ ) 
	{
		for( int j = i+1; input[i] > 1 && j < n; j++) 
		{
			if( input[i] > 1 && input[j] > 1 ) 
			{
				gcd = GCD(input[i],input[j]);
				input[i] = input[i] / gcd;
				input[j] = input[j] / gcd;
			}
		}
	}

	for(int i = 0; i < n; i++ ) 
		pro = timesmod(pro,input[i],M) % M;

	return pro;
}

main()
{
	int T,n;
	scanf("%d",&T);
	while(T--) 
	{
		scanf("%d",&n);
		for(int i = 0; i < n; i++) 
			scanf("%lld",&input[i]);
		if(n == 1) 
			printf("%lld\n",input[0]);
		else
			printf("%lld\n",ProcessInput( n ) % M);
	}
	return 0;
}
