#include<iostream>
#include<fstream>
using namespace std;

int main(){

    ifstream inFile;
    string str;
    // ofstream onFile;
    // onFile.open("file.txt");
    // // onFile.open("C:\\Users\\itsme\\OneDrive\\Desktop\\test.txt>");
    // onFile<<"Printed in file";
    // cout<<"File Created successfully"<<endl;
    // onFile.close();
    inFile.open("file.txt");

    // inFile >> str;
    // cout<<"File updated"<<endl;
    // cout<<str;
    while(getline(inFile, str)){
        cout<<str;
    }

    inFile.close();

    ofstream onFile;

    onFile.open("file1.text");
    onFile<<"Printed in fileiheirgheg errge gegergergergerr ger ger ger gr rgegeretq";

    onFile.close();











}