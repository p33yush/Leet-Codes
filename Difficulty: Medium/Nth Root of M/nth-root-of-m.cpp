class Solution {
  public:
    int nthRoot(int n, int m) {
        
        if(m==0) return 0;
        if(n==1) return m;
        // Code here
        int low = 1;
        int high=m;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            int res=pow(mid,n);
            if(res==m){
                return mid;
            }
            else if(res>mid){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
};