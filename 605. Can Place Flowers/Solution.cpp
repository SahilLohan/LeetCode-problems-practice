// Link : https://leetcode.com/problems/can-place-flowers/description/


// Code : 
class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int count = 0;
        for(int i=0;i<fb.size();i++)
        {
            cout << "i : " << i ;
            if(fb[i]==0)
            {
                if(i>0 && i<fb.size()-1 )
                {
                    if(fb[i-1]==0 && fb[i+1]==0) 
                    {
                        count++;
                        i++;
                    }
                }
                else if(i<=0 && i<fb.size()-1)
                {
                    if(fb[i+1]==0) {count++;
                    i++;}
                }
                else if(i<=fb.size()-1 && i!=0)
                {
                    if(fb[i-1]==0) 
                    {
count++;
                    i++;
                    }
                }
                else if(i==0 && i==fb.size()-1)
                {
                    count++;
                }
            }
            cout <<" count : " <<  count << endl;
        }
        cout << count << endl;
        return count>=n;
    }
};
