class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
            int low=1,mid,high=nums.size()-2;
            if(nums.size()==1) return nums[0];
            else if(nums[0]!=nums[1]) return nums[0];
            else if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
            while(low<=high)
            {
                mid=(low+high)/2;
                if((nums[mid-1]!=nums[mid]) && (nums[mid+1]!=nums[mid]))
                {
                    return nums[mid];
                }
                else if((mid%2 == 0 && nums[mid]==nums[mid+1]) || (mid%2 == 1 && nums[mid]==nums[mid-1]))
                {
                    low=mid+1;
                }
                else high=mid-1;;
            }
            return -1;
    }
};