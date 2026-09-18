class Solution {
  public:
    void sum(vector<int>& arr, int idx, int currSum,vector<int>& res){
        if(idx == arr.size()){
            res.push_back(currSum);
            return;
        }
        
        sum(arr,idx+1,currSum+arr[idx],res);
        sum(arr,idx+1,currSum,res);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        
        vector<int> res;
        sum(arr,0,0,res);
        return res;
        
    }
};