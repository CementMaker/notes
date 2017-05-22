/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes in the end should
remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
    Given this linked list: 1->2->3->4->5
    For k = 2, you should return: 2->1->4->3->5
    For k = 3, you should return: 3->2->1->4->5
*/
#include <iostream>

#ifdef LOCAL
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#endif

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr|| k == 1) return head;

        ListNode* ktail = nullptr;
        ListNode* khead = nullptr;

        ListNode* tail = nullptr;
        ListNode* ans = nullptr;
        ListNode* pre = nullptr;
        ListNode* next = nullptr;

        while (true) {
            khead = tail == nullptr ? head : tail->next;
            ktail = khead;
            for (int i = 1; i < k; ++i) {
                if (ktail == nullptr) break;
                ktail = ktail->next;
            }
            if (ktail == nullptr) break;

            pre = khead;
            for (ListNode *node = khead->next; node != ktail; ) {
                next = node->next;
                node->next = pre;
                pre = node;
                node = next;
            }

            khead->next = ktail->next;
            ktail->next = pre;

            if (ans == nullptr) {
                ans = ktail;
            } else {
                tail->next = ktail;
            }
            tail = khead;
        }
        return ans == nullptr ? head : ans;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {

    return 0;
}
#endif
