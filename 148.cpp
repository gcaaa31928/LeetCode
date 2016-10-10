#include <afxres.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

#include <cstdio>
#include <algorithm>

using namespace std;

class Solution {
public:

    int count(ListNode *head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode *sortList(ListNode *head) {
        if (head == NULL)return head;
        else if (head->next == NULL)return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *slow = &dummy, *fast = &dummy;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rightStart = slow->next;
        slow->next = NULL;
        ListNode *l1 = sortList(dummy.next);
        ListNode *l2 = sortList(rightStart);
        return mergedList(l1, l2);
    }

    ListNode *mergedList(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *current = &dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val > l2->val) {
                current->next = l2;
                l2 = l2->next;
            } else {
                current->next = l1;
                l1 = l1->next;
            }
            current = current->next;
        }
        if (l1 == NULL)current->next = l2;
        if (l2 == NULL)current->next = l1;
        return dummy.next;
    }

    ListNode *sortList2(ListNode *head) {
        int len = count(head);
        for (int seg = 1; seg < len; seg <<= 1) {
            ListNode *last = NULL;
            for (int start = 0; start < len; start += (seg << 1)) {
                int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
                ListNode *start1, *start2;
                ListNode *newHead, *currentRoot;
                if (start == 0) {
                    start1 = head;
                    newHead = new ListNode(0);
                } else {
                    start1 = last->next;
                    newHead = last;
                }
                currentRoot = newHead;
                start2 = start1;
                for (int i = low; i < mid; i++) {
                    start2 = start2->next;
                }
                ListNode *lastHead = start2;
                for (int i = mid; i < high; i++) {
                    lastHead = lastHead->next;
                }
                int i = low, j = mid;
                for (; i < mid && j < high;) {
                    if (start1->val < start2->val) {
                        newHead->next = start1;
                        start1 = start1->next;
                        i++;
                    } else {
                        newHead->next = start2;
                        start2 = start2->next;
                        j++;
                    }
                    newHead = newHead->next;
                }
                for (; i < mid; i++) {
                    newHead->next = start1;
                    start1 = start1->next;
                    newHead = newHead->next;
                }
                for (; j < high; j++) {
                    newHead->next = start2;
                    start2 = start2->next;
                    newHead = newHead->next;
                }
                last = newHead;
                newHead->next = lastHead;
                if (start == 0) {
                    head = currentRoot->next;
                }
            }

        }
        return head;
    }


};

int main() {
    Solution solution;
    ListNode *head = new ListNode(4);
    ListNode *root = head;
    head->next = new ListNode(3);
    head = head->next;
    head->next = new ListNode(3);
    head = head->next;
    head->next = new ListNode(5);
    head = solution.sortList(root);
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
}