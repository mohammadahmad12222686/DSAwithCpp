#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    char arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n/2; i++){
        int p1=arr[i];
        int p2=arr[n-i-1];
        arr[i]=p2;
        arr[n-i-1]=p1;
    }

    cout<<"Updated array:";
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }

}