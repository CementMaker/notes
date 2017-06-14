/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;

        int length = 0;
        for (auto p = head; p != nullptr; p = p->next) ++length;
        k %= length;
        if (k == 0) return head;

        ListNode* pright = head;
        ListNode *pleft = head;
        while (pright->next != nullptr) {
            pright = pright->next;
            if (k <= 0) {
                pleft = pleft->next;
            } else {
                --k;
            }
        }

        pright->next = head;
        auto res = pleft->next;
        pleft->next = nullptr;
        return res;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    auto res = Solution().rotateRight(head, 4);

    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
#endif
