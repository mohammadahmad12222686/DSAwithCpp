class MinStack {
    stack < pair < int, int >> st;//STACK ME DO VALUE IN PAIR AYSE STORE KARATE HAIN
public:
    MinStack() {
        
    }
    
    void push(int val) {
         int min;
      if (st.empty()) {
        min = val;
      } else {
        min = std::min(st.top().second, val);//PAIR KI VALUE KO st[1].first st[1].second karke access ya allot kliya ja sakta
      }
      st.push({val,min});
        
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
      return st.top().first;  //PAIR KI VALUE KO st[1].first st[1].second karke access ya allot kliya ja sakta
    }
    
    int getMin() {
        return st.top().second;//PAIR KI VALUE KO st[1].first st[1].second karke access ya allot kliya ja sakta
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */