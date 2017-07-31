/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

#include <iostream>

using namespace std;

#ifdef LOCAL
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* res = nullptr;
        ListNode* left = nullptr;
        ListNode* right_begin = nullptr;
        ListNode* right_end = nullptr;

        while (head != nullptr) {
            if (head->val < x) {
                if (res == nullptr) {
                    res = head;
                    left = head;
                } else {
                    left->next = head;
                    left = left->next;
                }
                head = head->next;
                left->next = nullptr;

            } else {
                if (right_begin == nullptr) {
                    right_begin = head;
                    right_end = head;
                } else {
                    right_end->next = head;
                    right_end = right_end->next;
                }
                head = head->next;
                right_end->next = nullptr;
            }
        }
        if (left != nullptr) left->next = right_begin;
        else res = right_begin;
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    for (auto p = head; p != nullptr; p = p->next) cout << p->val << " "; cout << endl;

    Solution().partition(head, 3);
    for (auto p = head; p != nullptr; p = p->next) cout << p->val << " "; cout << endl;

    for (auto p = Solution().partition(head, 3); p != nullptr; p = p->next) cout << p->val << " ";
    cout << endl;

    return 0;
}
#endif
