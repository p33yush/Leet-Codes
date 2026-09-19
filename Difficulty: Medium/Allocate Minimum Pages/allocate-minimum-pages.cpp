class Solution {
  public:
  
    bool canAllocate(vector<int>& arr, int k, long long limit){
        int cnt=1;
        
        long long pageSum= 0;
        
        for(int i=0;i<arr.size();i++){
            if(pageSum+arr[i] >limit){
                cnt++;
                pageSum=arr[i];
            }
            else{
                pageSum+=arr[i];
            }
            
            
        }
        return cnt<=k;
    }
    int findPages(vector<int> &arr, int k) {
        if(k>arr.size()) return -1;
        // code here
        long long low = arr[0];
        long long high=0;
        
        for(int i:arr){
            if(i>low) low=i;
            high+=i;
        }
        int res=0;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(canAllocate(arr,k,mid)){
                res = mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return res;
    }
};