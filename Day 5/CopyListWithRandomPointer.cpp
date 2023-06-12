#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    map<LinkedListNode<int> *, LinkedListNode<int> *>mp;
        if(head == NULL)
            return NULL;
        int t = head->data;
        LinkedListNode<int> * node = new LinkedListNode<int>(t);
        mp[head] = node;
        LinkedListNode<int> *listB = node;
        LinkedListNode<int> *temp = head->next;
        

        while(temp != NULL){
            int t = temp->data;  
            LinkedListNode<int> * newnode = new LinkedListNode<int>(t);
            node->next = newnode;
            node = node->next;
            mp[temp] = node;
            temp = temp->next;
        }

        LinkedListNode<int> *ptr = listB;
        while(ptr != NULL){
            LinkedListNode<int> * q = head->random;
            if(q == NULL){
                ptr->random = temp;
            }
            else{
                ptr->random = mp[q];
            }
            
            ptr = ptr->next;
            head = head->next;
        }

        return listB;
}
