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
Here's the algorithm for the provided code to remove all the nodes from the singly linked list that have a greater value on their right side:

Algorithm:

1. Create a helper function `reverse` to reverse the linked list. This function takes the head of the list as input and returns the new head of the reversed list.

2. Check if the input `head` is null or the list contains only one node (`head->next == nullptr`). If either of these conditions is true, return the `head` as there is nothing to remove.

3. Reverse the linked list using the `reverse` function to make it easier to process nodes from right to left.

4. Initialize three pointers: `maxNode`, `curr`, and `prev` as follows:
   - Set `maxNode = head`, pointing to the first node of the reversed list.
   - Set `curr = head->next`, pointing to the second node of the reversed list.
   - Set `prev = head`, pointing to the first node of the reversed list.

5. Traverse the reversed list using `curr` and `prev` pointers until `curr` becomes null:
   - If the `data` of `curr` is greater than or equal to the `data` of `maxNode`, update `maxNode = curr` and move both `curr` and `prev` to their next nodes.
   - If the `data` of `curr` is less than the `data` of `maxNode`, it means that the current node has a greater value on its right side. In this case, remove the current node by updating `prev->next = curr->next` and delete `curr`. Then, move `curr` to the next node without moving `prev`.

6. After the traversal is complete, the modified list contains only the nodes that do not have a greater value on their right side. Reverse the list back to its original order using the `reverse` function.

7. Return the head of the modified list.

This algorithm ensures that the input linked list is modified such that all nodes with a greater value on their right side are removed, and the relative order of the remaining nodes is maintained.
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