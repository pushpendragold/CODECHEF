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
#define MAX 1000001
typedef long long int INT;

char input[MAX];
map<char,char> hash;

void ProcessInput()
{
	int i,len;
	for(i = 0; input[i] != '\0'; ++i)
	{
		if( hash[input[i]] > 0) 
			input[i] = hash[input[i]];
	}

	len = i;
	// remove tailing zeors
	for(int j = i - 1; j >= 0; --j) 
	{
		if( input[j] != '0' ) 
		{
			if(input[j] == '.') 
			{
				input[j] = '\0';
				len = j+1;
			}
			else
			{
				input[j+1] = '\0';
				len = j+2;
			}
			break;
		}
	}

	bool leadingZeors = true;
	for(i = 0; input[i] != '\0'; ++i) 
	{
		if(leadingZeors && input[i] != '0') 
			leadingZeors = false;

		if(!leadingZeors) 
			printf("%c",input[i]);
	}
	printf("\n");
}

int main()
{
	int T,n;
	int a,b;
	scanf("%d\n",&T);
	while(T--) 
	{
		hash.clear();
		scanf("%d\n",&n);
		for(int i = 0; i < n; ++i) 
		{
			gets(input);
			sscanf(input,"%c %c",&a,&b);
			hash[a] = b;
		}
		input[0] = '\0';
		fflush(stdin);
		gets(input);
		if(input[0] == '\0') 
			printf("\n");
		else
			ProcessInput();
	}
	return 0;
}
