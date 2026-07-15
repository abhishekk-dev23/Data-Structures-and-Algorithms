/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* temp = head;
        vector<int> arr;

        while(temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        ListNode* hd = new ListNode(arr[0]);
        ListNode* t = hd;
        for(int i=1; i<arr.size(); i++) {
            ListNode* node = new ListNode(arr[i]);
            t->next = node;
            t = t->next;
        }
        return hd;
    }
};