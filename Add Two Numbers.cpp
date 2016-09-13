
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int plus = 0, remainder = 0;
        ListNode* prev = NULL,* root = NULL;
        while(l1 || l2) {
            int l1val = (l1) ? l1->val : 0;
            int l2val = (l2) ? l2->val : 0;
            int tmp = l1val + l2val + plus;
            plus = tmp / 10;
            remainder = tmp % 10;
            ListNode* digit = new ListNode(remainder);
            if (prev) {
                prev->next = digit;
            }
            if (root==NULL)
                root = digit;
            prev=digit;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (plus) {
            prev->next = new ListNode(plus);
        }
        return root;
    }
};