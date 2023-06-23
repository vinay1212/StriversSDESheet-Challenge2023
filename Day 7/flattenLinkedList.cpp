/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
#include <bits/stdc++.h>
Node* flattenLinkedList(Node* head) 
{
	// Write your code here

	vector<Node*> v;
	Node *ptr = head;
	int count = 1;
	while(ptr != NULL){
		v.push_back(ptr);
		ptr = ptr->next;
		count++;
	}
	vector<int> vec;
	for(int i = 1; i < count; i++){
		Node*temp = v[i-1];
		while(temp != NULL){
			vec.push_back(temp->data);
			temp = temp->child;
		}
	}
	sort(vec.begin(), vec.end());
	Node* ans = new Node(vec[0]);
	Node* q = ans;
	for(int i = 1; i < vec.size(); i++){
		int t = vec[i];
		Node *r = new Node(t);
		q->child = r;
		q = q->child;
	}
	return ans;
}
