class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n==0) return 0;
        vector<int> leftMin(n,-1);
        vector<int> rightMin(n,n);

        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()) leftMin[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()) rightMin[i]=st.top();
            st.push(i);
        }
        int ans = heights[0];
        for(int i=0;i<n;i++){
            int r = rightMin[i]-1;
            int l = leftMin[i]+1;
            ans = max(ans,heights[i]*(r-l+1));
        }
        return ans;
    }
};