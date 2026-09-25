class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left = 0;
        int currSum = 0;
        int sum = accumulate(nums.begin(),nums.end(),0);

        int tar= sum-x;
        int mx=-1;
        if(tar<0) return -1;
        if(tar==0) return nums.size();

        for(int right = 0;right<nums.size();right++){
            currSum+=nums[right];
            while(currSum > tar){
                currSum -= nums[left];
                left++;
            }
            if(currSum == tar){
                mx=max(mx,right-left+1);
            }
        }

        return mx==-1?-1:nums.size()-mx;
    }
};