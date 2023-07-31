//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * merge(Node *a , Node *b){
        Node *temp = nullptr;
        Node *dummy= new Node(-1);
        Node * tail = dummy;
        
        while(a != nullptr and b != nullptr){
            if(a -> data < b->data ){
                temp = a;
                a = a->next;
            }
            else{
                temp = b;
                b = b->next;
            }
            tail->next = temp;
            temp->next = nullptr;
            tail = tail->next;
        }
        if(a == nullptr){
            tail->next = b;
        }
        if(b == nullptr){
            tail->next = a;
        }
        Node *res = dummy->next;
        
        delete dummy;
        return res;
    }
    Node * mergeKLists(Node *arr[], int K)
    {
          int i;
          int last =K - 1;
          int j;
          while( last > 0 ){
              i = 0; 
              j = last;
              while(i < j){
                  arr[i] = merge(arr[i] , arr[j]);
                  i++;j--;
                  if(i >= j){
                      last = j;
                  }
              }
              
          }
          return arr[0];
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends