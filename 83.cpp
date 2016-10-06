
#include <afxres.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *current = head, *pivot=NULL;
        while(current && current->next) {
            if (current->val == current->next->val) {
                ListNode *tmp = current->next;
                current->next = current->next->next;
                delete tmp;
            }else
                current = current->next;
        }
        return head;
    }
};