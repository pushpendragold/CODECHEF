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
#define MAX 1000
typedef long long int INT;

enum {
	QUEEN   = 1,
	FREE    = 2,
	CHECKED = 3
};

typedef struct Point 
{
	int x; int y;
} Point;

void PrintBoard( vector< vector<int> > &Board, int n )
{
	for(int i = 0; i < n; i++) 
	{
		for(int j = 0; j < n; j++) 
			printf("%d ",Board[i][j]);
		printf("\n");
	}
}

void CalculateSafePositions( vector< vector<int> > &Board, vector< Point > &safePosition, int n )
{
	Point p;
	for( int i = 0 ; i < n; i++ ) 
	{
		for( int j = 0 ; j < n; j++ ) 
		{
			if( Board[i][j] == 0 ) 
			{
				p.x = i; p.y = j;
				safePosition.push_back(p);
			}
		}
	}
}

int CheckPosition( vector< vector<int> > &Board, Point &pos, int n )
{
	int kChecks = 0;
	
	if(pos.x + 2 < n && pos.y - 1 >= 0 && Board[ pos.x + 2 ][ pos.y - 1 ] == QUEEN )
		kChecks++;

    if(pos.x + 2 < n && pos.y + 1 < n && Board[ pos.x + 2 ][ pos.y + 1 ] == QUEEN)
		kChecks++;
    if(pos.x - 2 >= 0 && pos.y - 1 >= 0 && Board[pos.x - 2][ pos.y - 1] == QUEEN )
		kChecks++;
    if(pos.x - 2 >= 0 && pos.y + 1 < n && Board[pos.x - 2][ pos.y + 1 ] == QUEEN)
		kChecks++;
      
    if(pos.y - 2 >= 0 && pos.x + 1 < n && Board[pos.x + 1][ pos.y - 2] == QUEEN )
		kChecks++;
    if(pos.y - 2 >= 0 && pos.x - 1 >= 0 && Board[pos.x - 1][ pos.y - 2] == QUEEN )
		kChecks++;
	if(pos.y + 2 < n && pos.x + 1 < n && Board[pos.x + 1][ pos.y + 2] == QUEEN )
		kChecks++;
	if(pos.y + 2 < n && pos.x - 1 >= 0 && Board[pos.x - 1][ pos.y + 2] == QUEEN)
		kChecks++;
	return ( kChecks > 1 ) ? 1 : 0;
}

int CalcuateForkPosition( vector< vector<int> > &Board, vector< Point > &safePosition, int n )
{
	int count = 0;
	Point p;
	for(unsigned a = 0; a < safePosition.size(); a++ ) 
	{
		p.x = safePosition[a].x;
		p.y = safePosition[a].y;

		count += CheckPosition( Board,p,n );
	}
	return count;
}

void PlaceQueens( vector< vector<int> > &Board, vector< Point > &queens,int n)
{
	for(unsigned q = 0; q < queens.size(); q++) 
	{
		Board[ queens[q].x - 1 ][ queens[q].y - 1 ] = QUEEN;

		// horizontal and vertical
		for(int i = 0; i < n; i++) 
		{
			if( Board[ queens[q].x - 1 ][ i ] != QUEEN )
				Board[ queens[q].x - 1 ][ i ] = CHECKED;

			if( Board[ i ][ queens[q].y - 1 ] != QUEEN ) 
				Board[ i ][ queens[q].y - 1 ] = CHECKED;
		}

		// Daigonal position 
		for(int i = queens[q].x - 1, j = queens[q].y - 1; i < n && j < n ; i++, j++)
		{
			if( Board[i][j] != QUEEN ) 
			Board[i][j] = CHECKED;
		}
		for(int i = queens[q].x - 1, j = queens[q].y - 1; i >= 0 && j >= 0 ;i--,j--)
		{
			if( Board[i][j] != QUEEN ) 
			Board[i][j] = CHECKED;
		}
      
		for(int i = queens[q].x - 1, j = queens[q].y - 1; i >= 0 && j < n ;i--,j++)
		{
			if( Board[i][j] != QUEEN ) 
			Board[i][j] = CHECKED;
		}
		 
		for(int i = queens[q].x - 1, j = queens[q].y - 1; i < n && j >= 0 ;i++,j--)
		{
			if( Board[i][j] != QUEEN ) 
			Board[i][j] = CHECKED;
		}
	}
}



int ProcessInput(int n,int m,vector<Point> &queens)
{
	vector< vector<int> > Board;
	Board.resize(n);
	for(int i = 0; i < n; i++) 
		Board[i].resize(n);

	if(DEBUG) PrintBoard(Board,n);
	PlaceQueens( Board,queens,n );
	if(DEBUG) PrintBoard(Board,n);
	
	vector< Point > safePosition;
	CalculateSafePositions( Board , safePosition, n );

	return CalcuateForkPosition( Board, safePosition, n );
}

main()
{
	int T,n,m;
	Point p;
	scanf("%d",&T);

	while(T--) 
	{
		scanf("%d %d",&n,&m);
		vector<Point> queens;

		for(int i = 0; i < m; i++ ) 
		{
			scanf("%d %d",&p.x,&p.y);
			queens.push_back(p);
		}

		printf("%d\n",ProcessInput(n,m,queens));
	}

	return 0;
}
