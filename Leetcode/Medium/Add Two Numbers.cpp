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
 using ll = long long;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-1);
        ListNode* cursor1 = l1;
        ListNode* cursor2 = l2;
        ListNode* cursor3 = result;
        int carry = 0;
        int sum = 0;
        while(cursor1 != nullptr || cursor2 != nullptr || carry) {
            sum = 0;
            if(cursor1 != nullptr){
                sum += cursor1->val;
            }
            if(cursor2 != nullptr){
                sum += cursor2->val;
            }

            sum += carry;
            carry = 0;
            if(sum >= 10){
                carry = 1;
                sum -= 10;
            }

            ListNode* newNode = new ListNode(sum);
            if(cursor3->val == -1) {
                result = newNode;
                cursor3 = newNode;
            }                
            else {
                cursor3->next = newNode;
                cursor3 = cursor3->next;
            }

            if(cursor1 != nullptr) cursor1 = cursor1->next;
            if(cursor2 != nullptr) cursor2 = cursor2->next;
        }

        return result;
    }
};