class Solution {
  public:
    int single(vector<int>& arr) {
        // code here
        int ans=arr[0];
        for(int i=1;i<arr.size();i++){
            ans^=arr[i];
        }
        return ans;
    }
};