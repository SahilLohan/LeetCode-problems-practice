// Link : https://leetcode.com/problems/min-stack/


// Code : 

class MinStack {
public:
    stack<int> OGst;
    stack<int> MINst;
    int min=INT_MAX;

    MinStack() {
        
    }
    
    void push(int val) {
        
        if(val < min)
        {
            MINst.push(val);
            min = val;
        }
        else
        {
            MINst.push(min);
        }

        OGst.push(val);
    }
    
    void pop() {
        if(!OGst.empty())
        {
            OGst.pop();
            MINst.pop();
            if(!MINst.empty())
            min = MINst.top();
            else
            min = INT_MAX;
        }
    }
    
    int top() {
        if(!OGst.empty())
        {
            return OGst.top();
        }
        return -1;
    }
    
    int getMin() {
        if(!OGst.empty())
        {
            return MINst.top();
        }     
        return -1;   
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
