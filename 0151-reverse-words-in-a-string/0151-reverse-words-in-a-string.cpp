class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        vector<string> words;
        while(i<n){
            while(i<n && s[i]==' ') i++;
            
            string word="";
            while(i<n && s[i]!=' '){
                word+=s[i];
                i++;
            }

            if(!word.empty()){
                words.push_back(word);
            }
        }
        string ans="";
        for(int k=words.size()-1;k>=0;k--){
            ans+=words[k];
            if(k>0) ans+=' ';
        }
        return ans;
    }
};