class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size(),i,j=0;
        vector<int> nums1(len);
        k=k%len;
        for(i=len-k;i<len;i++){
            nums1[j++]=nums[i];
        }
        i=0;
        for(;j<len;j++){
            nums1[j]=nums[i++];
        }
        nums=nums1;

    }
};