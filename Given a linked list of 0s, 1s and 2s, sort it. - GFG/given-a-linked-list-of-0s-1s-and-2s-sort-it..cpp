//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    void linkage(Node * &tail , Node * curr){
        tail->next = curr;
        tail = curr;
    }
    Node* segregate(Node *head) {
        Node* dummy0 = new Node(-1);
        Node* next0=dummy0;
        
        Node* dummy1 = new Node(-1);
        Node* next1 = dummy1;
        
        Node* dummy2 = new Node(-1);
        Node* next2 = dummy2;
        
        Node * curr = head;
        
        while(curr != nullptr){
            int val = curr->data;
            
            if(val == 0){
                linkage(next0 , curr);
                }
            else if(val == 1){
                linkage(next1 , curr);
                }
            else if(val == 2){
                linkage(next2 , curr);
                }
            curr = curr->next;
        }
      //merge 3 sublist
    
    // 1s list not empty
    if(dummy1 -> next != NULL) {
        next0 -> next = dummy1 -> next;
    }
    else {
        //1s list -> empty
        next0-> next = dummy2 -> next;
    }
    
    next1 -> next = dummy2 -> next;
    next2 -> next = NULL;
    
	//setup head 
    head = dummy0 -> next;
    
    //delete dummy nodes
    delete dummy0;
    delete dummy1;
    delete dummy2;
    
    return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends