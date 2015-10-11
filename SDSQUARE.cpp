/*
 
Recently Chef become very much interested in perfect squares. We all know Chef and his weird interests. Anyways Chef will be soon writing his masters thesis on 
perfect squares revealing what-not-known properties of perfect squares.While doing his research, he happened to be confronted with some interesting perfect 
squares. These prefect squares consists only of digits which are themselves perfect squares. 0, 1, 4 and 9 are such digits. These are called perfect digits.
As we all know Chef also has habit of asking too many questions, he is asking- given two numbers a and b, how many perfect squares exists between these two 
numbers inclusive, that contains only perfect digits. 
 
Input:
First line of input will contains T, number of test cases. Then T lines follows, each containing two positive integers a and b.
Constraints:
T <= 500
1<= a <= b <= 10000000000 
 
Output:
For each input, output number of perfect digit squares between given numbers. 
Sample
 
Input:
2
1 10
100 10000
Output:
3
9 
 
Trick : To pass time limit has to use precomputation 
 
*/

#include <stdio.h>
#include <math.h>
 
 
unsigned long long anslist[] = {1l, 4l, 9l, 49l, 100l, 144l, 400l, 441l, 900l, 1444l, 4900l, 9409l, 10000l, 10404l, 
                                11449l, 14400l, 19044l, 40000l, 40401l, 44100l, 44944l, 90000l, 144400l, 419904l, 
                                490000l, 491401l, 904401l, 940900l, 994009l, 1000000l, 1004004l, 1014049l, 1040400l, 1100401l, 
                                1144900l, 1440000l, 1904400l, 1940449l, 4000000l, 4004001l, 4040100l, 4410000l, 4494400l, 9000000l, 
                                9909904l, 9941409l, 11909401l, 14010049l, 14040009l, 14440000l, 19909444l, 40411449l, 41990400l, 
                                49000000l, 49014001l, 49140100l, 49999041l, 90440100l, 94090000l, 94109401l, 99400900l, 99940009l, 
                                100000000l, 100040004l, 100140049l, 100400400l, 101404900l, 101949409l, 104040000l, 104919049l, 
                                110040100l, 111049444l, 114041041l, 114490000l, 144000000l, 190440000l, 194044900l, 400000000l, 
                                400040001l, 400400100l, 404010000l, 404090404l, 409941009l, 414000409l, 414041104l, 441000000l, 
                                449440000l, 490091044l, 900000000l, 990990400l, 991494144l, 994140900l, 1190940100l, 1401004900l, 
                                1404000900l, 1409101444l, 1444000000l, 1449401041l, 1490114404l, 1990944400l, 4014109449l, 
                                4019940409l, 4041144900l, 4199040000l, 4900000000l, 4900140001l, 4901400100l, 4914010000l, 
                                914991449l, 4941949401l, 4999904100l, 9044010000l, 9409000000l, 9409194001l, 9410940100l, 
                                9900449001l, 9940090000l, 9994000900l, 9999400009l, 10000000000l};
int main()
{
	long long T = 0, a, b, _a, ans, n;
	int i = 0;
	scanf("%llu", &T);
	
	while(T--)
	{
		scanf("%llu%llu", &a, &b);
	
		ans = 0;
 
		for (i = 0; i < 120 ; ++i)
			if (anslist[i] >= a && anslist[i] <=b ) ++ans;
 
		printf("%lld\n", ans);
	}
	return 0;
} 
