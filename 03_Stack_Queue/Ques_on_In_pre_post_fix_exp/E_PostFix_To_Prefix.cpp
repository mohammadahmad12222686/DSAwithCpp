#include<stack>
string postfixToPrefix(string &s){
    // Write your code here.
    stack<string> st;
        string r;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-')
            {
                string op1=st.top();
                st.pop();
                string op2=st.top();
                st.pop();
                r=s[i]+op2+op1;
                st.push(r);

            }
            else
            {
                st.push(string(1,s[i]));
            }
}
return r;
}