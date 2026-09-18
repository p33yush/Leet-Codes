class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<double>> res(n);
        
        for(int i=0;i<n;i++){
            res[i] = {(double)val[i]/wt[i],val[i],wt[i]};
        }
        
        sort(res.rbegin(),res.rend());
        
        int curr = 0;
        int i=0;
        double prof = 0;
        while(i<n && capacity >= res[i][2]){
            capacity-=res[i][2];
            prof+=res[i][1];
            i++;
        }
        
        if(i==n) return prof;
        else{
            prof+=(double)res[i][0]*capacity;
        }
        return prof;
        
    }
};
