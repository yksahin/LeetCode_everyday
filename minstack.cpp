/* MinStack in stack and queeues*/

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    stack<int> minStack;
    stack<int> primary;

    MinStack()
    {

    }
    void push(int val)
    {
        primary.push(val);
        if(minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
    }
    
    void pop()
    {
        if(!primary.empty() && !minStack.empty() 
        && minStack.top() == primary.top())
        {minStack.pop();}
        primary.pop();
    }

    int top()
    {
        return primary.top();
    }
    int getMin()
    {
        return minStack.top();
    }
};

int main(int argc, char const *argv[])
{
    MinStack m;
    m.push(-2);
    m.push(0);
    m.push(-3);
    cout<< m.getMin() << endl;;
    m.pop();
    cout<< m.top() << endl;
    cout<<m.getMin()<<endl;
    return 0;
}
