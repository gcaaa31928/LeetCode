
#include <afxres.h>
#include <climits>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *newHead = new ListNode(INT_MIN);
        ListNode *current = head;
        while(current!=NULL) {
            ListNode *next = current->next;
            ListNode *pivot = newHead;
            while(pivot->next!=NULL) {
                if (pivot->next->val > current->val)
                    break;
                pivot=pivot->next;
            }
            current->next=pivot->next;
            pivot->next =current;
            current=next;
        }
        return newHead->next;
    }
};