/**相交表总体思想（（x+z)+y == (y+z)+x）
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL) return NULL;
    struct ListNode *NodeA = headA, *NodeB = headB;
    while(NodeA != NodeB){
        NodeA = NodeA == NULL ? headB : NodeA->next;
        NodeB = NodeB == NULL ? headA : NodeB->next;
    }
    return NodeA;
}