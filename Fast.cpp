/*
Cyael is a very gifted girl who loves Magic (she even reached the finals on a very famous tournament in Byteland ;) ) and Computer Science. As we know, CS is a very vast subject and Cyael learns what she can, little by little, by reading the editorials of codechef.com, her favourite programming website.
Today, she came across a problem that was about calculating powers of two, and she got bored of it really fast, as she considers she knows all there is to know about powers of two. She knows how to compute even very big powers, like powers of 10, so it's obvious that for her, powers of two have no secrets :D
But her friend Lira, as she was tired of hearing her boasting about her skills for calculating powers, decided to challenge her with a brand new task: computing what she calls, SuperPowers of 2 .
Cyael: "Okay Lira, tell me about SuperPower of 2 so that I can solve one more problem and prepare for Codechef's November Long Challenge!! It's less than a month away!"
Lira: "I define the Nth Superpower of 2 as being the number (2N_bin)2 , where N_bin stands for the decimal number encoded by the representation in base 2 of the number N.
So, for example, the 2nd SuperPower of 2 is then equal to the number:
(210)2 = 1048576
because, N = 2 , and its binary encoding is 10 in decimal it is ten. So 210 = 1024 and 10242 = 1048576
Since the answer can be large, you are asked to compute SuperPowers of 2 modulo 1000000007."
After some time, Cyael finally solved the problem and decided to call Lira:
Cyael: "Well, I admit I struggled more than I'd have expected on this problem... You should consider becoming a problem setter and set this problem for Codechef... Do you want me to call Bruno and ask him to set this problem on your behalf? He always finds a way of writing a fun problem statement!!"
Lira: "Wooow!! That means Codechef community would solve my problem, modified by Bruno himself? Please do so, I'd love it!!!"
And now, here I am (yes, Bruno :D ) setting Lira's problem to all of you, but, with some differences regarding Lira's initial version, which hopefully you will appreciate.
Input

The first line of the input contains an integer T denoting the number of test cases.
Then on the following T lines, there is an integer N, denoting the index of the SuperPower of 2 you need to compute modulo 1000000007.
Output

For each test case, output a single line containing the required value: the Nth SuperPower of 2 modulo 1000000007.
Constraints

1 ≤ N ≤ 600000
T = 100000 on each official test-case file.
Note: Your code will be judged against several input files.
Example

Input:
100000
1
2
(and 99998 more test cases...)


Output:
4
1048576
(and 99998 more answers...)

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0
#define MAX 600000
#define M 1000000007LL

typedef unsigned long long uint64;
//uint64 Output[MAX];


uint64 PowMod(uint64 x, uint64 e,uint64 mod)
{
  uint64 res;

  if (e == 0)      res = 1;
  else if (e == 1) res = x;
  else
  {
    res = PowMod(x, e / 2, mod);
    res = ( res % mod ) * ( res % mod ) % mod;
    if (e % 2) res = (res % mod ) * ( x % mod ) % mod;
  }

  return res;
}

void revStr(char * A,int index)
{
   char t;
   for(int i=0;i<index/2;i++)
   {
      t = A[i];
      A[i] = A[index - i - 1];
      A[index - i - 1] = t;
   }
}
void bin(int n,char * A)
{
    int i,index = 0;
    int p = 1;
    while(n > 0)
    {
       A[index++] = (n & 1) + '0';
       n = n>>1;
    }
    A[index] = '\0';
    revStr(A,index);
}


void PreProcess()
{
   char buf[1024]; uint64 k;
   for(int i=0;i<MAX;i++)
   {
       bin(i + 1,buf);
       sscanf(buf,"%llu",&k);
       k *= 2;
       if(DEBUG) printf("%llu\n",k);
       //Output[i] = PowMod(2,k,M);
   }
}

int main()
{
    
    // Create Look up table first
    int T,base;
    scanf("%d",&T);
    //PreProcess();
    while(T--)
    {
       scanf("%d",&base);
       char buf[1024]; uint64 k;  
       bin(base,buf);
       sscanf(buf,"%llu",&k);
       if(DEBUG) printf("%llu\n",k);
       printf("%llu\n", PowMod(PowMod(2,k,M),2,M));
    }
    
    return 0; 
}