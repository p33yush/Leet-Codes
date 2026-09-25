class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int tar = accumulate(nums.begin(),nums.end(),0);
        tar=tar-x;
        unordered_map<int,int> mp;
        mp[0]=-1;
        int mx=-1;
        int t=0;
        int len=0;

        for(int i=0;i<nums.size();i++){
            t+=nums[i];
            if(mp.find(t)==mp.end()){
                mp[t]=i;
            }
            if(mp.find(t-tar)!=mp.end()){
                len = i - mp[t - tar];
                mx=max(mx,len);
            }
        }
        return mx == -1 ? -1 : nums.size()-mx;
    }
};
