/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //差错控制
        if (n <= 0) //保证 n 为一个正数
            return nullptr;
        if (head == nullptr)
            return nullptr;
        
        //找出链表的长度
        int length = 0;
        ListNode* pNode = head;
        while (pNode != nullptr) {
            length++;
            pNode = pNode->next;    //时刻谨记循环的结束条件
        }
        //如果 n > 链表长度
        if (length < n)
            return nullptr;
        
        if (length == n) {
            pNode = head->next;
            delete head;
            return pNode;
        }
        
        ListNode* pNext = head;
        while (n-- > 0) {
            pNext = pNext->next;
        }
        
        //在变量使用之前记得初始化
        pNode = head;
        while (pNext->next != nullptr) {
            pNode = pNode->next;
            pNext = pNext->next;
        }
        
        //如果删除的不是头部，那么 pNode 应该是应删除元素的前一个节点
        ListNode* tmp = pNode->next;
        pNode->next = pNode->next->next;
        delete tmp;
        
        return head;
    }
};