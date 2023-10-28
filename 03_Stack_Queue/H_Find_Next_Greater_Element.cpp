/*****************************OPTIMISED NAHI HAI*****************************/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;
        int count;
      for(int i=0; i<nums1.size();i++)
      {
  
          for(int j=0; j<nums2.size();j++)
          {
              if(nums1[i]==nums2[j])
              {
                 
                int max=nums2[j];
                count=0;
                for(int k=j+1;k<nums2.size();k++)
                {
                    count=0;
                    if(nums2[k]>max)
                    {
                        max=nums2[k];
                        count++;
                        break;
                    }
                }
                if(count>0)
                {
                    ans.push_back(max);
                    break;
                }
                else
                {
                    ans.push_back(-1);
                    break;
                }
               
            }

              }
          }
      
      return ans;  
    }
};