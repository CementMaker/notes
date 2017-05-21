/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,
    Given linked list: 1->2->3->4->5, and n = 2.
    After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;

        ListNode* npre = nullptr;
        for (ListNode* p = head; p != nullptr; p = p->next) {
            if (npre == nullptr) {
                if (n-- == 0) npre = head;
            } else {
                npre = npre->next;
            }
        }

        if (npre != nullptr) {
            ListNode* del = npre->next;
            npre->next = npre->next->next;
            delete del;
            return head;
        } else if (n == 0) {
            ListNode* new_head = head->next;
            delete head;
            return new_head;
        }
        return head;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    ListNode* head = new(std::nothrow) ListNode(1);
    head->next = new(std::nothrow) ListNode(2);
    head->next->next = new(std::nothrow) ListNode(3);
    head->next->next->next = new(std::nothrow) ListNode(4);
    head->next->next->next->next = new(std::nothrow) ListNode(5);

    Solution sol;
    for (ListNode* p = sol.removeNthFromEnd(head, 5); p != nullptr; p = p->next) {
        cout << p->val << endl;
    }
}
#endif
