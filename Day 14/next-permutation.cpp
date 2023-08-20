class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j,len=nums.size(),diff=INT_MAX,index;
        for(i=len-2;i>0;i--){
            diff=INT_MAX;
            index=-1;
            for(j=i+1;j<len;j++){
                if((diff>(nums[j]-nums[i])) && ((nums[j]-nums[i])>0)) 
                {
                    diff=nums[j]-nums[i];
                    index=j;
                }
            }
            if(index!=-1) break;
        }
        swap(nums[i], nums[index]);
        sort(nums.begin()+i+1,nums.end());
    }
};