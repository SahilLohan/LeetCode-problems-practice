// Link : https://leetcode.com/problems/design-circular-queue/



// Code :
class Listnode
{
    public:
    int value;
    Listnode* next;

    Listnode()
    {
        value=0;
        next=nullptr;
    }

    Listnode(int value)
    {
        this->value = value;
        next=nullptr;
    }
};

class MyCircularQueue {
public:
    int max_size , size;
    Listnode* head; 
    Listnode* hend;

    MyCircularQueue(int k) {
        max_size = k;
        size = 0;
        head = nullptr;
        hend = nullptr;
    }
    
    bool enQueue(int value) {
        if(size<max_size)
        {
            
            if(this->isEmpty())
            {
                head = new Listnode(value);
                hend = head;

                hend->next = head;
            }
            else
            {
                Listnode* temp = new Listnode(value);
                hend->next = temp;
                hend = hend->next;
                hend->next = head;
            }
            size++;
            return true;
        }

        return false;
    }
    
    bool deQueue() {
        if(size>0)
        {
            Listnode* temp = head;
            head = head->next;
            hend->next = head;

            delete temp;
            size--;
            return true;

        }
        return false;
    }
    
    int Front() {
        if(size==0)
        return -1;
        else
        return head->value;
    }
    
    int Rear() {
        if(size==0)
        return -1;
        else
        return hend->value;
    }
    
    bool isEmpty() {
        if(size==0)
        return true;
        else
        return false;
    }
    
    bool isFull() {
        if(size==max_size)
        return true;
        else
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
