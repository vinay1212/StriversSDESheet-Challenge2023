// ### Approach1:

// - we will add digits stored at both nodes, & store it new node, till the both lists end.
// - run a while loop until until both the lists are not empty and carry is not zero
//     - if list1 has node, add to sum, if list2 has node, add to sum, then add carry to the sum.
//     - then calculate the new value of carry & update it.
//     - create new node, changes its data value to sum, (unit place digit of sum)
//     - add the given node to the end of the ans list.
// - return the head pointer of ans list.



/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.

    Node * head = new Node(-1);
    Node *ptr = head;
    int carry = 0;
    while(num1 != NULL || num2 != NULL || carry != 0){
        int sum = 0;
        if(num1 != NULL){
            sum += num1->data;
            num1 = num1->next;
        }
        if(num2 != NULL){
            sum += num2->data;
            num2 = num2->next;
        }
        sum += carry;
        carry = sum/10;
        Node *temp = new Node(-1);
        temp->data = (sum%10);
        ptr->next = temp;
        ptr = ptr->next;

    }

    head = head->next;
    return head;
}
