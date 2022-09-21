#include<iostream>
using namespace std;
//Implementation of Linked lists 
class Node {

public:
  int data ;
  Node* next;
  Node (int data){
    this -> data= data ;
    this ->next = NULL ;
  }
 };
 //Insert at tail 
  void insertAtTail (Node* &head , int val){

    Node* n = new Node (val);
    if (head == NULL)
    {
        head=n;
        return;
    }
    
    Node* temp = head;
    while (temp -> next != NULL){
        temp = temp -> next ; 
         
    }
    temp -> next = n;
  }
 //Display of Node 
void display (Node* head){
    Node* temp = head;
    while (temp!=NULL)
    {
    cout<<temp->data<<"->";
    temp = temp -> next ;

    }
    cout<<"NULL"<<endl;
}
//Finding Length of a linked lists
       int length(Node* &head){
         int l=0;
         Node* temp=head;
            while (temp != NULL)
                  {
                      l++;
                      temp=temp->next;
                  }
    
        return l;
        }  

//FInding intersection of two linked lists
   /*
   first we'll find the length of both linked lists
   And then see for the node where both pointers are 
   on same node....  
   */
  
int intersection(Node* &head1 , Node* &head2){

    int l1 = length(head1);
    int l2 = length(head2);

    int d=0 ;
    Node* ptr1;  // pointing towards linked list having greater length
    Node* ptr2;  // pointing towards linked list having shorter length
      if (l1 > l2)
      {
         d= l1-l2;
         ptr1=head1;
         ptr2=head2;
      }
      else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
      }
while (d)
{
 ptr1 = ptr1->next;
 if (ptr1 == NULL)
 {
    return 1;
 }
 
 d--;
}
 while (ptr1 != NULL && ptr2 != NULL)
 {
    if (ptr1 == ptr2 )
    {
        return ptr1->data;
    }
    
    ptr1 = ptr1 -> next ;
    ptr2 = ptr2 -> next ;   
 }
  
return -1;
}


//Code for making intersection of two linked lists
void intersect(Node* &head1 , Node* &head2 , int pos){
Node* temp1=head1;
pos--;
while (pos--)
{
    temp1=temp1->next;
}
Node* temp2 = head2 ;
while (temp2->next!=NULL)
{
    temp2=temp2->next;
}
temp2->next=temp1;
}


//Merging two sorted linked lists
   //Create a dummy node -ptr3
   //ptr -1 head1
   //ptr -2 head2
Node* merge( Node* &head1 , Node* &head2){
    Node* p1=head1;
    Node* p2=head2;
    Node* dummyNode = new Node(-1);
    Node* p3 = dummyNode;

    while (p1 != NULL && p2!= NULL)
    {
        if (p1->data<p2->data)
        {
           p3 ->next = p1;
           p1 = p1->next;
        }
        else {
            p3 -> next = p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    
     //to check if any of our linked list has ended or not
     while (p1 != NULL)
     {
        p3 ->next=p1;
        p1=p1->next;
        p3=p3->next;
     }
     while (p2 != NULL)
     {
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
     }
return dummyNode-> next;
}
//Merging using recursion
Node* merge_recursive(Node* &head1, Node* &head2){


    Node* result;
    if (head1 == NULL)
    {
       return head2;
        
    }
    if (head2 == NULL)
    {
       return head1;
        
    }
    
    if (head1 ->data < head2->data)
    {
        result = head1;
        result -> next = merge_recursive(head1->next,head2);
    }
    else{
        result = head2;
        result -> next = merge_recursive(head1,head2->next);
    }
    return result;
}
 int main(){
    Node* head1 = NULL;
    Node* head2 = NULL;
/*
insertAtTail(head1,1);
insertAtTail(head1,2);
insertAtTail(head1,3);
insertAtTail(head1,4);
insertAtTail(head1,5); 
insertAtTail(head1,6);
insertAtTail(head2,8);
insertAtTail(head2,5);
insertAtTail(head2,10);
display(head1);
display(head2);
intersect(head1,head2,2);
cout<<intersection(head1,head2)<<endl; 
*/
int arr1[]={1,4,5,7};
int arr2[]={2,3,6};
for (int i = 0; i < 4; i++)
{
    insertAtTail(head1,arr1[i]);
}
for (int i = 0; i < 3; i++)
{
    insertAtTail(head2,arr2[i]);
}
display(head1);
display(head2);
Node* new_head=merge(head1,head2);
display(new_head);

    return 0 ;
 }