// Link :- https://leetcode.com/problems/next-greater-element-iii/description/


// code :- 


class Solution {
public:
    int nextGreaterElement(int n) {
              
        int temp=n;
        int digits=0;
        // find number of digits
        while(temp!=0)
        {
            temp=temp/10;
            digits++;
        }
        if(digits<=1) return -1;
        // make an array to push digits 
        vector<int> num(digits,-1);
        
        // push digits
        temp=n;
        for(int i=digits-1;i>=0;i--)
        {
            num[i]=temp%10;
            temp/=10;
        }
        // get point where sequence break
        int pre=-1;
        int point;
        for(int i=digits-1;i>=0;i--)
        {
            point=i;
            if(num[i]<pre)
            {
                break;
            }
            if(i==0)
            {
                return -1;
            }
            pre=num[i];
        }
        cout << point;
        temp=num[point];
        // point se lekr last tak check kro ki is se bda element konsa h .. use temp m store krva lenge
        int index;
        for(int i=digits-1;i>point;i--)
        {
            if(num[i]>num[point])
            {
                index=i;
                while(num[i]==num[i-1] && i>point)
                {
                    index--;
                    i--;
                }
                break;
            }
        }
        cout << " " << index << " ";
        // swap kro num[point],num[index]
        swap(num[point],num[index]);
        // sort remaining array
        sort(num.begin()+point+1 , num.end());
        // lets create a number back
        long int ans=0;
        for(int i=0;i<num.size();i++)
        {
            ans=(ans*10)+num[i];
        }
        int a = ans;
        if(ans>INT_MAX)
        return -1;
        cout << ans;
        return ans;
    }
};
