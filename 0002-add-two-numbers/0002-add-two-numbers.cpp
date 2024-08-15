/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    // Helper function to insert a new node with value 'val' at the tail of the list
    void insertAtTail(ListNode* &head, ListNode* &tail, int val) {
        // Create a new node with the given value
        ListNode* temp = new ListNode(val);
        
        // If the list is empty, set both head and tail to the new node
        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            // Otherwise, append the new node to the end of the list and update the tail
            tail->next = temp;
            tail = temp;
        }
    }

    // Function to add two linked lists representing numbers
    ListNode* add(ListNode* a, ListNode* b) {
        // If one of the lists is null, return the other list
        if (a == nullptr) return b;
        if (b == nullptr) return a;

        int carry = 0; // Variable to store carry value for each digit addition
        ListNode* ansHead = nullptr; // Head of the resulting linked list
        ListNode* ansTail = nullptr; // Tail of the resulting linked list

        // Iterate while either list is not empty or there is a carry to process
        while (a || b || carry) {
            int val1 = 0;  // Value of the current node in list 'a'
            if (a)
                val1 = a->val;

            int val2 = 0;  // Value of the current node in list 'b'
            if (b)
                val2 = b->val;

            // Calculate the sum of the two digits and the carry
            int sum = val1 + val2 + carry;

            // Determine the digit to store in the current node and update the carry
            int digit = sum % 10;
            carry = sum / 10;

            // Insert the digit at the end of the result list
            insertAtTail(ansHead, ansTail, digit);

            // Move to the next nodes in the input lists
            if (a)
                a = a->next;
            if (b)
                b = b->next;
        }

        // Return the head of the resulting linked list
        return ansHead;
    }
public:
    // Public method to add two numbers represented by linked lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2);  // Call the private helper function to perform the addition
    }
};