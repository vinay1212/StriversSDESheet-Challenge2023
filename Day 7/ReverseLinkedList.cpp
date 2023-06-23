// ### Approach1:

// - first traverse the given list, insert its all nodes into vector,
// - now, reverse this vector,
// - traverse the given list again, change node values according to vector

// Time complexity : O(N)

// Space complexity : O(N)

// ### Approach2:

// - create 3 variable to store address of
    
//     *prev(which will be used to update the head—>next pointer), 
    
//     *curr(used to update prev pointer in each loop) and 
    
//     *nxt( used to store address of next node as after updation of head→next it will point to previous node) node
    
// - initialize prev = NULL
// - run a while loop on linked list until the head doesn’t reaches the end
//     - first store the address of next element in nxt
//     - store address of current node in curr
//     - change the address of next node in current node to prev
//     - update the prev to current node
//     - jump the head to next node using nxt
    
//     So, basically we're going through the linked list. We start at the beginning and keep moving forward until we hit the end. Along the way, we're switching the pointers around to reverse the order of the list. Easy peasy, lemon squeezy!




#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int> *prev = NULL, *curr, *nxt;
    while(head != NULL){
        nxt = head->next;
        curr = head;
        head->next = prev;
        prev = curr;
        head = nxt;
    }
    return prev;
}
