#include<iostream>
using namespace std;
//array impplementation
/*
 class queue
 {
    int* arr;
    int front;
    int back;
    int n;
 
 public:
    queue(){
    arr=new int[n]; 
    front = -1;
    back = -1;
 };
 void push (int x){
    if (back == n-1)
    {
        cout<<"Queue overflow";
        return;
    }
    back++;
    arr[back]=x;
 }
void pop(){
    if (front == n-1 || front>back)
    {
        cout<<"No elements in queue"<<endl;
        return;
    }
    front++;
}    

int peek(){
    if (front == n-1 || front>back)
    {
        cout<<"No elements in queue"<<endl;
        return -1;
    }
    return arr[front];
   
 }
bool empty(){
     if (front == n-1 || front>back)
    {
        
        return true;
    }
    return false;
}

 };
 */



 //linked list implementation
class node
{

public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
class queue{
    node* front;
    node* back;
    public:
    queue(){
        front=NULL;
        back=NULL;
    }

    void push(int x){
        node* n =new node(x);
        if (front==NULL)
        {
            back=n;
            front=n;
            return;
        }
        
        back->next=n;
        back=n;
        
    }

    void pop(){
        if (front==NULL)
        {
            cout<<"No element in Queue"<<endl;
            return;
        }
        node* todelete = front;
        front = front->next;
        delete todelete;
        
    }
int peek(){
     if (front==NULL)
        {
            cout<<"No element in Queue"<<endl;
            return -1;
        }
        return front->data;
}
bool empty(){
    if (front == NULL)
    {
        return true;
    }
    return false;
}
};











 int main(){
queue q;
q.push(1);
q.push(2);
q.push(3);
q.push(4);
cout<<q.peek()<<endl;
q.pop();
cout<<q.peek()<<endl;
q.pop();
cout<<q.peek()<<endl;
q.pop();
cout<<q.peek()<<endl;
q.pop();
cout<<q.empty()<<endl;
    return 0;
 }
 
 
 