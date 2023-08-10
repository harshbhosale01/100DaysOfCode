class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len=nums.size(),max_count=0,count=0;
        while(len){
            if(nums[--len]==1) count++;
            else count=0;
            if(max_count<count)max_count=count;
        }
        return max_count;
    }
};