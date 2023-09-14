//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

// TIme Complexity ===> O(n^2) Space complexity O(n)

class Solution {
public:
    int preInd = 0; // Initialize a global variable to keep track of the current index in the pre-order traversal array.

    // Recursive function to construct a binary tree from its in-order and pre-order traversals.
    Node* tree(int *in, int* pre, int is, int ie) {
        if (is > ie) {
            return nullptr; // Base case: If the in-order traversal indices are invalid, return null.
        }

        int ind;
        Node* root = new Node(pre[preInd++]); // Create a new node using the next element in the pre-order traversal.

        // Find the index of the current node's value in the in-order traversal.
        for (int i = is; i <= ie; i++) {
            if (in[i] == root->data) {
                ind = i;
                break;
            }
        }

        // Recursively build the left and right subtrees.
        root->left = tree(in, pre, is, ind - 1);
        root->right = tree(in, pre, ind + 1, ie);

        return root; // Return the constructed root of the subtree.
    }

    // Main function to build a binary tree from in-order and pre-order traversals.
    Node* buildTree(int in[], int pre[], int n) {
        Node* res = tree(in, pre, 0, n - 1); // Call the helper function to build the tree.
        return res; // Return the root of the constructed binary tree.
    }

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends