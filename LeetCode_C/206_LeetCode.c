/**反转链表
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *cru = head;
    struct ListNode *pre = NULL;
    while(cru != NULL){
        struct ListNode *next = cru->next;
        cru->next = pre;
        pre = cru;
        cru = next;
    }
    return pre;
}