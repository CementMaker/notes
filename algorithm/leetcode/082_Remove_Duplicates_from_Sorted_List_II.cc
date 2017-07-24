/*
Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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

        ListNode* res = nullptr;
        ListNode* last = nullptr;

        auto start = head;
        ListNode *todel = nullptr;
        while (start != nullptr) {
            if (start->next != nullptr && start->val == start->next->val) {
                while (start->next != nullptr && start->val == start->next->val) {
                    todel = start->next;
                    start->next = start->next->next;
                    delete todel;
                }
                todel = start;
                start = start->next;
                delete todel;
            } else {
                if (last == nullptr) {
                    res = start;
                } else {
                    last->next = start;
                }
                last = start;
                start = start->next;
                last->next = nullptr;
            }
        }
        return res;
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
