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

#define DEBUG 1
typedef unsigned long long int INT;

class FractionNumbers 
{

private: // (a/b)
		INT a; 
		INT b;

		// Utility function
		INT LCM(INT a,INT b);
		INT GCD(INT a,INT b);

		// Make Perfect fractional number
		void MakePerfectFractional();
		bool CheckValidNumber();

public:
		FractionNumbers(INT _a,INT _b):a(_a),b(_b) {  assert(CheckValidNumber()); MakePerfectFractional(); }
	   ~FractionNumbers(){ }

	    FractionNumbers(const FractionNumbers &rhs);
		void operator =  ( const FractionNumbers &rhs);

		// operators
		FractionNumbers operator += ( const FractionNumbers &rhs);
		FractionNumbers operator +  ( const FractionNumbers &rhs);
		FractionNumbers operator *  ( const FractionNumbers &rhs);

		void Display();
		void Set(INT a,INT b) { this->a = a; this->b = b; MakePerfectFractional(); }
};

int main()
{
	int T;
	INT N,M;
	int eN,oN;
	int eM,oM;

	scanf("%d",&T);
	while(T--) 
	{
		scanf("%llu %llu",&N,&M);
		FractionNumbers c1(0,1),c2(0,1),c3(0,1);
		
		oN = eN = N/2;
		if( N % 2 ) oN++;

		eM = oM = M/2;
		if( M % 2 ) oM++;

		if(DEBUG) 
		{
			cout<< oN << " " << eN << endl;
			cout<< oM << " " << eM << endl;
			cout<< oN * eM <<endl;
			cout<< oM * eN <<endl;
		}
		c1.Set( oN , N * M );
		c2.Set( eM , N * M );
		c1 = c1 * c2;

		c3.Set( oM , N * M );
		c2.Set( eN , N * M );
		c3 = c3 * c2;

		c2 = c1 + c3;
		c2.Display();
	}
	return 0;
}

INT FractionNumbers::GCD(INT a, INT b)
{
  while(b)
  {
	  INT tmp = b;
	  b = a % b;
	  a = tmp;
  }
  return a;
}
 
INT FractionNumbers::LCM(INT a,INT b)
{
	INT g = GCD(a,b);
	assert(g != 0);
	return (a*b)/g;
}

void FractionNumbers::MakePerfectFractional()
{
	if( a == 0 || b == 0 ) return;

	INT g = GCD(a,b);

	if(DEBUG) cout<<" GCD : "<< g << " ( " << a << "," << b << " )\n";

	if( g > 1 ) 
	{
		a = a/g;
		b = b/g;
	}
}

FractionNumbers::FractionNumbers(const FractionNumbers &rhs)
{
	if(DEBUG) { cout<<"Copy constructor called\n"; }
	this->a = rhs.a;
	this->b = rhs.b;
}
void FractionNumbers::operator = ( const FractionNumbers &rhs)
{
	if(DEBUG) { cout<<"Eqaul Operator called\n"; }
	this->a = rhs.a;
	this->b = rhs.b;
}
FractionNumbers FractionNumbers::operator += ( const FractionNumbers &rhs)
{
	INT lcm = LCM(b,rhs.b);
	this->a = rhs.a * (lcm/rhs.b) + this->a * (lcm/this->b);
	this->b = lcm;
	MakePerfectFractional();
}
FractionNumbers FractionNumbers::operator + ( const FractionNumbers &rhs)
{
	FractionNumbers tmp(1,1);
	INT lcm = LCM(rhs.b,this->b);
	tmp.a = rhs.a * (lcm/rhs.b) + this->a * (lcm/this->b);
	tmp.b = lcm;
	tmp.MakePerfectFractional();
	return tmp;
}
FractionNumbers FractionNumbers::operator * ( const FractionNumbers &rhs)
{
	FractionNumbers tmp(1,1);
	tmp.a = this->a * rhs.a;
	tmp.b = this->b * rhs.b;

	tmp.MakePerfectFractional();

	return tmp;
}

void FractionNumbers::Display()
{
	printf("%llu/%llu\n",a,b);
}
bool FractionNumbers::CheckValidNumber()
{
	return b != 0;
}
