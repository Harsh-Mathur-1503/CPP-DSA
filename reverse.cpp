#include<iostream>
using namespace std;

void reverse(int arr[],int size){
    int start = 0;
    int end = size-1;
    while (start<=end)
    {
        swap(arr[start],arr[end]);
        start ++;
        end -- ;
    }
    

}
void printarray(int arr[], int size){
    for (int i = 0; i < size; i++)
 {
   cout<<arr[i]<<" ";
 }
    
}
int main(){
    int arr[6]={1,2,3,4,5,6};
    int brr[5]={10,20,30,40,50};
    reverse(arr,6);
    reverse(brr,5);
    printarray(arr,6);
    printarray(brr,5);
}