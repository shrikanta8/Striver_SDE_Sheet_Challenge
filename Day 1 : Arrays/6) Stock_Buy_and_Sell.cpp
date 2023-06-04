class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit =INT_MIN,minCost=INT_MAX;
        
        for(auto n:prices){
            minCost = min(minCost,n);
            maxProfit=max(maxProfit,n-minCost);
        }
        return maxProfit;
    }
};
