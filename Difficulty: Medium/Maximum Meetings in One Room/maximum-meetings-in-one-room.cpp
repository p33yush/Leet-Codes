class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // code here
        int n=s.size();
        vector<pair<int,int>> a(n);
        
        for(int i=0;i<n;i++){
            a[i]={f[i],i};
        }
        
        sort(a.begin(),a.end());
        vector<int> ans;
    
        int lastEnd = a[0].first;
        ans.push_back(a[0].second+1);
        
        for(int i=1;i<n;i++){
            if(s[a[i].second] > lastEnd){
                lastEnd = a[i].first;
                ans.push_back(a[i].second+1);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};