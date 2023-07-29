//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

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
class Solution
{
    public:
    /*
    Node *compute(Node *head)
    {
        if(head->next == nullptr) return head;
        Node *bkd = nullptr;
        Node *curr= head;
        Node *fwd = head->next;
        
        while(fwd != nullptr){
        if(head == curr && head->data < fwd->data){
                head = head->next;
                curr->next = nullptr;
                delete(curr);
                curr = fwd;
                
                // fwd = fwd->next;
            }
        else if(curr->data < fwd ->data){
            
            bkd->next = curr->next;
            curr->next = nullptr;
            delete(curr);
            curr = fwd;
            // fwd = fwd -> next;
        }
        else{
                bkd = curr;
                curr = curr->next;
                // fwd = fwd ->next;
            }
               fwd = fwd ->next;
        }
        return head;
    }
   */ 
   Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node* compute(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    // Reverse the list to process nodes from right to left
    head = reverse(head);

    Node* maxNode = head;
    Node* curr = head->next;
    Node* prev = head;

    while (curr != nullptr) {
        if (curr->data >= maxNode->data) {
            // If the current node has a greater or equal value than maxNode
            // update maxNode and move curr to the next node
            maxNode = curr;
            curr = curr->next;
            prev = prev->next;
        } else {
            // If the current node has a smaller value than maxNode
            // remove the current node
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
    }

    // Reverse the list back to its original order
    head = reverse(head);
    return head;
}
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends