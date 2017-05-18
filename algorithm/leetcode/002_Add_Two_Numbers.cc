/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <iostream>

using namespace std;

#ifdef LOCAL
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#endif // LOCAL

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* cur = nullptr;

        int digit = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) {
                digit += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                digit += l2->val;
                l2 = l2->next;
            }

            if (result == nullptr) {
                result = new(std::nothrow) ListNode(digit % 10);
                cur = result;
            } else {
                cur->next = new(std::nothrow) ListNode(digit % 10);
                cur = cur->next;
            }
            digit /= 10;
        }
        if (digit > 0) {
            cur->next = new(std::nothrow) ListNode(digit);
        }
        return result;
    }
};

#ifdef LOCAL
void print_list(ListNode* head) {
    if (head == nullptr) {
        return;
    }

    for (ListNode* p = head; p != nullptr; p = p->next) {
        cout << (p == head ? "" : " -> ") << p->val;
    }
    cout << endl;
}

int main(int argc, const char* argv[]) {
    ListNode* l1 = new(std::nothrow) ListNode(2);
    l1->next = new(std::nothrow) ListNode(4);
    l1->next->next = new(std::nothrow) ListNode(3);

    ListNode* l2 = new(std::nothrow) ListNode(5);
    l2->next = new(std::nothrow) ListNode(6);
    l2->next->next = new(std::nothrow) ListNode(4);

    print_list(l1);
    print_list(l2);

    Solution sol;
    print_list(sol.addTwoNumbers(l1, l2));
    return 0;
}
#endif
