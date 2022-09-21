#include<iostream>

using namespace std;
class que{
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(int x){
        if (s1.empty() and s2.empty())
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        if (s2.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        
    }
    int topval = s2.top();
    return topval;
    bool empty(){
        if (s1.empty() and s2.empty()){
            return true;
        }
        return false;
    }
};
int32_t main(){
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.pop();
    q.push(5);
    cout<<q.pop()<<"\n";
   cout<<q.pop()<<"\n";
   cout<<q.pop()<<"\n";
   cout<<q.pop()<<"\n";
   cout<<q.pop()<<"\n";
}