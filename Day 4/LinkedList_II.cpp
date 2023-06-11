/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/
#include<bits/stdc++.h>
Node *firstNode(Node *head)
{
    //    Write your code here.

    // Node *slow = head, *fast = head;
	// while(fast->next != NULL && fast->next->next != NULL){
	// 	slow = slow->next;
	// 	fast = fast->next->next;
	// 	if(slow == fast){
	// 		return fast;
	// 	}
	// }

	unordered_map<Node*, int>m;
	while(head != NULL){
		if(m[head] == 1){
			return head;
		}
		m[head]++;
		head = head->next;
	}
	return head;
}
