class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<int> ans(2);
        
        vector<pair<int,int>> jobs;
        for(int i=0;i<deadline.size();i++){
            jobs.push_back({deadline[i],profit[i]});
        }
        
        sort(jobs.begin(),jobs.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0;i<jobs.size();i++){
            if(jobs[i].first > pq.size()){
                pq.push(jobs[i].second);
            }
            else if(!pq.empty() && pq.top()<jobs[i].second){
                pq.pop();
                pq.push(jobs[i].second);
            }
        }
        
        while(!pq.empty()){
            ans[0]++;
            ans[1]+=pq.top();
            pq.pop();
        }
        return ans;
    }
};