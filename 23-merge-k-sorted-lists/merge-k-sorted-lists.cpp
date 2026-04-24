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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        vector<int>res;
        for(int i=0; i<n; i++){
            ListNode* temp= lists[i];
            while(temp!=nullptr){
                res.push_back(temp->val);
                temp=temp->next;
            }
        }
        sort(res.begin(), res.end());
        ListNode* dummy= new ListNode(-1);
        ListNode* tail= dummy;
        for(int v: res){
            tail->next= new ListNode(v);
            tail=tail->next;
        }
        return dummy->next;
    }
};