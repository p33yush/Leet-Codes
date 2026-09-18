class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = height[0];
        int rmax = height[n-1];
        int ans=0;


        int left=1;
        int right=n-2;

        while(left<=right){
            if(lmax>rmax){
                ans+=max(0,rmax-height[right]);
                rmax=max(rmax,height[right]);
                right--;
            }
            else{
                ans+=max(0,lmax-height[left]);
                lmax=max(lmax,height[left]);
                left++;
            }
        }
        return ans;
    }
};