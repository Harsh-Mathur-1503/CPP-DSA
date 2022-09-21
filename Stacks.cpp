#include<iostream>
#include<stack>
using namespace std;


//implementation using arrays
 /*
 #define n 100
class stack
{
int* arr;
int top;
public:
stack(){
    arr = new int[n];
    top=-1;
}
void push(int x){
    if (top == n-1)
    {
        cout<<"Stack Overflow"<<endl;
        return;
    }
    top++;
    arr[top]=x;
}
void pop(){
    if (top == -1)
    {
        cout<<"No element to pop"<<endl;
        return;
    } 
    top--;
    
     }

int Top(){
    if (top==-1)
    {
        cout<<"No element in stack"<<endl;
        return -1;
    }
    return arr[top];
}
bool empty(){
    return top == -1;
}
} ;
*/
//reverse a sentence using stack
void reverseSentence(string s){
stack<string> st;
for (int  i = 0; i < s.length(); i++)
{
    string word="";
    while (s[i]!=' ' && i<s.length())
    {
       word += s[i];
       i++;
    }
    st.push(word);
}
while (
    !st.empty()
)
{
cout<<st.top()<<" ";
st.pop();
}
cout<<endl;
}


//insert at bottom 
void insertAtBottom(stack<int> &st , int ele){
    if (st.empty())
    {
        st.push(ele);
        return;
    }
    int topele=st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(topele);
}

//reversal of stack
                 //using recursion
void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    
    int ele=st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,ele);
}





int main()
{


stack<int> st;
st.push(1);
st.push(2);
st.push(3);
st.push(4);
reverse(st);
while (!st.empty())
{
  cout<<st.empty()<<" ";
  st.pop();  
}
cout<<endl;


string s = " Hey , how are you doing ? ";
reverseSentence(s);


return 0;
}