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
        //������
        if (n <= 0) //��֤ n Ϊһ������
            return nullptr;
        if (head == nullptr)
            return nullptr;
        
        //�ҳ�����ĳ���
        int length = 0;
        ListNode* pNode = head;
        while (pNode != nullptr) {
            length++;
            pNode = pNode->next;    //ʱ�̽���ѭ���Ľ�������
        }
        //��� n > ������
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
        
        //�ڱ���ʹ��֮ǰ�ǵó�ʼ��
        pNode = head;
        while (pNext->next != nullptr) {
            pNode = pNode->next;
            pNext = pNext->next;
        }
        
        //���ɾ���Ĳ���ͷ������ô pNode Ӧ����Ӧɾ��Ԫ�ص�ǰһ���ڵ�
        ListNode* tmp = pNode->next;
        pNode->next = pNode->next->next;
        delete tmp;
        
        return head;
    }
};