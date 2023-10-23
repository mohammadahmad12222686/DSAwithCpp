#include<iostream>
#include<stack>//for using stack stl
#include<math.h>//to use functions like pow
using namespace std;

int Prefix(string str){
    stack<int> s;
//str.length() Returns the number of characters in the string, not including any null-termination.
    for(int i=str.length()-1;i>=0;i--){
        if(str[i]>='0' && str[i]<='9'){        //yaha par ASCII value hi compare hogi
            s.push(str[i]-'0');                //integer store karwana hai
        }
        else
        {
            int op1=s.top();
            s.pop();
            int op2=s.top();
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
    string st="-+7*45+20";
    cout<<Prefix(st);
}