class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int exor=0,len=nums.size();
        while(len){
            exor^=nums[--len];
        }
        return exor;
    }
};