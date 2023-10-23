// Example

// Consider the following infix expression:

// (A + B) * C  (infinix meaning beech me)
// This expression can be converted to postfix and prefix as follows:

// Postfix: A B + C *      (prefix meaning operatror operand se pehle)
// Prefix: * + A B C       (postfix meaning operatror operand ke baad me)

#include<iostream>
#include<stack>//for using stack stl
#include<math.h>//to use functions like pow
using namespace std;

int Postfix(string str){
    stack<int> s;
//str.length() Returns the number of characters in the string, not including any null-termination.
    for(int i=0;i<str.length();i++){
        if(str[i]>='0' && str[i]<='9'){        //yaha par ASCII value hi compare hogi
            s.push(str[i]-'0');                //integer store karwana hai
        }
        else
        {
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();
            switch (str[i])
            {
                case '+':
                s.push(op1 + op2);
                break;
                case '-':
                s.push(op1 - op2);
                break;
                case '*':
                s.push(op1 * op2);
                break;
                case '/':
                s.push(op1 / op2);
                break;
                case '^':
                s.push(pow(op1,op2));
                break;

            }
            
        }
    }
    return s.top();
}
int main(){
    string st="46+2/5*7+";
    cout<<Postfix(st);
}