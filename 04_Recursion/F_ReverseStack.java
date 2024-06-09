// https://www.geeksforgeeks.org/problems/reverse-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-stack

import java.util.*;
class F_ReverseStack
{
    static void reverse(Stack<Integer> s) {
        if (s.size() > 0) {
            int temp = s.pop();
            reverse(s);
            insertAtBottom(s, temp);
        }
    }

    static void insertAtBottom(Stack<Integer> s, int num) {
        if (s.isEmpty()) {
            s.push(num);
        } else {
            int temp = s.pop();
            insertAtBottom(s, num);
            s.push(temp);
        }
    }   
  
    public static void main(String[] args) {
        Stack<Integer> st=new Stack<>();
        
        st.push(8);
        st.push(6);
        st.push(9);
        st.push(3);
        st.push(1);
        st.push(3);
        st.push(9);
        st.push(8);
        st.push(6);
        st.push(8);
        reverse(st);
        while(!st.isEmpty()){
            int n=st.pop();
            System.out.print(n +" ");
        }
        
    }
}