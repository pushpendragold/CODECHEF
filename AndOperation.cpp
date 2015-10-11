/*
Problem URL : http://www.codechef.com/LTIME14/problems/TAAND
Algo Type   : 
Time Complexity : 
Space Complexity:
*/

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

class node
{
    int val;
    bool isLeaf;
    node *left;
    node *right;
    
public: 
	node()
    {
        val = 0;
        isLeaf = false;
        left = NULL;
        right = NULL;
    }
	void  setVal(int n) { val = n; }
	int   getVal() { return val; }
	void  setLeftChild(node *ptr) { left = ptr; }
	void  setRightChild(node *ptr) { right = ptr; }
	node* getLeftChild()  { return left; }
	node* getRightChild() { return right; }
	void  setIsLeaf(bool b) { isLeaf = b; }
	bool  getIsLeaf() { return isLeaf; }
};
 
 
class Tree
{

private:

	node *root;
    int heightOfTree ;

public: 
    
    Tree()
    {
        root = new node();
        root->setVal(99);
        heightOfTree = 31;
    }
    
    int getMSBPosition() { return 0; }
	void insertNode(node* ptr, int n, int pos)
    {
        if(pos >= 0)
        {
            int getBit = (1<<pos) & n;
            node* newNode;
            if( getBit )
            {
                if(ptr->getRightChild() == NULL)
                {
                    newNode = new node();
                    newNode->setVal(1);
                    ptr->setRightChild(newNode);
                }
                if(pos == 0)
                {
                    node* leafNode = new node();
                    newNode->setIsLeaf(true);
                    leafNode->setVal(n);
                    newNode->setLeftChild(leafNode);
                }
                else
                    insertNode(ptr->getRightChild(),n,pos-1);
            }
            else
            {
                if(ptr->getLeftChild() == NULL)
                {
                    newNode = new node();
                    newNode->setVal(0);
                    ptr->setLeftChild(newNode);
                }
                if(pos == 0)
                {
                    node* leafNode = new node();
                    leafNode->setVal(n);
                    newNode->setIsLeaf(true);
                    newNode->setLeftChild(leafNode);
                }
                else
                    insertNode(ptr->getLeftChild(),n,pos-1);
            }
        }
    }
    
    void insert(int n)
    {
        insertNode(root, n , heightOfTree);
    }
    
    int findMax(node* ptr1, node* ptr2)
    {
        if(ptr1->getIsLeaf() == false)
        {
            int n01 = 0;
            int n10 = 0;
            bool pathTaken = false;

            if(ptr1->getLeftChild() != NULL && ptr2->getRightChild() != NULL)
            {
                n01 = findMax(ptr1->getLeftChild(),ptr2->getRightChild());                
                pathTaken = true;
            }

            if(ptr1->getRightChild() != NULL && ptr2->getLeftChild() != NULL)
            {
                n10 = findMax(ptr1->getRightChild(),ptr2->getLeftChild());
                pathTaken = true;
            }

            if(!pathTaken)
            {
                if(ptr1->getLeftChild() && ptr2->getLeftChild())
                    n01 = findMax(ptr1->getLeftChild(),ptr2->getLeftChild());
                else
                    n10 = findMax(ptr1->getRightChild(),ptr2->getRightChild());
            }
            return n01 > n10 ? n01 : n10;
        }
        else
        {
            return (ptr1->getLeftChild()->getVal()) & (ptr2->getLeftChild()->getVal());
        }
    }
    int findMaxValue()
    {
        return findMax(root,root);
    }
    
};

int main()
{
    int T,a;
	Tree t ;
	scanf("%d",&T);

    while(T--) 
    {
        scanf("%d",&a);
        t.insert(a);
    }
    cout<<t.findMaxValue()<<endl;
	return 0;
}


