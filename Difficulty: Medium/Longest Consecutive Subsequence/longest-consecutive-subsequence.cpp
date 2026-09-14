class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        // code here
        unordered_set<int> s;
        int ans=0;
        for(int i:arr){
            s.insert(i);
        }
        for(int i:arr){
            if(s.find(i)!=s.end() && s.find(i-1)==s.end()){
                int val=0;
                int cnt=0;
                val = i;
                cnt = 0;
                
                while(s.find(val)!=s.end()){
                    val++;
                    cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};