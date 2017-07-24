/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* todel = nullptr;
        auto last = head;
        while (last->next != nullptr) {
            if (last->val == last->next->val) {
                todel = last->next;
                last->next = last->next->next;
                delete todel;
            } else {
                last = last->next;
            }
        }
        return head;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next->next = new ListNode(5);

    for (auto p = head; p != nullptr; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;

    Solution().deleteDuplicates(head);

    for (auto p = head; p != nullptr; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;

    return 0;
}
#endif
