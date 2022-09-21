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







//insert at Head
void insertAtHead(Node* &head , int val)
   {
    Node* n = new Node(val);    
    n->next=head;
    head=n;

   }
   //Searching
   bool search(Node* head, int key){
    Node* temp=head;
    while (temp!=NULL)
    {
        if (temp->data==key)
        {
            return true;
        }
        temp=temp->next;
    }
   }
    //Deletion of N'th node
                  //Deletion of first Node
void delete_first_node (Node* &head){
    Node* todelete=head;
    head=head->next;

    delete todelete;
}

        
    void deletion(Node* &head, int val)
    {

        if (head==NULL)//when linked list is empty
        {
            return;
        }
        if (head->next== NULL){
            //when linked consists of one element only
            delete_first_node(head);
            return;
        }
        
        
        
        Node* temp=head;
        while (temp->next -> data != val)
        {
            temp=temp->next; 


        }
        Node* todelete = temp->next;
        temp->next=temp->next->next;

        delete todelete;
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

//Iterative Method to reverse the Linked Lists
Node* reverse(Node* &head){
    Node* prevptr = NULL;
    Node* currptr = head ;
    Node* nextptr;

    while (currptr!=NULL)
    {
        nextptr=currptr->next;
        
        currptr->next = prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
     return prevptr;
}




//Recursive Method of reversing Linked Lists
Node* reverseRecursive(Node* &head){
    if (head==NULL || head->next == NULL)
    {
        return head;
    }
    
    Node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}



//Reversal of K nodes of a Linked Lists
Node* reverse_K(Node* &head , int k)
{
    Node*prevptr = NULL;
    Node* currptr = head ;
    Node* nextptr;

    int count=0;
    while (currptr != NULL && count<k)
    {
        nextptr=currptr->next;
        currptr->next = prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;

    }
    if (nextptr!=NULL)
    {
   head->next = reverse_K(nextptr,k);
    }
    
 return prevptr;


}
//Make a cycle 
void makeCycle(Node* &head , int pos){
    Node* temp = head;
    Node* startNode;
    int count =1;
    while (temp -> next != NULL)
    {
        if (count == pos)
        {
            startNode=temp;
        }
        temp=temp -> next ;
        count++;
        
    }
    temp -> next = startNode;
}


//Check cyclic or not
bool detect_Cycle(Node* &head){
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
        
    }
    
return true;
}
//Remove Cycle 
 void removeCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;
    do
    {
     slow= slow -> next ;
        fast = fast -> next -> next;
    } while (fast!= slow);
    fast=head;
    while (slow -> next !=  fast -> next )
    {
       slow = slow -> next;
       fast = fast -> next;
    }
    slow -> next = NULL;
 }
//Append last k nodes to start of Linked Lists

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

Node* kappend(Node* &head , int k){
    Node* newHead;
    Node* newTail;
    Node* tail = head;
      int l = length(head);
      int count = 1;


      while (tail->next != NULL)
      {
        if (count==l-k)
        {
           newTail=tail;

        }
        if (count == l-k+1)
        {
            newHead=tail;
        }
        tail=tail->next;
        count++;
      }
    newTail->next=NULL;
    tail->next=head;

    return newHead;  

}








int main()
{
/* 
Node* node1 = new Node(10);
cout<< node1->data <<endl;
cout<< node1->next <<endl;
*/
Node* head = NULL;
insertAtTail(head,1);
insertAtTail(head,2);
insertAtTail(head,3);
insertAtTail(head,4);
insertAtTail(head,5);
insertAtTail(head,6);
display(head);



 Node* newhead= reverse(head);
 display(newhead);

/* int k=2;
Node* newhead_1 = reverse_K(head,k);
display(newhead_1);
*/



makeCycle(head,3);
//display(head);
cout << detect_Cycle(head) <<endl;
removeCycle(head);
//display(head); 

kappend(head,4);
display(head);
 

  return 0 ;
}
   