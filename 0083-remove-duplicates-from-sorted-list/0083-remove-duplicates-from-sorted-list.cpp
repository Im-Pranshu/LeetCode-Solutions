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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* prev = head;
        ListNode* curr = head->next;;

        while(curr != nullptr){
            if(prev->val == curr->val){// equal hai to pointer age badha do or duplicate node ko delete krdo
                
                ListNode* delNode = curr;// is node ko delete krna duplicate hai to store krlo
                prev->next = curr->next;// delete hone wali node ke phle wale node ko uske bad wali node se jod do
                curr = curr->next;// curr ko delete hone wali node ke next se jod do

                // Deleting duplicate node
                delNode->next = nullptr;// delete wali node ka next null kardo
                delete delNode;// delete the node.
            }
            else{// equal nahi hai to age badho
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};