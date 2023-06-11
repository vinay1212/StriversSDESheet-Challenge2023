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

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.

    // int count = 0;
  // LinkedListNode<int> *temp = head;
  // while(temp != NULL){
  //     count++;
  //     temp = temp->next;
  // }
  // int a = count/2;
  //     stack <int> s;
  //     while(a>0){
  //         s.push(head->data);
  //         head = head->next;
  //         a--;
  //     }
  //     if(count%2 == 1)
  //         head = head->next;
  //     while(head != NULL && !s.empty()){
  //         if(s.top() != head->data)
  //             return false;
  //         s.pop();
  //         head = head->next;
  //     }

  // return true;
    if(head == NULL || head->next == NULL)
        return true;

    int count = 0;
    LinkedListNode<int> *temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    int a = count/2;
    LinkedListNode<int> *con = head, *ptr = head;
    while(a > 0){
        con = ptr;
        ptr = ptr->next;
        a--;
    }
    if (count % 2 == 1) {
        con = ptr;
        ptr = ptr->next;
    }

    LinkedListNode<int> *prev = NULL, *curr, *nxt;
    while(ptr != NULL){
        nxt = ptr->next;
        curr = ptr;
        ptr->next = prev;
        prev = curr;
        ptr = nxt;
    }
    con->next = prev;
    con = con->next;

    while(con != NULL){
        if(head->data != con->data){
            return false;
        }
        head = head->next;
        con = con->next;
    }
    return true;

}
