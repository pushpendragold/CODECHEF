/*
 
Chef doesn't love math anymore. He loves Sasha. Sashen'ka is cute.
Chef goes on a date with her. Flowers are boring, while numbers are not. He knows that most of all this girl loves numbers, that's why he is going to bring 
ribbon with numbers L, L+1, L+2, ..., R written on it. Sasha thinks that numbers with prime number of divisors are special. That's why she is going to kiss 
boy for each such number he will bring.Now Chef wonder how many times he will be kissed by Sashen'ka ?
 
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two number L, R.
 
Output

For each test case, output a single line containing answer for corresponding test case.
 
Constraints

1 <= T <= 5
1 <= L <= R <= 10^12
0 <= R-L <= 10^6
 
Example

Input:
1
1 10

Output:
6
 
Explanation

Example case 1. Numbers 2,3,4,5,7,9 are special. 
 
*/

#include<stdio.h>
#include<math.h>
 
char a[1000004];
int b[80000],c[15];
 
void sieve()
{
	long long i,j,y,p=1;
	b[0]=2;
	for(i=1;i<500000;i++)
	{
		if(a[i]==0)
		{
			j=2*i+1;
			b[p++]=j;
			y=i*(j+1);
			while(y<500000)
			{
				a[y]=1;
				y+=j;
			}
		}
	}
	b[p]=10000000;			//last value of p=78497
	for(i=0;i<15;i++)
		c[i]=b[i]-1;
}
	
main()
{
	sieve();
	
	long long t,m,n,z,l,i,j,k,ans,M,N;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&m,&n);
		if(m==1)
			m=2;
		l=n-m;
		for(z=0;z<l+2;z++)
			a[z]=0;
		
		i=0;		//prime finder
		j=sqrt(n);
		while(b[i]<=j)
		{
			k=((m-1)/b[i]+1);
			if(k<2)
				k=2;
			k=k*b[i]-m;
			while(k<=l)
			{
				a[k]++;
				k+=b[i];
			}
			i++;
		}
		ans=0;
		for(i=0;i<=l;i++)
			if(a[i]==0)
				ans++;
		
		m--;
		for(i=1;i<15;i++)
		{
			double X1,X2,Y1,Y2;
			long long Z1,Z2,I,J;
			
			X1=log10(m)/(c[i]*1.0);
			Y1=pow(10,X1);
			Z1=(long long)Y1;
			
			X2=log10(n)/(c[i]*1.0);
			Y2=pow(10,X2);
			Z2=(long long)Y2;
			
			if(Z2==1)
				break;		
			I=0;
			while(b[I]<=Z1)
				I++;
			J=I;
			while(b[I]<=Z2)
				I++;
			ans+=I-J;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
