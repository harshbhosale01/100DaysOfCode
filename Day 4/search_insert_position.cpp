class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int mid, low=0, high=nums.size()-1;
    if(nums[0]>=target) return 0;
    else if(nums[high]<=target) return high+1;
    while(low!=high){
    mid = (low + high)/2;
    if (target == nums[mid])
        return mid;
    else if (target > nums[mid]) // x is on the right side
        low = mid + 1;
    else                       // x is on the left side
        high = mid - 1;
    }
    return low+1;
    }
};