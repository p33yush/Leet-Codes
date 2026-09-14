class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1 = 0;
        int m2 = 0;
        int c1 = 0;
        int c2 = 0;

        for(int i=0;i<nums.size();i++){
            if(c1>0 && nums[i] == m1){
                c1++;
            }
            else if(c2>0 && nums[i]==m2){
                c2++;
            }
            else if(c1==0){
                m1=nums[i];
                c1=1;
            }
            else if(c2==0){
                m2=nums[i];
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }

        vector<int> ans;
        int sz = nums.size()/3;

        if(count(nums.begin(),nums.end(),m1) > sz){
            ans.push_back(m1);
        }
        
        if(m2!=m1 && count(nums.begin(),nums.end(),m2) > sz){
            ans.push_back(m2);
        }

        return ans;


    }
};