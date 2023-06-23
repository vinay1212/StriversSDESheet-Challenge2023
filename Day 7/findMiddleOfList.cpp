// ### Appeoach1:

// - Firstly we will need to find total no. of nodes present in the linked list
// - run a while loop & count total nodes
// - now we know the total nodes we can find the node which is at middle by running on more while loop

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

Node *findMiddle(Node *head) {
    // Write your code here

    Node *ptr = head;
    int count = 0;
    while(ptr != NULL){
        count++;
        ptr = ptr->next;
    }

    count = count/2;
    int i = 0;
    while(i < count){
        head = head->next;
        i++;
    }
    return head;
}

