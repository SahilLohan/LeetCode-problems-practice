//link:-https://leetcode.com/problems/implement-queue-using-stacks/description/
class MyQueue {
public:
    stack<int> real;
    stack<int> temp; 
    
    void push(int x) {
        if(real.empty())
        {
            real.push(x);
        }
        else
        {
            while(!real.empty())
            {
                temp.push(real.top());
                real.pop();
            }
            real.push(x);
            while(!temp.empty())
            {
                real.push(temp.top());
                temp.pop();
            }
        }
    }
    
    int pop() {

        int ans = real.top();
        real.pop();
        return ans;
    }
    
    int peek() {
        return real.top();
    }
    
    bool empty() {
        return real.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
