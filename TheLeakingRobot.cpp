/*
Problem URL : http://www.codechef.com/AUG14/problems/CRAWA
Algo Type   : Implementation Math
Time Complexity : O(n)
Space Complexity: O(n) 
Status : AC 
 
*/
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
 
#define DEBUG 0
using namespace std;
 
bool Q_I(int x,int y)
{
	if( DEBUG ) printf("Q_I\n");
	
	// on perpendicular to x axis
	if( x % 2 == 1 && y <= (x + 1))
			return true;
 
	// on perpendicular to y axis
	if( y % 2 == 0 && x <= (y - 1))
		return true;
	
	// not found in 1st quadrent
	return false;
}
 
bool Q_II(int x,int y)
{
	if( DEBUG ) printf("Q_II\n");
 
	x = x < 0 ? (-1)*x : x;
	y = y < 0 ? (-1)*y : y;
 
	// perpendicular to x - axis
	if( x % 2 == 0 && y <= x )
		return true;
	
	// perpendicular to y - axis
	if( y % 2 == 0 && x <= y )
		return true;
	
	return false;
}
 
bool Q_III(int x,int y)
{
	if( DEBUG ) printf("Q_III\n");
	return Q_II(x,y);
}
 
bool Q_IV(int x,int y)
{
	if( DEBUG ) printf("Q_IV\n");
 
	x = x < 0 ? (-1)*x : x;
	y = y < 0 ? (-1)*y : y;
 
	// perpendicular to x - axis
	if( x % 2 == 1 && y <= x - 1 )
		return true;
 
	// perpendicular to y - axis
	if( y % 2 == 0 && x <= y + 1 )
		return true;
	
	return false;
}
 
bool ProcessInput(int x,int y)
{
	if(( x == 0 && y == 0 ) || ( x == 1 && y == 0 ))
		return true;
 
	if( x == 0 ) // y - axis
	{
		if( y % 2 == 0 )
			return true;
		return false;
	}
 
	if( y == 0 ) // x - axis
	{
		if( x > 0 && x % 2 == 1 )
			return true;
		if( x < 0 && x % 2 == 0 )
			return true;
		return false;
	}
 
	// Check for Quaderants
	if( x > 0 && y > 0 )
		return Q_I(x,y);
	if( x < 0 && y > 0 )
		return Q_II(x,y);
	if( x < 0 && y < 0 )
		return Q_III(x,y);
	if( x > 0 && y < 0 )
		return Q_IV(x,y);
 
	// Should not reach here
	assert(0);
}
int main()
{
	int T,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&x,&y);
		ProcessInput(x,y) ? printf("YES") : printf("NO");
		printf("\n");
	}
	return 0;
}
