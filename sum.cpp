#include<iostream>
using namespace std;

int main(){
 int size;
 int arr[100];
 cin>>size;
 for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
 int sum=0;
 for (int i = 0; i < size; i++)
 {

    sum=sum+arr[i];
 }
 cout<<"Sum="<<sum<<endl;
 return sum;
 
}