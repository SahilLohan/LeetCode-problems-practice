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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr=head;
        vector<int>arr;
        stack<int>st;
        vector<int>ans(arr.size(),0);

       //coping the linklist into an array
        while(curr){
            arr.push_back(curr->val);
            curr=curr->next;
        }

        //now using monotonic stack apply operations on aaray
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans.push_back(st.top());
            }else {
                ans.push_back(0);
            }
        st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
