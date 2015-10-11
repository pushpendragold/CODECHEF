/*
Problem URL : http://www.codechef.com/LTIME14/problems/TAEDITOR
Algo Type   : AC
Time Complexity : 
Space Complexity:
*/

#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

#define DEBUG 0
#define MAX   (3*100000 + 1)


using namespace std;

char input[MAX];

list<char> E;

void Print(int start,int len);

void Insert(int pos,char c[])
{
    if( E.size() == pos ) 
    {
        int i = 0;
        while( c[i] != '\0' )
            E.push_back(c[i++]);
    }
    else if( pos == 0 ) 
    {
        // push front
        int len = strlen(c);
        while(len > 0) 
            E.push_front( c[--len] );
    }
    else
    {
        if( E.size() - pos > pos ) 
        {
            list<char>::iterator it = E.begin();
            for(int i = 0; i < pos; ++i,++it);
    
            int i = 0;
            while(c[i] != '\0') 
                E.insert(it,c[i++]);
        }
        else
        {
            list<char>::reverse_iterator it = E.rbegin();
            for(int i = 0; i < E.size() - pos; ++i,++it);
    
            int i = 0;
            while(c[i] != '\0') 
                E.insert(it.base(),c[i++]);
        }
    }
    if(DEBUG) Print(1,E.size());
}

void Print(int start,int len)
{
    list<char>::iterator it = E.begin();

    for(int i = 0; i < start-1; ++i,++it);

    for( int i = 0; i < len; ++i,++it) 
        printf("%c",(*it));
    printf("\n");
}

int main()
{
    int T;
    char inpStr[MAX];
    scanf("%d\n",&T);
    while(T--) 
    {
        gets(input);
        if(input[0] == '+') 
        {
            // input
            char c; int pos;
            sscanf(input,"%c %d %s",&c, &pos,inpStr);
            Insert(pos,inpStr);
        }
        else
        {
            // output
            char c; int  pos; int len;
            sscanf(input,"%c %d %d",&c,&pos,&len);
            Print(pos,len);
        }
    }
    return 0;
}
