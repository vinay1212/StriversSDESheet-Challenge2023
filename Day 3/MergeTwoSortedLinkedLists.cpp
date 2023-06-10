// ### Approach1: creating new nodes

// - create new linked list by using data values of the given two lists.
// - create new head & ptr pointers, ptr will traverse the list along with values & head will be used to return the pointer of list
// - check if any of given list is empty, if yes return another list
// - to initiate ptr & head pointers, find min of two lists, and start this node, move to next address of that list,
// - run while loop until any of the lists become NULL
//     - create new node of temp.
//     - compare nodes of two lists, check which is min, assign its value to temp node, keep address of next node for temp as NULL
//     - point next pointer of ptr to this temp node, then move ptr to next node(ie. this temp node)
// - Now one of two lists are empty, point the ptr to the remaining lists address
// - return head pointer.

// - Time complxity : O(N+M)


#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;

    Node<int>* head, *ptr;

    if (first->data <= second->data) {
      head = first;
      first = first->next;
    } else if (second->data < first->data) {
      head = second;
      second = second->next;
    }
    ptr = head;

    while(first != NULL && second != NULL){
        Node <int>* temp = new Node <int>(0);
        
        if(first->data < second->data){
            temp->data = first->data;
            temp->next = NULL;
            first = first->next;
        }
        else{
            temp->data = second->data;
            temp->next = NULL;
            second = second->next;
        }
        head->next = temp;
        head = head->next;
    }

    if(first == NULL && second != NULL){
        head->next = second;
    }
    else if (second == NULL && first != NULL){
        head->next = first;
    }
    return ptr;
}

