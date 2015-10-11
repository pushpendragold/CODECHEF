/*
Problem URL : http://www.codechef.com/JULY14/problems/FROGV 
Status      : Not AC 
 
Algo Type   : Disjoint Sets
Time Complexity : O(log (n) + n log(n)) // because of sorting
Space Complexity: O(log(n) + n)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<bitset>
#include<cstdlib>
#include<queue>
#include<stdint.h>
#include<unistd.h>
#include<utility>
#include<fstream>
#include<sstream>
#include<stack>
#include<cstdio>
#include<ctime>
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
 
#define DEBUG 0
#define MAX   10000001
using namespace std;

class FastInput {
	public:
		FastInput() {
			m_dataOffset = 0;
			m_dataSize = 0;
			m_v = 0x80000000;
		}
		uint32_t ReadNext() {
			if (m_dataOffset == m_dataSize) {
				int r = read(0, m_buffer, sizeof(m_buffer));
				if (r <= 0) return m_v;
				m_dataOffset = 0;
				m_dataSize = 0;
				int i = 0;
				if (m_buffer[0] < '0') {
					if (m_v != 0x80000000) {
						m_data[m_dataSize++] = m_v;
						m_v = 0x80000000;
					}
					for (; (i < r) && (m_buffer[i] < '0'); ++i);
				}
				for (; i < r;) {
					if (m_buffer[i] >= '0') {
						m_v = m_v * 10 + m_buffer[i] - 48;
						++i;
					} else {
						m_data[m_dataSize++] = m_v;
						m_v = 0x80000000;
						for (i = i + 1; (i < r) && (m_buffer[i] < '0'); ++i);
					}
				}
			}
			return m_data[m_dataOffset++];
		}
	public:
		uint8_t m_buffer[32768];
		uint32_t m_data[16384];
		size_t m_dataOffset, m_dataSize;
		uint32_t m_v;
};
class FastOutput 
{
	public:
		FastOutput() {
			m_dataOffset = 0;
		}
		~FastOutput() {
		}
		void Flush() {
			if (m_dataOffset) {
				if (write(1, m_data, m_dataOffset));
				m_dataOffset = 0;
			}
		}
        void PrintChar(char d) {
			if (m_dataOffset + 1 > sizeof(m_data)) Flush();
			m_data[m_dataOffset++] = d;
		}
		
		void PrintStr(int i) {
			if(i==0){ PrintChar('N');PrintChar('o'); } 
            else {PrintChar('Y');PrintChar('e');PrintChar('s');
			}
			PrintChar('\n');
		}

        void ReplaceChar(int offset, char d) {
			m_data[m_dataOffset + offset] = d;
        }
	public:
		uint8_t m_data[3268];
		size_t m_dataOffset;
};

typedef struct Data
{
    uint32_t frog_id;
    uint32_t dist;
}Data;

FastOutput f_out;
FastInput f_in;

struct comp
{
    bool operator()( const Data &a, const Data &b )
    {
        return a.dist < b.dist;
    }
};

void ProcessInput(list<Data> &A,int P,int K)
{
    A.sort(comp());
    if(DEBUG) 
    {
        //for(int i = 0; i < A.size(); ++i) 
            //cout<<A[i].frog_id<<" "<<A[i].dist<<endl;
    }
    int sets[A.size()];
    int set_count = 1;
    int prev_dist = -1;

    for(list<Data>::iterator it = A.begin(); it != A.end(); ++it) 
    {
        if( it == A.begin() ) 
            sets[it->frog_id] = set_count;
        else
        {
            if( it->dist - prev_dist <= K ) 
                sets[it->frog_id] = set_count;
            else
                sets[it->frog_id] = ++set_count;
        }
        prev_dist = it->dist;
    }
 
    if(DEBUG) 
    {
        for(int i = 0; i < A.size(); ++i) 
            cout<<i+1<<" "<<sets[i]<<endl;
    }
    
    uint32_t a,b;
    for(int i = 0; i < P; ++i) 
    {
        a = f_in.ReadNext();
        b = f_in.ReadNext();
        if(sets[a-1] == sets[b-1]) 
            printf("Yes\n");
        else
            printf("No\n");
    }
}

int main()
{
    uint32_t N,P,K,a,b;
    N = f_in.ReadNext();
    P = f_in.ReadNext();
    K = f_in.ReadNext();

    list<Data> A;
    A.resize(N);
    int i = 0;
    for(list<Data>::iterator it = A.begin(); it != A.end(); ++it,++i)
    {
        it->frog_id = i;
        it->dist = f_in.ReadNext();
    }
    ProcessInput(A,P,K);
    return 0;
}

/*
Problem Statement : 
 
Nobody knows, but N frogs live in Chef's garden.
Now they are siting on the X-axis and want to speak to each other. One frog can send a message to another one if the distance between them is less or equal to K.
Chef knows all P pairs of frogs, which want to send messages. Help him to define can they or not!
Note : More than 1 frog can be on the same point on the X-axis.
 
Input

The first line contains three integers N, K and P.
The second line contains N space-separated integers A1, A2, ..., AN denoting the x-coordinates of frogs".
Each of the next P lines contains two integers A and B denoting the numbers of frogs according to the input.
 
Output

For each pair print "Yes" without a brackets if frogs can speak and "No" if they cannot.
 
Constraints

1 <= N, P <= 10^5
0 <= Ai, K <= 10^9
1 <= A, B <= N
 
Example

Input:
5 3 3
0 3 8 5 12
1 2
1 3
2 5

Output:
Yes
Yes
No

Explanation
For pair (1, 2) frog 1 can directly speak to the frog 2 as the distance between them is 3 - 0 = 3 <= K . 
For pair (1, 3) frog 1 can send a message to frog 2, frog 2 can send it to frog 4 and it can send it to frog 3.
For pair (2, 5) frogs can't send a message under current constraints.  
 
*/
