// Write a C++ class called "Rectangle" that has two private member 
// variables: "length" and "width". The class should have a constructor 
// that initializes these member variables and public member functions 
// called "getArea" and "getPerimeter" that return the rectangle's area 
// and perimeter, respectively.#include <iostream>
#include <iostream>

class MyClass {
public:
    int data = 5;
    
    void printData(int d) {
        std::cout << data;
    }
    
    void printDataFromMember() {
        std::cout << data;
    }
};

int main() {
    MyClass obj;
    obj.printData(10);
    obj.printDataFromMember();
    
    return 0;
}