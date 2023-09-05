class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,mid,high=nums.size()-1,pass=0,low_idx=-1,high_idx=-1;
        vector <int> ans;
        if(nums.size()==1 && nums[0]==target) {
            ans.push_back(0);
            ans.push_back(0);
            return ans;
        }
        else if(nums.size()==1 && nums[0]!=target) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else{
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target) {
                pass=1;
                break;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        if(pass==1) {
            low_idx=mid;
            high_idx=mid;
            if(low_idx-1>=0) {
                while(nums[low_idx-1]==nums[low_idx]) 
                {
                    low_idx--;
                    if(low_idx==0) break;
                }
            }
            if(high_idx+1<nums.size()){
            while(nums[high_idx+1]==nums[high_idx]) 
            {
                high_idx++;
                if(high_idx==nums.size()-1) break;
            }
            }
        }
        ans.push_back(low_idx);
        ans.push_back(high_idx);
        
        return ans;
        
        }
    }
};