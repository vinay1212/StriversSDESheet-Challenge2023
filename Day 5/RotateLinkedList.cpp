/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.

     if(k == 0)
	 	return head;
	Node *temp = head;
	int count = 0;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	if(count == 1 || count == k)
		return head;
		
	Node *ptr = head;
	int cnt = 1;
	int t = k;
	if(k>count)
		t = k%count;
	while(cnt < count-t){
		cnt++;
		ptr = ptr->next;
	}
	Node* curr = ptr->next;
	ptr->next = NULL;
	Node * q = curr;
	while(q->next != NULL){
		q = q->next;
	}
	q->next = head;
	return curr;
}
