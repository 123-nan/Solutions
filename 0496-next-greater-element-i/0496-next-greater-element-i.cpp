class Solution {
public:
    int f(int num,vector<int>&nums2)
    {
        int size=nums2.size();
        int idx=-1;
        for(int i=0;i<size;i++)
        {
           if(nums2[i]==num)
            idx=i;
        }
        for(int i=idx;i<size;i++)
        {
            if(nums2[i]>num)
                return nums2[i];
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int res=f(nums1[i],nums2);
            ans.push_back(res);
                
        }
        return ans;
    }
};