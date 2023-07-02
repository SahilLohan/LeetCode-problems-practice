// Link : https://leetcode.com/problems/lru-cache/


/***************************************************
*************** Time limit Exceeded ****************
***************************************************/


class LRUCache {
    map<int,int> mp;
    int capacity;
    list<int> elements;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        // cout << "get the key -> " << key << endl;
        if(mp.find(key)!=mp.end())
        {
            // cout << "key found" << endl;
            elements.remove(key);
            elements.push_back(key);
            // auto i = elements.begin();
            // cout <<  "Least recently used key is : " << *i << endl;
            return mp[key];
        }
        else
        {
            // cout << "Key not found" << endl;
            // auto i = elements.begin();
            // cout <<  "Least recently used key is : " << *i << endl;
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        // cout << "Put the key,value : " << key << " , " << value << endl;
        if(mp.find(key)==mp.end() && mp.size()==capacity)
        {
            auto i = elements.begin();
            // cout <<  "Least recently used key was : " << *i << endl;
            mp.erase(*i);
            elements.remove(*i);
            mp[key]=value;
            elements.push_back(key);
            // if(elements.size()!=0)
            // {
            //     i = elements.begin();
            //     cout << "Now , Least recently used key is : " << *i << endl;
            // }
            
        }
        else if(mp.find(key)==mp.end())
        {
            mp[key]=value;
            elements.push_back(key);
        }
        else
        {
            mp[key]=value;
            elements.remove(key);
            elements.push_back(key);
        }
        
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
