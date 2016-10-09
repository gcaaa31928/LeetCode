
#include <afxres.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode **current = &head;
        while (*current) {
            if ((*current)->next && (*current)->val == (*current)->next->val) {
                ListNode *tmp = (*current);
                while (tmp && tmp->next && tmp->val == tmp->next->val) {
                    tmp=tmp->next;
                }
                *current = tmp->next;
            } else if ((*current) != NULL)
                current = &((*current)->next);
        }
        return head;
    }
};