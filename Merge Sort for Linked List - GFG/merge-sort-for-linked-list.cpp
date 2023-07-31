//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
    //Finding middle if linkd list
    void middleFind(Node* curr , Node **first , Node **second){
    // if (curr == nullptr || curr->next == nullptr) {
    //     *first = curr;
    //     *second = nullptr;
    //     return;
    // }
    
        Node *slow = curr;
        Node * fast = curr -> next;
        
        while(fast != nullptr){
            fast = fast -> next;
            if(fast != nullptr){
                slow = slow ->next;
                fast = fast ->next;
            }
        }
        
        *first = curr;
        *second = slow -> next;
        slow ->next = nullptr;
    }
    //merge node together by comapring data 
    Node * mergeFun(Node *a , Node *b){

        Node *dummy = new Node(-1);
        Node *tail = dummy;
        Node *temp = nullptr;

        while(a != nullptr and b != nullptr){
            if(a->data < b->data){
                temp = a;
                a = a->next;
            }
            else{
                temp = b;
                b =b->next;
            }
                tail->next = temp ;
                tail = tail->next;
        }
            if(a != nullptr) tail->next = a;
            if(b != nullptr) tail->next = b;
            
            temp =  dummy->next;
            delete dummy;
            return temp;
        }
        //Function which contain d&C and Combine approach;
        void merger(Node **head){
        Node * curr = *head;
        Node *first = nullptr;
        Node *second = nullptr;
        
        if(curr == nullptr or curr->next == nullptr){
            return;
        }
        middleFind(curr , &first , &second);
        merger(&first);
        merger(&second);
        *head = mergeFun(first , second);
    }
        
    Node* mergeSort(Node* head) {
       merger(&head);
       return head;
        }

};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends