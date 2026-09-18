class Solution {
public:
    void help(vector<int>& nums,int idx,vector<vector<int>>& res,vector<int>& temp){
        //base
        if(idx==nums.size()){
            res.push_back(temp);
            return;
        }

        //include
        temp.push_back(nums[idx]);
        help(nums,idx+1,res,temp);
        temp.pop_back();


        //exclude
        while(idx+1<nums.size() && nums[idx]==nums[idx+1]) idx++;
        help(nums,idx+1,res,temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> res;
        help(nums,0,res,temp);
        return res;    
    }
};