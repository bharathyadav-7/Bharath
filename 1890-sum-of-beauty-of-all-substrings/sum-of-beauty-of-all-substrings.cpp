class Solution {
public:
    int beautySum(string s) {
        int sum=0,n=s.size();
        for(int i=0;i<n;i++){
            unordered_map<char,int> freq;
            for(int j=i;j<n;j++){
                freq[s[j]]++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(auto it:freq){
                    mini=min(mini,it.second);
                    maxi=max(maxi,it.second);
                }
                sum +=(maxi-mini);
            }

        }
        return sum;
    }
};