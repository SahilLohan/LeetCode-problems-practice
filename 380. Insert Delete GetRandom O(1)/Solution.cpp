// Link : https://leetcode.com/problems/insert-delete-getrandom-o1/


// Code : 
class RandomizedSet {
unordered_map<int,int> mp;
int limit;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
        return false;
        else{
            mp[val]=1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())
        return false;
        else{
            mp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int num = rand()%mp.size();
        auto itr = mp.begin();

        for(int i=0;i<num;i++)
        {
            itr++;
        }

        return itr->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
