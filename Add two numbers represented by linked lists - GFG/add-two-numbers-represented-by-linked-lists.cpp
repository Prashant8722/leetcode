//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node* h1){
      struct Node* curr = h1;
      struct Node* prev = NULL;
      struct Node* next = NULL;
      
      while(curr != NULL){
          next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
      }
      return prev;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
      first = reverse(first);
     second =  reverse(second);
     
     struct Node* h1 = first;
     struct Node* h2 = second;
     int carry = 0;
     struct Node* head = NULL;
     struct Node* rear = NULL;
     
     while(h1 != NULL && h2 != NULL){
        int sum = (carry + h1->data + h2->data);
        if(sum >= 10 )
            carry = 1;
        else 
            carry = 0;
        struct Node* h = new Node(sum % 10);
         if(head == NULL) {
           head = h;
           rear = h;
         }
         else{
             rear->next = h;
             rear = rear -> next;
         }
         h1 = h1->next;
         h2= h2->next;
     }
        if( h1 != NULL){
            while(h1 != NULL){
                int sum = (carry + h1->data);
                    if(sum >= 10 )
                        carry = 1;
                    else
                        carry = 0;
                 struct Node* h = new Node(sum % 10);
                 rear->next = h;
                 rear = rear->next;
                 h1 = h1->next;
          
        }
        }
        if( h2 != NULL){
           while(h2 != NULL){
                int sum = (carry + h2->data);
                    if(sum >= 10 )
                        carry = 1;
                    else
                        carry = 0;
                 struct Node* h = new Node(sum % 10);
                 rear->next = h;
                 rear = rear->next;
                 h2 = h2->next; 
        }
        }
        if(carry == 1){
          struct Node* h = new Node(1);
                 rear->next = h;
                 rear = rear->next;
        }
       return reverse(head);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends