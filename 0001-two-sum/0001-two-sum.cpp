class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //when it comes to indices you cannot sort the array
        int n=nums.size();
        vector<int>ans;
        // unordered_map<int,int>mp;
        // for(int i=0;i<n;i++)
        // {
        //     int a=target-nums[i];
        //     if(mp.find(a)!=mp.end())
        //     {
        //          ans.push_back(mp[a]);
        //         ans.push_back(i);
               
        //         return ans;
        //     }
        //     mp[nums[i]]=i;
        // }
        // return ans;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};