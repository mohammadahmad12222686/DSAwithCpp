// Write a C++ class called "Employee" that has three private 
// member variables: "name", "salary", and "employeeCode". The class
//  should have a constructor that initializes these member variables 
//  and a public member function called "displayInfo" that prints out 
//  the employee's name, salary, and employeeCode.


#include<iostream>
using namespace std;

class Employee{
    string name;
    int salary;
    int employeeCode;
public:
 void displayInfo(Employee obj){
    cout<<name<<" "<<salary<<" "<<employeeCode;
 }
 Employee(){};
 Employee(string name, int salary, int employeeCode){

 };


};

int main(){
    Employee adhiraj("Adhiraj", 1000000000, 001);
    displayInfo(adhiraj);
}