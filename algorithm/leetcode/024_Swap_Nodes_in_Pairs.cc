/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space.
You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* res_head = head->next;
        ListNode* pre = head;

        ListNode* t = res_head->next;
        res_head->next = pre;
        pre->next = t;
        while (pre->next != nullptr && pre->next->next != nullptr) {
            t = pre->next->next->next;
            pre->next->next->next = pre->next;
            pre->next = pre->next->next;
            pre->next->next->next = t;
            pre = pre->next->next;
        }
        return res_head;
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
    for (ListNode* p = sol.swapPairs(head); p != nullptr; p = p->next) {
        cout << p->val << endl;
    }
    return 0;
}
#endif
