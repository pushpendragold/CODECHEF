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
typedef unsigned long long int INT;

main()
{
	INT n;
	bool found = false;
	scanf("%llu",&n);

	if ( n == 0)
		found = true;
	else if( n % 6 == 0 ) 
		found = true;
	else
	{
		INT fact = n / 6;
		n = n - fact * 6;
		if( n == 1 ||  n == 3 || n == 0 )
			found = true; 
	}

	printf("%s\n", found ? "yes" : "no");
	return 0;
}
