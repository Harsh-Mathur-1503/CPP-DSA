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
 void insert_at_head(Node* &head , int val){

 }
 void display(Node* &head){
    Node* curr = head;
    while (curr!= NULL)
    {
        curr=curr->next;
        cout<< curr-> data <<endl;
    }
    cout<<"NULL"<<endl;
 }