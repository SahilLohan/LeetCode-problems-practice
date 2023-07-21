// Link :https://leetcode.com/problems/trapping-rain-water/


// Code :
class Solution {
public:
    int trap(vector<int>& h) {
        // for every height we find left max height and right max height
        int ans=0;
        vector<int> leftMax(h.size(),0);
        vector<int> rightMax(h.size(),0);
        
        int max=-1;
        for(int i=0;i<h.size();i++)
        {
            if(h[i] > max)
            {
                max = h[i];
                leftMax[i] = -1;
            }
            else
            {
                leftMax[i] = max;
            }
        }

        max = -1;
        for(int i=h.size()-1;i>=0;i--)
        {
            if(h[i] > max)
            {
                max = h[i];
                rightMax[i] = -1;
            }
            else
            {
                rightMax[i] = max;
            }
        }

        for(int i=0;i<h.size();i++)
        {
            if(leftMax[i]!=-1 && rightMax[i] !=-1)
            {
                cout << "added : " << min(leftMax[i],rightMax[i]) - h[i] << " at : " << i << endl;
                ans += (min(leftMax[i],rightMax[i]) - h[i]);
            }
        }
        return ans;
    }
};
