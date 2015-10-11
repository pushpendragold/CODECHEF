#include <cstdio>
#include <cassert>
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
#define MAX   101
#define MAXC  50
#define INF   100000000

typedef long long int INT;

int pascal [ MAX ][ MAX ];
int answer [ MAXC ];

void init()
{
	// init pascal triangle
	for(int i = 0; i < MAX; i++ )  // number of elements
	{
		for ( int j = 0; j < i; j++) 
		{
			if( j == 0 ) 
				pascal[i][j] = 1;
			else
				pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
		}
	}

	if(DEBUG) 
	{
		for(int i = 0; i < 7; i++) 
		{
			for(int j = 0; j < 7; j++) 
				printf("%d\t",pascal[i][j]);
			printf("\n");
		}
	}
}

bool ProcessInput_until(int C,int R,int G,int &ansCount,int lastPicked)
{
	if( G == 0) return true;

	for(int i = MAX - 1 ; i >= 0 && pascal[ i ][ R ] > 0 ; i-- ) 
	{
		if( G == pascal[ i ][ R ] ) 
		{
			answer[ ansCount++] = pascal[ i ][ R ];
			return true;
		}
		else if( pascal[ i ][ R ] < G && pascal[ i ][ R ] <= lastPicked ) 
		{
			answer[ ansCount++] = pascal[ i ][ R ];
			if( ProcessInput_until(C,R-1,G - pascal[ i ][ R ],ansCount, pascal[ i ][ R ]) )
				return true;
			ansCount--;
		}
	}
	return false;
}

void ProcessInput(int C,int R,int G)
{
	int ansCount = 0;

	ProcessInput_until(C,R,G,ansCount,INF);
		

	printf("%d\n",ansCount);
	for(int i = 0; i < ansCount; i++) 
	{
		printf("%d ",answer[i]);
	}
	printf("\n");
}

main()
{
	init();
	int T,C,R,G;
	scanf("%d",&T);
	while(T--) 
	{
		scanf("%d %d %d",&C,&R,&G);
		ProcessInput(C,R,G);
	}
	return 0;
}
