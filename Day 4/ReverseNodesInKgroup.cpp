// ### Approach1: (Using vector of stacks)

// - Basic idea is create vector of stacks & insert each block elements into stacks, then pop out these elements and insert into list
// - firstly, create n stacks, (n = no. of blocks) (vector of stacks)
// - traverse the linked list, insert b[ i ] elements into i’th stack,
// - now, start with the first stack & pop out the first stack, insert into linked list, then pop out the second stack insert into same list
// - in this way, it will reverse the given linked list into groups
    
    
//     - Time complexity : O(N)
//     - space Complexity : O(N)


#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.

	vector<stack<int>>v(n);
	Node *ptr = head;
	int i = 0;
	while(head != NULL && i < n){
		int j = 0;
		while(j < b[i] && head != NULL){
			v[i].push(head->data);
			head = head->next;
			j++;
		}
		i++;
	}
	i = 0;
	Node *temp = ptr;
	while(temp != NULL && i < n){
		int j = 0;
		while(j < b[i] && temp != NULL){
			temp->data = v[i].top();
			v[i].pop();
			temp = temp->next;
			j++;
		}
		i++;
	}
	return ptr;
}
