class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len=nums.size(),i=0,j=0,k=len-1;
        while(j<=k){
            if(nums[j]!=1){
                if(nums[j]==0){
                    //while(nums[i]==0 && i<j) i++;
                    swap(nums[i],nums[j]);
                    i++;
                    j++;
                }
                else {
                    //while(nums[k]==2 && k>j) k--;
                    swap(nums[k],nums[j]);
                    k--;
                }
            }
            else j++;
        }
    }
};