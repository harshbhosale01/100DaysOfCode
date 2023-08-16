class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0, len=nums.size(),sum=0,maxi=INT_MIN;
        while(i<len){
            sum+=nums[i];
            maxi=max(sum,maxi);
            if(sum<0) sum=0;
            i++;
        }
        return maxi;
    }
};