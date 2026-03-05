/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//使用数组覆盖链表内容再操作，空间复杂度O(n)
bool isPalindrome(struct ListNode* head) {
    int vals[100001], vals_num = 0;
    while (head != null) {
        vals[vals_num] = head->val;
        head = head->next;
    }
    for(int i = 0, j = vals_num - 1; i < j; ++i, --j) {
        if(vals[i] != vals[j]) return false;
    }
    return true;
}

//使用反转链表操作，空间复杂度O(1)
struct ListNode* reverseList(struct ListNode* head) { // 反转链表
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

//用快慢指针找到中间节点
struct ListNode* endOfFirstHalf(struct ListNode *head) {
    struct ListNode *fast = head, *slow = head;
    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

bool isPalindrome(struct ListNode* head) {
    if(head == NULL) return true;
    
    struct ListNode* firstHalfEnd = endOfFirstHalf(head);
    struct ListNode* secondHalfStart = reverseList(firstHalfEnd->next);

    struct ListNode *p1 = head;
    struct ListNode *p2 = secondHalfStart
    bool result = true;
    while (result && p2 !=NULL) {
        if (p1->val != p2->val) result = false;
        p1 = p1->next;
        p2 = p2->next;
    }
    firstHalfEnd->next = reverseList(secondHalfStart);
    return result;
}