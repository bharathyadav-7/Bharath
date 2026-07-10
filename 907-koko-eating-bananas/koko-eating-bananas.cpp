class Solution {
public:
int findMax(vector<int> &piles){
    int n=piles.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        maxi=max(maxi,piles[i]);
    }
    return maxi;
}
double totalHours(vector<int>&piles,int hourly){
    int n=piles.size();
    double totalH=0;
    for(int i=0;i<n;i++){
        totalH+=ceil((double)piles[i]/(double)hourly);
    }
    return totalH;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int low=0,high=findMax(piles);
    while(low<=high){
        int mid=low+(high-low)/2;
        double totalH=totalHours(piles,mid);
        if(totalH<=h){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}
};