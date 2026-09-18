class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int ans=0;
        for(int i:nums){
            if(i==1){
                cnt++;
                ans=max(cnt,ans);
            }
            else{
                cnt=0;
            }
        }
        return ans;
    }
};