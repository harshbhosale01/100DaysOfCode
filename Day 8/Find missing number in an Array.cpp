class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0,len=nums.size(),actual_sum=0;
        actual_sum =(len*(len+1))/2;
        while(len){
            sum+=nums[--len];
        }
        return (actual_sum-sum);
    }
};