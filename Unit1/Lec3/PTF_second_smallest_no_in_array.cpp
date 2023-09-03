#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    cout<<"Second Smallest Element:"<<arr[1];
}

// We have discussed qsort() in C. C++ STL provides a similar function sort that sorts a
// vector or array (items with random access)

/*It generally takes two parameters, the first one being the point of the array/vector 
from where the sorting needs to begin and the second parameter being the length up to
which we want the array/vector to get sorted. The third parameter is optional and can
 be used in cases such as if we want to sort the elements lexicographically.*/


 
 /*Here we take two parameters, the beginning of the
    array and the length n upto which we want the array to
    be sorted    sort(arr, arr + n); */
   



/*How to sort in descending order? 
sort() takes a third parameter that is used to specify the order in which elements
are to be sorted. We can pass the “greater()” function to sort in 
descending order. This function does a comparison in a way that puts greater elements
 before.  sort(arr, arr + n, greater<int>());  */    
  