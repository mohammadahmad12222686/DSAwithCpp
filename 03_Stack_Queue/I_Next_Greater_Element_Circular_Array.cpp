
/****************************OPTIMISED HAI*************************/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n, -1);
        int count=0;
        while(count!=2*n)
        {
            while(!st.empty() && nums[n-(count%n)-1]>=st.top())
            {
                st.pop();
            }
            if(!st.empty() && st.top()>nums[n-(count%n)-1])
            {
                ans[n-(count%n)-1]=st.top();
                
            }
            st.push(nums[n-(count%n)-1]);
            count++;
        }
        return ans;

        // vector<int> ans(n, -1);
        // for(int i=0;i<n;i++){
        //     int j=(i+1)%n;
        //     while(j!=i)
        //     {
        //         if(nums[j]>nums[i])
        //         {
        //             ans[i]=nums[j];
        //             break;
        //         }
        //         j=(j+1)%n;
        //     }
        // }
        // return ans;
    }
};