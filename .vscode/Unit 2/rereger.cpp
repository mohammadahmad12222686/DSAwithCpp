// Preethi is developing an input processing module for a chatbot. 
// Implement a program that reads user input and counts the number of
//  words to analyze the user's query. Utilize pointer to pointer 
//  concept to process the input and count the words.



// Note: This is a sample question asked in a Wipro interview.

// Input format :

// The input consists of a list of words/sentences.

// Output format :

// The output prints the count of the words that are present in the given sentence/sentences.

// Code constraints :

// 1 <= Total number of characters in the sentence(s) <= 1000

// Sample test cases :
// Input 1 :
// Hi, how are you? Hope this code helps you to learn. Happy Learning!! - 01245
// Output 1 :
// 15
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// write code in c++

#include<iostream>
#include<cstring>
using namespace std;

int word(char **str){
    int count=0;
    char *point=strtok(*str, " ");
    while(point!=nullptr){
        count++;
        point=strtok(nullptr, " ");
    }
    return count;
}
int main(){
    char input[1000];
    cin.getline(input, sizeof(input));
    char *ptr=input;
    int num=word(&ptr);
    cout<<num;
    return 0;
}


