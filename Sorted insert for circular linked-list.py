"""

5 February 2024

Given a sorted circular linked list of length n, the task is to insert a new node in this circular list so that it remains a sorted circular linked list.

Example 1:

Input:
n = 3
LinkedList = 1->2->4
(the first and last node is connected, i.e. 4 --> 1)
data = 2
Output: 
1 2 2 4
Explanation:
We can add 2 after the second node.
Example 2:

Input:
n = 4
LinkedList = 1->4->7->9
(the first and last node is connected, i.e. 9 --> 1)
data = 5
Output: 
1 4 5 7 9
Explanation:
We can add 5 after the second node.
Your Task:
The task is to complete the function sortedInsert() which should insert the new node into the given circular linked list and return the head of the linked list.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
0 <= n <= 105

"""

#User function Template for python3

'''
class Node: 
    # Constructor to initialize the node object 
    def __init__(self, data): 
        self.data = data 
        self.next = None
  '''
class Solution:
    def sortedInsert(self, head, data):
        #code here
        newNode = Node(data)
        
        if head is None:
            newNode.next = newNode
            head = newNode
            
        elif head.data >= newNode.data:
            temp = head
            while temp.next != head:
                temp = temp.next
            temp.next = newNode
            newNode.next = head
            head = newNode
            
        else:
            current = head
            while current.next != head and current.next.data < newNode.data:
                current = current.next
            newNode.next = current.next
            current.next = newNode
            
        return head
#{ 
 # Driver Code Starts
#contributed by RavinderSinghPB
class Node: 
    # Constructor to initialize the node object 
    def __init__(self, data): 
        self.data = data 
        self.next = None
  
class LinkedList: 
  
    # Function to initialize head 
    def __init__(self): 
        self.head = None
        self.last=None
  
    # Function to insert a new node  
    def push(self, data):
        if not self.head:
            nn=Node(data)
            self.head=nn
            self.last=nn
            nn.next=nn
            return
        nn=Node(data)
        nn.next=self.head
        self.last.next=nn
        self.last=nn 
  

# Utility function to print the linked LinkedList

def printList(head):
    if not head:
        return
    temp = head 
    print (temp.data,end=' ') 
    temp = temp.next
    while(temp != head): 
        print (temp.data,end=' ') 
        temp = temp.next
  
    
if __name__ =='__main__':
    t=int(input())
    for tcs in range(t):
        n=int(input())
        arr=[int(x) for x in input().split()]
        data=int(input())

        cll=LinkedList()
        for e in arr:
            cll.push(e)
            
        reshead=Solution().sortedInsert(cll.head,data)
        printList(reshead)
        print()
        


# } Driver Code Ends
