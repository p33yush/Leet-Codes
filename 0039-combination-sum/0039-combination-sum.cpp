class Solution {
public:
    void help(vector<int>& candidates,int idx,int target,int currSum,vector<int>& temp, vector<vector<int>>& ans){
        //base
        if(currSum==target){
            ans.push_back(temp);
            return;
        }

        if(currSum>target){
            return;
        }
        if(idx == candidates.size()){
            return;
        }

        //include
        temp.push_back(candidates[idx]);
        help(candidates,idx,target,currSum+candidates[idx],temp,ans);
        temp.pop_back();

        //exclude
        help(candidates,idx+1,target,currSum,temp,ans);
    
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        help(candidates,0,target,0,temp,ans);
        return ans;
        
    }
};