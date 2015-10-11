/*
 
Lucy had recently learned the game, called Natural Numbers.
The rules of the game are really simple. There are N players. At the same time, every player says one natural number. Let's call the number said by the i-th player Ai. 
The person with the smallest unique number (that is, the smallest number that was not said by anybody else) wins. Sometimes, there is a case when there are no unique 
numbers at all. Then the game is obviously a draw, so nobody wins it. Sometimes, it's hard to determine the winner, especially, when the number of players is enormous. 
So in this problem, your assignment will be: given the names of the players and the numbers every of them have said. Please, tell the name of the winner, or determine 
that nobody wins.
 
Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of every test case consists of a single integer N - the number of players. Then, N lines will follow. 
Each of these N lines will consist of the player's name and the number Ai said by her, separated by a single space.
Output

For each test case, output a single line containing an answer to the corresponding test case - the name of the winner, or a string "Nobody wins.", 
if nobody wins the game.
Example

Input:
2
5
Kouta 1
Yuka 1
Mayu 3
Lucy 2
Nana 5
2
Lucy 2
Nana 2

Output:
Lucy
Nobody wins. 
 
*/

#include <vector>
#include <map>
#include <iostream>
#include <cstdio>

using namespace std;


enum HEAPTYPE{
  MIN_HEAP,
  MAX_HEAP
};

class PriorityQueue{

private:
  int capacity;
  int count;
  int * A;
  int heap_type;

  int LeftChild(int i);
  int RightChild(int i);
  int Parent(int i);
  
  void PercolateDown(int data);
  void PercolateUp(int data);
  
public:
  PriorityQueue(int _capacity,int _heap_type);
  virtual ~PriorityQueue();
  int Size(){ return count ? count : -1;}
  int Top();
  int DeleteTop();
  void InsertElement(int data);
  void DeleteElement(int data);
  void Heapify(int A[],int n);
};


PriorityQueue::PriorityQueue(int _capacity, int _heap_type)
{
   capacity  = _capacity;
   heap_type = _heap_type;
   count = 0;
   A = new int[capacity];
   for(int i=0;i<capacity;i++)
     A[i] = 0;
}
PriorityQueue::~PriorityQueue()
{
  delete [] A;
}
int PriorityQueue::Parent(int i)
{
   if(i <= 0 || i >= count)
     return -1;
   return (i - 1)/2;
}
int PriorityQueue::LeftChild(int i)
{
   int left = 2*i + 1;
   if(left >= count || A[left] == 0) return -1;
   return left;
}
int PriorityQueue::RightChild(int i)
{
  int right = 2*i + 2;
  if(right >= count || A[right] == 0) return -1;
  return right;
}
int PriorityQueue::Top()
{
   if(count == 0) return -1;
   return A[0];
}
void PriorityQueue::PercolateDown(int i)
{
   int max = -1;
   int left  = LeftChild(i);
   int right = RightChild(i);
   
   if(left != -1 && heap_type == MAX_HEAP && A[left] > A[i]  ||
      left != -1 && heap_type == MIN_HEAP && A[left] < A[i])
    max = left;
   else
    max = i;
   
   if(right != -1 && heap_type == MAX_HEAP && A[right] > A[max] ||
      right != -1 && heap_type == MIN_HEAP && A[right] < A[max])
    max = right;
    
    if(max != i) //Swap with max index
    {
      int tmp = A[i];
      A[i] = A[max];
      A[max] = tmp;
      PercolateDown(max);
    }
}
void PriorityQueue::PercolateUp(int data)
{
   if(data == 0) return;
   int parent = Parent(data);
   if(parent != -1)
   {
      if(heap_type == MAX_HEAP && A[parent] < A[data] ||
	 heap_type == MIN_HEAP && A[parent] > A[data])
      {
	int temp = A[parent];
	A[parent] = A[data];
	A[data] = temp;
	PercolateUp(parent);
      }
   }
}
int PriorityQueue::DeleteTop()
{
   if(count != 0)
   {
     int data = A[0];
     A[0] = A[count - 1];
     A[count - 1] = 0;
     count--;
     PercolateDown(0);
     return data;
   }
   return -1;
}
void PriorityQueue::Heapify(int array[], int n)
{
    for(int i=0;i<n;i++)
      InsertElement(array[i]);
}
void PriorityQueue::InsertElement(int data)
{
    if(count == 0) 
    {
      A[0] = data;
      count++;
      return;
    }
    A[count] = data;
    count++;
    PercolateUp(count - 1);
}
void PriorityQueue::DeleteElement(int data)
{
   int i = 0;
   for(;i<count;i++)
   {
      if(A[i] == data)
	break;
   }
   if(i == count) 
   {
     printf("Element not found in the heap. %d\n",data);
     return;
   }
   A[i] = A[count - 1];
   A[count - 1] = 0;
   count--;
   PercolateDown(i);
}

main()
{
    int T,n,number;
    string player;
    scanf("%d",&T);
    while(T--) 
    {
        scanf("%d",&n);
        PriorityQueue heap(n,MIN_HEAP);

        map< int, string > Num_Lookup;
        map< int , int >   Numbers;

        for(int i=0; i<n; i++ ) 
        {
            cin >> player >> number;

            if(Numbers[number] == 0) Numbers[number] = 1;
            else Numbers[number]++;

            if(Numbers[number] == 1) 
                heap.InsertElement(number);
            else
                heap.DeleteElement(number);
          
            Num_Lookup[number] = player;
        }

        if(heap.Size() == -1) 
            cout<<"Nobody wins"<<endl;
        else
            cout<<Num_Lookup[heap.Top()]<<endl;
   }
   return 0;
}
