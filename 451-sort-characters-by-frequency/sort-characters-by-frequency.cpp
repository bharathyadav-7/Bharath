class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(auto ch:s){
            freq[ch]++;
        }
        int n=s.size();
        vector<vector<char>> bucket(n+1);
        for(auto it:freq){
            bucket[it.second].push_back(it.first);
        }
        string ans="";
        for(int i=n;i>=1;i--){
            for(auto c:bucket[i]){
                ans.append(i,c);
            }
        }
        return ans;   
    }
};