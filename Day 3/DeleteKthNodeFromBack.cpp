// ### Approach1:

// - Basically count the total number of nodes in the list, and then find the node which is at Kth position from last.
// - here some corner cases are imp,
    
//     if K = 0 —>return given linked list as it is.
    
//     if count = 0 —>list is empty, return head as it.
    
// - find the Kth node from the back, Kth node from back is next node of (count-K)th node from front.
    
//     1—>2—>3—>4—>5          2nd node from back   
    
//     count = 5    (5-2) = 3        the next node of 3rd node is the target
    
// - we have to change (count-K) the nodes next address.
// - traverse the given list till count-K, then change the address of next element to address of next of next.
// - this way it will jump to second element directly.

// - Time complexity : O(N)



/*
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
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.

    Node* ptr = head;
    int count = 0;
    
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }
    if(K == 0 || count == 0){
        return head;
    }
   
    if(count == K){
        head = head->next;
        return head;
    }

    Node* temp = head;

    int t = count - K, cnt = 1;

    while(cnt < t){
        cnt++;
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;

   
    // LinkedListNode<int>* ptr = new LinkedListNode(0);
    // ptr->next = head;
    // LinkedListNode<int>* slow = ptr; 
    // LinkedListNode<int>*fast = ptr;
    // for(int i = 0; i < K; i++){
    //     fast = fast->next;
    // }

    // if(fast == NULL){
    //     head = head->next;
    //     return head;
    // }
    // while(fast->next != NULL){
    //     fast = fast->next;
    //     slow = slow->next;
    // }
    // slow->next = slow->next->next;

    // return head;
}
