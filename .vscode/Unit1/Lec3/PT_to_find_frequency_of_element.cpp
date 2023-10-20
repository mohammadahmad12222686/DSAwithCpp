// You are using GCC
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
   int size;
   cin>>size;
   int elements[size];
   const int MAX_ELEMENTS=1000;
   int frequency[MAX_ELEMENTS]={0};
   for(int i=0;i<size;i++){
       cin>>elements[i];
       frequency[elements[i]]++;
   }
    cout<<"Element Frequency"<<endl;
    for(int i=0; i<size; i++){
        if(frequency[elements[i]]>0){
            cout<<left<<setw(10)<<elements[i]<<setw(10)<<frequency[elements[i]]<<endl;
        frequency[elements[i]]=0;
        }
    }
    
    return 0;
    
}

// #include<iostream> and #include<iomanip>: These are preprocessor directives that 
// include necessary header files for input/output operations (iostream) and for 
// formatting output (iomanip).

// left: This is a manipulator from the iomanip library. It aligns the output to the 
// left within the specified width.



// setw(10): This is another manipulator from iomanip. It sets the width of the field
// for the next output. In this case, it sets the width to 10 characters. This means
//  that the printed content will take up at least 10 characters of space, and if it's 
//  shorter, the remaining space will be filled with padding.