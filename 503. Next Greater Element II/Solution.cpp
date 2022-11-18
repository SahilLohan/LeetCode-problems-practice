// Link :- https://leetcode.com/problems/next-greater-element-ii/description/


// code :-


class Solution {
public:
    vector<int> nextGreaterElements(vector<int> nums) {
        vector<int> ans(nums.size(),-1);

        // make a stack .. We will use it as decreasing monotonic stack .. 
        // Note:-  store the index of elements instead of elements
        stack<int> s;

        // use a for loop for 2n iterations
        int index;
        for(int i=0;i<2*nums.size();i++)
        {
            // agr i ki value array se bahar ho gai to usko tackle krne k liye modulo ka use kr lenge
            index=i%nums.size();

            // agr stack khali nhi h + vo element dalne se montonicity break hoti h ... Then pop until it don't satisfies
            while(!s.empty() && nums[index]>nums[s.top()])
            {
                ans[s.top()]=nums[index];
                s.pop();
            }
            s.push(index);
        }

        return ans;
    }
};
