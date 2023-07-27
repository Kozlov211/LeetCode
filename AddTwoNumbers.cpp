class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool transfer = false;
        ListNode* result = new ListNode();
        ListNode* node = result;
        ListNode* prev = result;
        while(l1 && l2) {
            int val = l1->val + l2->val;
            if (transfer) {
                ++val;
                transfer = false;
            }
            if (val > 9) {
                val -= 10;
                transfer = true;
            }
            node->val = val;
            node->next = new ListNode();
            prev = node;
            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int val = l1->val;
            if (transfer) {
                ++val;
                transfer = false;
            }
            if (val > 9) {
                val -= 10;
                transfer = true;
            }
            node->val = val;
            node->next = new ListNode();
            prev = node;
            node = node->next;
            l1 = l1->next;
        }
        while (l2) {
            int val = l2->val;
            if (transfer) {
                ++val;
                transfer = false;
            }
            if (val > 9) {
                val -= 10;
                transfer = true;
            }
            node->val = val;
            node->next = new ListNode();
            prev = node;
            node = node->next;
            l2 = l2->next;
        }
        if (transfer) {
            node->val = 1;
        }
        if (node->val == 0) {
            prev->next = nullptr;
        }
        return result;
    }
};

void Tests() {
    Solution solution;
    {
        ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
        ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
        ListNode* result = solution.addTwoNumbers(l1, l2);
        assert(result->val == 7);
        result = result->next;
        assert(result->val == 0);
        result = result->next;
        assert(result->val == 8);
        result = result->next;
        assert(result == nullptr);
    }
    {
        ListNode* l1 = new ListNode(0);
        ListNode* l2 = new ListNode(0);
        ListNode* result = solution.addTwoNumbers(l1, l2);
        assert(result->val == 0);
        result = result->next;
        assert(result == nullptr);
    }
    {
        ListNode* l1 = new ListNode(9, new ListNode(9, new ListNode(9)));
        ListNode* l2 = new ListNode(1, new ListNode(1, new ListNode(1)));
        ListNode* result = solution.addTwoNumbers(l1, l2);
        assert(result->val == 0);
        result = result->next;
        assert(result->val == 1);
        result = result->next;
        assert(result->val == 1);
        result = result->next;
        assert(result->val == 1);
    }
    {
        ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3)));
        ListNode* l2 = new ListNode(5);
        ListNode* result = solution.addTwoNumbers(l1, l2);
        assert(result->val == 6);
        result = result->next;
        assert(result->val == 2);
        result = result->next;
        assert(result->val == 3);
        result = result->next;
        assert(result == nullptr);
    }
    {
        ListNode* l1 = new ListNode(9);
        ListNode* l2 = new ListNode(5);
        ListNode* result = solution.addTwoNumbers(l1, l2);
        assert(result->val == 4);
        result = result->next;
        assert(result->val == 1);
        result = result->next;
        assert(result == nullptr);
    }

    cout << "Tests passed" << endl;
}
