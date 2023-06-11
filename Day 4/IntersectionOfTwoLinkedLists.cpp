// ### Approach1:

// - for each node of first list run a loop over other list and check if nodes are equal.
// - first count the number of nodes in both lists, and choose shorter list for outer loop, or slower moving list.
// - for each node of this shorter list, we will check all nodes of second list,
    
//     if equal return node
    
//     else try for second node
    

// - Time complexity : O(M*N)    M,N = nodes in lists

// ### Approach2:

// - Using the hashmap,
// - create hashmap to count nodes of the lists, traverse both lists and find the counts of each node
// - now find the first node in this map to have 2 as count
    
//     return this node
    
//     (Use unoredred_map)
    
//     - Time complexity : O(M+N)
//     - space complexity : O(N)
      
      
      
#include<bits/stdc++.h>
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

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    // Node* f = firstHead;
	// int c1 = 0;
	// while(f != NULL){
	// 	c1++;
	// 	f = f->next;
	// }
	// Node* s = secondHead;
	// int c2 = 0;
	// while(s != NULL){
	// 	c2++;
	// 	s = s->next;
	// }
	// if(c1 <= c2){
	// 	Node *head = firstHead;
	// 	while(head != NULL){
	// 		Node * temp = secondHead;
	// 		while(temp != NULL){
	// 			if(temp == head){
	// 				return temp->data;
	// 			}
	// 			temp = temp->next;
	// 		}
	// 		head = head->next;
	// 	}
	// }
	// Node *head = secondHead;
	// while(head != NULL){
	// 	Node * temp = firstHead;
	// 	while(temp != NULL){
	// 		if(temp == head){
	// 			return temp->data;
	// 		}
	// 		temp = temp->next;
	// 	}
	// 	head = head->next;
	// }
	
	map <Node*, int> m;
	Node* f = firstHead;
	while(f != NULL){
		m[f]++;
		f = f->next;
	}
	Node* s = secondHead;
	while(s != NULL){
		m[s]++;
		s = s->next;
	}
	for(auto it : m){
		if(it.second == 2){
            return it.first;
			
		}
	}
	return NULL;
}
