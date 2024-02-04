/*

4 February 2024

You are given two linked lists that represent two large positive numbers. From the two numbers represented by the linked lists, subtract the smaller number from the larger one. Look at the examples to get a better understanding of the task.

Example 1:

Input:
L1 = 1->0->0
L2 = 1->2
Output: 88
Explanation:  
First linked list represents 100 and the
second one represents 12. 12 subtracted from 100
gives us 88 as the result. It is represented
as 8->8 in the linked list.
Example 2:

Input:
L1 = 0->0->6->3
L2 = 7->1->0
Output: 647
Explanation: 
First linked list represents 0063 => 63 and 
the second one represents 710. 63 subtracted 
from 710 gives us 647 as the result. It is
represented as 6->4->7 in the linked list.
Your Task:
You do not have to take any input or print anything. The task is to complete the function subLinkedList() that takes heads of two linked lists as input parameters and which should subtract the smaller number from the larger one represented by the given linked lists and return the head of the linked list representing the result.

n and m are the length of the two linked lists respectively.
Expected Time Complexity:  O(n+m)
Expected Auxiliary Space: O(n+m)

Constraints:
1 <= n <= 10000
0 <= values represented by the linked lists < 10n
0 <= values represented by the linked lists < 10m

*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends

//User function Template for C++

class Solution {
public:
 Node* reverse(Node* head) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        Node *prev = NULL , *curr = head , *nxt = head;
        while(nxt) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        Node* ans = head2;
        while(head1){
            if(head1->data == 0) {
                head1 = head1->next;
            }
            else {
                break;
            }
        }
        while(head2) {
            if(head2->data == 0) {
                head2 = head2->next;
            }
            else {
                break;
            }
        }
        if(head1 == NULL && head2 == NULL) {
            ans->next = NULL;
            return ans;
        }
        else if(head1 == NULL) {
            return head2;
        }
        else if(head2 == NULL) {
            return head1;
        }
        Node* temp1 = head1;
        Node* temp2 = head2;
        int count1 = 0;
        int count2 = 0;
        while(temp1) {
            temp1 = temp1->next;
            count1++;
        }
        while(temp2) {
            temp2 = temp2->next;
            count2++;
        }
        if(count1 == count2) {
            if(head1->data == head2->data) {
                while(head1 && head1->data == head2->data){
                    head1 = head1->next;
                    head2 = head2->next;
                }
                if(head1 == NULL && head2 == NULL) {
                    ans->data = 0;
                    ans->next = NULL;
                    return ans;
                }
            }
            if(head1->data > head2->data) {
                temp1 = head1;
            }
            else {
                temp1 = head2;
            }
        }
        else if(count1>count2) {
            temp1 = head1;
        }
        else {
            temp1 = head2;
        }
        if(temp1 == head1) {
            temp1 = reverse(head1);
            temp2 = reverse(head2);
        }
        else {
            temp1 = reverse(head2);
            temp2 = reverse(head1);
        }
        head1 = temp1;
        head2 = temp2;
        bool flag = false;
        while(temp2) {
            if(flag == true) {
                if(temp1->data == 0) {
                    temp1->data = 9;
                    flag = true;
                }
                else {
                    temp1->data = temp1->data - 1;
                    flag = false;
                }
            }
            if(temp1->data >= temp2->data) {
                temp1->data = temp1->data - temp2->data;
            }
            else {
                int n  = 10 - temp2->data;
                temp1->data = temp1->data + n;
                flag = true;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(flag == true) {
            while(temp1->data == 0){
                temp1->data = 9;
                temp1 = temp1->next;
            }
            temp1->data = temp1->data -1;
        }
        temp1 = reverse(head1);
        while(temp1) {
            if(temp1->data == 0) {
                temp1 = temp1->next;
            }
            else {
                break;
            }
        }
        return temp1;
        
       return NULL;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends
