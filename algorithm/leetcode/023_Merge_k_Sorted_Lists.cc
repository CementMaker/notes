/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
#include <iostream>
#include <vector>
#include <queue>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* left, ListNode* right) { return left->val > right->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);

        for (auto node: lists) {
            if (node != nullptr) {
                q.push(node);
            }
        }

        ListNode* res_head = nullptr;
        ListNode* pre = nullptr;
        while (!q.empty()) {
            if (res_head == nullptr) {
                res_head = q.top();
                pre = res_head;
            } else {
                pre->next = q.top();
                pre = pre->next;
            }
            q.pop();
            if (pre->next != nullptr) {
                q.push(pre->next);
            }
        }
        return res_head;
    }
};

#ifdef LOCAL
int main(int argc, const char* argv[]) {
    return 0;
}
#endif
