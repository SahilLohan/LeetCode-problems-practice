// Link :- https://leetcode.com/problems/first-bad-version/description/?envType=study-plan&id=algorithm-i


// Code :-

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1) return 1;


        long long int l=1;
        long long int h=n;
        long long int mid=n/2;
        int count=1;
        while(l<=h){
            cout << count++ << endl;
            mid=(l+h)/2;
            cout << l << " " << h << " " << mid << endl;
            if(isBadVersion(mid)){
                cout << "I am here\n";
                if(l==h)
                return int(l);
                else
                h=mid;
            }
            else
            {
                cout << mid <<"is not a bad version\n"; 
                l=mid+1;
            }
        }

        return -1;
    }
};
