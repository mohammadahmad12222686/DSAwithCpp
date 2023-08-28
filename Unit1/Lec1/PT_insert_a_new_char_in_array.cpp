#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    char arr[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    int index;
    cin>>index;
    char Char;
    cin>>Char;
    n=n+1;
    for(int i=n-1; i>index ;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=Char;
    cout<<"Updated array after insertion:";
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
}