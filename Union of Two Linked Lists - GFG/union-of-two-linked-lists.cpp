//{ Driver Code Starts
#include<bits/stdc++.h>
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


// } Driver Code Ends
/*
// structure of the node is as follows

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
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        typedef struct Node* node; // previous submission it is not used 
        set<int>s;
        node h1 =head1;
        node h2 =head2;
        while(h1 != NULL || h2 != NULL){
            if(h1 != NULL){
                s.insert(h1->data);
                h1 = h1 -> next;
            }
            if(h2 != NULL){
                s.insert(h2->data);
                h2 = h2->next;
                
            }
        }
        // sort(s.begin() , s.end());
        node head = NULL;
        node curr = NULL;
        
        auto it = s.begin();
        
        while(it != s.end())
        {
            
            node create = new Node(*it);
            
            if(head == NULL){
                head = create;
                curr = head;
            }
            else{
                curr->next = create;
                curr = curr->next;
            }
            create->next = NULL; // previous submission it is not used
            it++;
        }
        return head;
    }
};


//{ Driver Code Starts.

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
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends