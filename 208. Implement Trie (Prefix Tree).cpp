// Link :-  https://leetcode.com/problems/implement-trie-prefix-tree/description/


class Trie {
public:
    vector<Trie*> children;
    bool isLeaf;
    Trie() {
        children=vector<Trie*>(26,nullptr);
        isLeaf=false;
    }
    
    void insert(string key) 
    {
        Trie* root=this;
        for(int i=0;i<key.length();i++)
        {
            if(root->children[key[i]-'a']==nullptr)
            {
                root->children[key[i]-'a']=new Trie();
            }
            root=root->children[key[i]-'a'];
            if(i==key.length()-1)
            root->isLeaf=true;
            
        }
    }
    
    bool search(string key) 
    {
        Trie* root=this;
        for(int i=0;i<key.length();i++)
        {
            if(root->children[key[i]-'a']==nullptr)
            return false;
            
            if(i==key.length()-1)
            {
                if(root->children[key[i]-'a']->isLeaf==false)
                return false;
                else
                return true;
            }
            root=root->children[key[i]-'a'];
        }
        return false;
    }
    
    bool startsWith(string key) 
    {
        Trie* root=this;
        for(int i=0;i<key.length();i++)
        {
            if(root->children[key[i]-'a']==nullptr)
            return false;
            
            if(i==key.length()-1)
            {
                return true;
            }
            root=root->children[key[i]-'a'];
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
