#include<stack>
string prefixToInfixConversion(string &s){
	// Write your code here.
	stack <string> st;
	string r;
	for(int i=s.length()-1; i>=0;i--)
	{
		if((s[i]>='a' && s[i]<='z'))
		{
			st.push(string(1, s[i]));//ye ek method hai char ko string banane ka for ex. ye char 'a' ko string "a" bana deta hai
		}
		else
		{
		string operand1 = st.top();
        st.pop();
    	string operand2 = st.top();
        st.pop();
        r = "(" + operand1 + s[i] + operand2 + ")";
        st.push(r);
		}

	}
return r;
}
