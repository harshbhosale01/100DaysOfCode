class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro=0,minprice=INT_MAX,i=0;
        while(i<prices.size()){
            minprice=min(minprice,prices[i]);
            maxpro=max(maxpro,prices[i]-minprice);
            i++;
        }
        return maxpro;
    } 
};