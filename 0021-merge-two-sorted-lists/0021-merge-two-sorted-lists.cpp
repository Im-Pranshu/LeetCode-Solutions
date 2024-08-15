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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // dummy node to make the mergin process easier
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;// tail of dummy

        ListNode* l1 = list1;// pointer of list1 for merging
        ListNode* l2 = list2;// pointer of list2 for merging

        // jb tak koi ek list ka pointer null na ho jae dummy list me value add krte raho
        while(l1 && l2){
            // choti value ko pehle add karo
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;// next value pe jao
            }
            else{
                tail->next = l2;
                l2 = l2->next;// next value pe jao
            }
            tail = tail->next;
        }

        // last me dono me se jis bhi list me elements bache ho wo tail ke last me jod me
        tail->next = l1 ? l1 : l2;

        // store original merged sorted list
        ListNode* ans = dummy->next;
        // delete dummy node now to avoid segment faults and memory leaks
        delete dummy;
        // return the merged sorted list
        return ans;

    }
};