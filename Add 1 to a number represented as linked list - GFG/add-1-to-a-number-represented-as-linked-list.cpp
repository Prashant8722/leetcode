//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = nullptr;
        
        while(curr != nullptr){
            Node* next  = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head = reverse(head);
        
        Node* curr = head;
        int carry = 1;
        
        while(curr != nullptr){
            int sum = curr->data +  carry;
            curr->data = sum % 10;
            carry = sum / 10;
            if (carry == 0) {
            break; // No need to propagate carry further
        }
            curr = curr->next;
        }
        //if still carry is there we have to create one new node and link it
        if(carry > 0){
              // If there's still a carry left, create a new node for it
        Node* newCarryNode = new Node(carry);
        curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newCarryNode;
        }
        curr = reverse(head);
        return curr;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends