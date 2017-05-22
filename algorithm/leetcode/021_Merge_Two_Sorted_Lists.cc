/*
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.
*/
#include <iostream>

#ifdef LOCAL
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* res_head = nullptr;
        if (l1->val < l2->val) {
            res_head = l1;
            l1 = l1->next;
        } else {
            res_head = l2;
            l2 = l2->next;
        }
 
        ListNode* pre = res_head;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                pre->next = l2;
                break;
            } else if (l2 == nullptr) {
                pre->next = l1;
                break;
            } else if (l1->val < l2->val) {
                pre->next = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        return res_head;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {

    return 0;
}
#endif
