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
 typedef long long int INT;

 double GetVal1(double a,double b)
 {
	 return sqrt( b*b - a*a );
 }

 double GetVal2(double a,double b)
 {
	 return sqrt( b*b + a*a );
 }

 double Round(double n)
 {
	 return n;
	 return round(n);
 }

 main()
 {
	int T;
	scanf("%d",&T);
	double a,b;
	while(T--) 
	{
		scanf("%lf %lf",&a,&b);
		printf("%lf %lf\n",Round(GetVal1(a,b)),Round(GetVal2(a,b)));
	}
	return 0;
 }

 /*
  
 Professor Snape has lots of potions. Bottles containing all types of potions are stacked on shelves which cover the entire wall from floor to ceiling. 
 Professor Snape has broken his bones several times while climbing the top shelf for retrieving a potion. He decided to get a ladder for him. But he has 
 no time to visit Diagon Alley. So he instructed Ron Weasley to make a ladder for him. Professor Snape specifically wants a step ladder which looks like 
 an inverted 'V' from side view.

Professor just mentioned two things before vanishing-
B - separation between left side (LS) and right side (RS) on the ground
LS - the length of left side
What should be the length of RS? At one extreme LS can be vertical and at other RS can be vertical. Ron is angry and confused. Since Harry is busy battling  
 Voldemort, its your duty to help him find the minimum and maximum length of RS.
Input

First line contains single integer T, the number of test cases. Then T lines follow each containing 2 integers - B and LS.
Output

Output T lines, each containing minimum value of RS and maximum value of RS, separated by space. The answer (RS) will be considered correct if it has relative  
and absolute error less than 10-2.
Constraints

1 ≤ T ≤ 1000
1 ≤ B < LS ≤ 1000
Example

Input:
3
4 5
10 12
10 20

Output:
3.0 6.40312
6.63325 15.6205
17.3205 22.3607 
  
 */
