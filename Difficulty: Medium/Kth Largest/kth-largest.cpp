class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq;
        for(int i:arr){
            pq.push(i);
        }
        int ans=-1;
        while(!pq.empty() && k!=0){
            ans=pq.top();
            pq.pop();
            k--;
            
        }
        
        return ans;
    }
};