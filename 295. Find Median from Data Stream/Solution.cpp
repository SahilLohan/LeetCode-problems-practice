// Link : https://leetcode.com/problems/find-median-from-data-stream/


// Code : 

class MedianFinder {
public:
    multiset<int> st;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        st.insert(num);
    }
    
    double findMedian() {
        int n = st.size();
        auto itr = st.begin();
        // cout << "The elements are : (size = " << n <<")\n";
        if(n%2==0)
        {
            double ans=0;
            int i=0;
            for(auto itr=st.begin();itr!=st.end();itr++,i++)
            {
                // cout << i << " : " << *itr << endl;
                if(i==(n/2 -1 ))
                {
                    ans+= *itr;
                    itr++;
                    ans+= *itr;
                    return ans/2;
                }
            }
        }
        else
        {
            double ans=0;
            int i=0;
            for(auto itr=st.begin();itr!=st.end();itr++,i++)
            {
                // cout << i << " : " << *itr << endl;
                if(i==(n/2))
                {
                    return *itr;
                }
            }
        }
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<pair<int,int>, null_type, 
//         less<pair<int,int>>, rb_tree_tag,
//         tree_order_statistics_node_update>
//         ordered_set_pair;
  
// class MedianFinder {
// public:
//     ordered_set_pair st;
//     int a=0;
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
//         //insert pair to store duplicate value in Ordered Set
//         st.insert({num,a++});
//     }
   
//     double findMedian() { 
//         int n=st.size();
//         auto itr = st.find_by_order(n/2); 
//         double num= (*itr).first;
//         if(n%2==0){
//             auto itr2=st.find_by_order((n-1)/2);
//             double num1=(*itr2).first;
//             num=(num+num1)/2;
//         }
//         return num;
        
//     }
// };
