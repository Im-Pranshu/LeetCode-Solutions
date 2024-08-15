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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case
        if(head == nullptr) return head;

        // Step 1: check if nodes are forming group of k nodes 
        ListNode* curr = head;
        int cnt = 0;
        while(curr != nullptr && cnt < k){
            curr = curr -> next;
            cnt++;
        }

        // check if group is formed or not else return original list
        if(cnt != k) return head;

        // Step 2: Reverse the list of k nodes i.e group of k is formed.
        cnt = 0;
        curr = head;
        ListNode* back = nullptr;
        ListNode* fwd = nullptr;
        while(curr != nullptr && cnt < k){
            fwd = curr -> next;
            curr -> next = back;
            back = curr;
            curr = fwd;
            cnt++;
        }

        // Step 3: Baki recursion dekhlega reversing.
        if(fwd != nullptr)
            head -> next = reverseKGroup(fwd,k);

        // Step 4: reversed list ka head return kardo.
        return back;
    }
};