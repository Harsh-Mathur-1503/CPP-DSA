#include<iostream>
using namespace std;
void update(int arr[],int n){
cout<<"Inside the function"<<endl;
//updating array's first function
arr[0]=120;
for (int i = 0; i < 3; i++)
 {
   cout<<arr[i]<<" ";
 }
cout<<"Going back to main function"<<"";
}
int main(){
 int arr[3]={1,2,3};
 update(arr , 3);
 //printing the array
 for (int i = 0; i < 3; i++)
 {
   cout<<arr[i]<<" "; 
 }
 
}