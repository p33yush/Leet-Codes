class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int i=0;
        int j=0;
        
        int n=arr.size();
        
        int minPlat =0;
        int train=0;
        
        while(i<n && j<n){
            if(arr[i]<= dep[j]){
                train++;
                i++;
            }
            else{
                train--;
                j++;
            }
            minPlat = max(minPlat,train);
        }
        return minPlat;
    }
};
