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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
       if(head->next == nullptr) return head;
       
       Node * curr = head;
       Node *oddLink = nullptr , *evenLink = nullptr;
       Node* oddEnd = nullptr , *evenEnd = nullptr;
       
       while(curr != nullptr){
           if(curr->data % 2 == 1){
               //odd number
               if(oddLink == nullptr){
                   oddLink = curr;
                   oddEnd = curr;
                //   oddEnd->next = nullptr;
               }
               else if(oddEnd != nullptr){
                   oddEnd->next = curr;
                   oddEnd = oddEnd->next;
               }
           }
           else{
               //even number
               if(evenLink == nullptr){
                   evenLink = curr;
                   evenEnd = curr;
               }
               else if(evenEnd != nullptr){
                   evenEnd->next = curr;
                   evenEnd = evenEnd->next;
               }
           }
           curr = curr->next;
       }
        // Terminate both lists
       if (evenEnd != nullptr) evenEnd->next = nullptr;
      if (oddEnd != nullptr) oddEnd->next = nullptr;
           // Merge the even list with the odd list
    if (evenLink != nullptr) {
        evenEnd->next = oddLink;
        return evenLink;
    } else {
        return oddLink;
    }
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends