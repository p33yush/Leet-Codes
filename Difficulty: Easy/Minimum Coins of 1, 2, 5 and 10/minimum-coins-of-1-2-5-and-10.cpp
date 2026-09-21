class Solution {
  public:
    int findMin(int n) {
        // code here
        vector<int> denom = {1,2,5,10};
        int cnt=0;
        for(int i=denom.size()-1;i>=0;i--){
            
            cnt+=(int)n/denom[i];
            n=n%denom[i];
        }
        return cnt;
    }
};