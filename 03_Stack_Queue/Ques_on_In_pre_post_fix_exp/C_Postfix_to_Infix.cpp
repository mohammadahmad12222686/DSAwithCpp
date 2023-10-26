string postToInfix(string postfix) {
    // Write your code here.
    stack <string> st;
	string r;
	for(int i=0; i<postfix.length();i++)
	{

        if(postfix[i]=='*' ||postfix[i]=='+' ||postfix[i]=='-' ||postfix[i]=='/')
        {
            string operand1 = st.top();
            st.pop();
    	    string operand2 = st.top();
            st.pop();
            r = "(" + operand2 + postfix[i] + operand1 + ")";
            st.push(r);
        }
		else
		{
		st.push(string(1, postfix[i]));
		}

	}
return r;
}