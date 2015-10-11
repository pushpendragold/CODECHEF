/*
 
Lucy had recently learnt about palindromes. As you may probably know, palindrome is a string that reads the same way in the both directions, that is left-to-right or right-to-left. For example, strings "radar" and "level" are palindromes, at the same time, strings "hello" and "world" are not.
There is a string of N latin letters. Lucy asks you to answer the following queries:

1 L R - reverse the substring from the L-th to the R-th character (1-indexed), inclusive.

2 L R - calculate the number of distinct palindromes that can be obtained by permutting characters from the L-th to the R-th in the arbitrary order (ignoring all other characters of the string).
Input

The first line of input consists of two space separated integers N and M - the length of the string and the number of queries.
The second line consists of N characters from the set {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'}, describing the string. Then, M queries follow. Each query is 
given in one of the following forms:

1 L R - reverse the substring from the L-th to the R-th character.
2 L R - calculate the number of distinct palindromes that can be obtained by permutting characters from the L-th to the R-th in the arbitrary order, 
modulo 10^9+7 (ignoring all other characters).
 
Output
 
For every query of the type 2 output the answer on the separate line.
Example

Input:
7 4
abacaba
2 1 7
2 2 3
1 1 2
2 2 3

Output:
3
0
1
Scoring

In all the subtasks, 1 <= L <= R <= N.
Subtask 1 (33 points): 1 <= N <= 10, 1 <= M <= 1000
Subtask 2 (17 points): 1 <= N <= 1000, 1 <= M <= 1000
Subtask 3 (23 points): 1 <= N <= 4*104, 1 <= M <= 4*104
Subtask 4 (27 points): 1 <= N <= 105, 1 <= M <= 105
Time limit for subtasks 1 and 2 is 1 sec, and for the subtasks 3 and 4 it's equal to 2 sec. 
 
*/ 

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <assert.h>

#define MAX 100001
#define MOD 1000000007

typedef long long int INT;
using namespace std;

INT repeated[MAX];
INT product[MAX];

INT getFactorial(int n_count,int r_count)
{
    //init
    for(int i = 1; i <= n_count; i++)
        product[i] = i;

    while(r_count >= 0)
    {
        for(int i = n_count; i >= 0; i--)
        {
            if( product[i] % repeated[r_count] == 0)
            {
                product[i] = product[i] / repeated[r_count];
                break;
            }
        }
        r_count--;
    }

    INT pro = 1;
    for(int i = 1; i <= n_count; i++)
        pro = ( ( pro % MOD ) *  ( product[i] % MOD) ) % MOD;

    return pro;
}

void Query1(char A[],int left,int right)
{
    char temp;

    while(right >= left)
    {
        temp = A[left];
        A[left] = A[right];
        A[right] = temp;
        right--; left++;
    }
}

bool CheckPermutationPossible(char A[],int left, int right,int &n)
{
    int len = right - left + 1;
    n = 0;
    if(len == 1) return true;
    
    if(len % 2 == 1) // odd length 
    {
       int B[10] = {0};

       for(int i = left ; i <= right; i++)
           B[ A[i] - 'a' ]++;

       int oddCount = 0;
       for (int i = 0; i < 10; i++)
       {
           if( B[i] % 2 == 1) // odd
           {
               oddCount++;
               if(oddCount > 1) //More than 1 odd not allowed
                   return false;
           }
           else if( B[i] / 2 > 1 )
           {
               repeated[n++] = ( B[i] / 2 );
           }
       }

       return true;
    }
    else
    {
        int B[10] = {0};

        for(int i = left ; i <= right; i++)
           B[ A[i] - 'a' ]++;

        for (int i = 0; i < 10; i++)
        {
           if( B[i] % 2 == 1) // odd
               return false;
           else if( B[i] / 2 > 1 )
           {
               repeated[n++] = ( B[i] / 2 );
           }
        }
        return true;
    }
    return false;
}

INT Query2(char A[],int left, int right)
{
    //Number of palindroms in given strings permutations
    int len = right - left + 1;
    int repeated = 0;
    //check if palindrom is possible in given string
    if(CheckPermutationPossible(A,left,right,repeated)) 
    {
        return getFactorial(len / 2, repeated - 1);
    }
    return 0;
}

main()
{
    int len,nQuery,qType,left,right;
    char A[1024];
    scanf("%d %d",&len,&nQuery);
    scanf("%s",A);
    for(int i=0; i<nQuery; i++) 
    {
        scanf("%d %d %d",&qType,&left,&right);
        if( qType == 1 )
        {
            Query1(A,left-1,right - 1);
            //printf("%s\n",A);
        }
        else
        {
            printf("%lld\n",Query2(A,left-1,right-1));
        }
    }
    return 0;
}
