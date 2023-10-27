
/****************************************************Convert Prefix to Postfix***********************************************/
string preToPost(string s) {
    // Write Your Code Here
    stack<string> st;
        string r;
        for(int i=s.length();i>=0;i--)
        {
            if(s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-')
            {
                string op1=st.top();
                st.pop();
                string op2=st.top();
                st.pop();
                r=op1+op2+s[i];
                st.push(r);

            }
            else
            {
                st.push(string(1,s[i]));
            }
}
return r;
}