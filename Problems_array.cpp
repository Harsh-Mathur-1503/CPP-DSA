#include<iostream>
using namespace std ;
void printArray( int arr[] , int size){
    for (int i = 0; i < size; i++)
    {
        cout<< arr[i]<<" ";

    }
    cout<<endl;
}
void swapAlternate(int arr[], int size){
    for (int i = 0; i < size; i+=2)
    {
     if ((i+1)<size)
     {
        swap(arr[i],arr[i+1]);
     }
     
    }
    
}
int main(){
    int even[8]={5,2,9,4,7,6,1,8};
    int odd[5]={11,33,9,76,43};
    int last_casse[5]={11,22,33,44,55};
    swapAlternate(even, 8);
    printArray(even, 8);
    swapAlternate(odd, 5);
    printArray(odd, 5);
    swapAlternate(last_casse,5);
    printArray(last_casse,5);

    return 0;
}
