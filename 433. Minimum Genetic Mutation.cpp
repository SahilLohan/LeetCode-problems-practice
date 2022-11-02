// Link :- https://leetcode.com/problems/minimum-genetic-mutation/description/


class Solution {
public:

    int minMutation(string start, string end, vector<string> bank) {
        unordered_set<string> visited;

        queue<string> q;
        q.push(start);
        visited.insert(start);

        
        int count=0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                string node=q.front();
                q.pop();
                if(node==end) 
                {
                    return count;
                }

                for(char ch:"ACGT")
                {
                    for(int index=0;index<node.size();index++)
                    {
                        string node1=node;
                        node1[index]=ch;
                        if(visited.count(node1)==0 && find(bank.begin(),bank.end(),node1)!=bank.end())
                        {
                            q.push(node1);
                            visited.insert(node1);
                            
                        }

                    }
                }
            }
            count++;
        }
        return -1;
    }
};
