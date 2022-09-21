//Doubly Linked lists
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;


    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }

};
//insertion at head
void insert_At_Head(node* &head , int val){
    node* n= new node(val);
    n->next=head;
    if (head != NULL)
    {
        head->prev=n;
    }
    
   

    head=n;
}
//insertion at end
void insert_At_Tail(node* &head , int val){
    if (head == NULL)
    {
        insert_At_Head(head,val);
        return;
    }
    
    node* n = new node(val);
    node* temp=head;
    while (temp->next = NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
//deletion of first node
void delete_At_Head (node* &head){
    node* todelete = head;
    head=head->next;
    head->prev= NULL;

    delete todelete;
}
//deletion in doubly linked lists



void deletion(node* &head , int pos){
    node* temp = head ;
    int count =1;
    //when you want to delete first node itself
    if (pos==1)
    {
        delete_At_Head(head);
        return;
    }
    
    while (temp != NULL && count != pos)
    {
        temp=temp->next;
        count++;
    }
    temp->prev->next= temp-> next ;
    if (temp ->next != NULL)
    {
       temp->next->prev = temp->prev ;
    }
    
    

    delete temp;

}

//displaying doubly linked lists
void display (node* &head){
    node* temp = head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"<->";
        temp = temp -> next;
    }
    cout<<endl;


}
int main(){
node* head=NULL;
 insert_At_Tail(head,1);
 insert_At_Tail(head,2);
 insert_At_Tail(head,3);
 insert_At_Tail(head,4);
 display(head);
 insert_At_Head(head,5);
 insert_At_Head(head,6);
 display(head);
 deletion(head,1);
 display(head);
    return 0;
}