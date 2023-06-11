
// ### Approach1: Using slow and fast pointer

// - if the list has a cycle then at some point both slow and fast pointer will point to the same node.
// - create two pointer slow and fast, slow will move 1 node and fast will move 2 nodes.
// - run a while loop until fast→next and fast→next→next is not equal to null
//     - move slow by 1 node
//     - move fast by 2 nodes
//     - if both are equal(points to same node)   —> return true
    
//     return false
    

// - Time complexity : O(N)
// - space complexity : O(1)

// ### Approach2: Using hashmap

// - create a hashmap to keep count of nodes
// - run a while loop on list
//     - if count of current node is already 1 in map, return true
// - it has space complexity of O(N )

// - Time complexity : O(N)
// - space complexity : O(N)
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

bool detectCycle(Node *head)
{
	//	Write your code here

    if(head->next == NULL || head == NULL)
		return false;
	Node * fast = head, *slow = head;

	while(fast->next != NULL && fast->next->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			return true;
		
	}
	return false;


	// unordered_map<Node*, int>m;
	// while(head != NULL){
	// 	if(m[head] == 1)
	// 		return true;
	// 	m[head]++;
	// 	head= head->next;
	// }
	// return false;
}
