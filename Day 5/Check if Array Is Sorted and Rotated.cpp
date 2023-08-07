class Solution {
public:
    bool check(vector<int>& nums) {
        int len=nums.size(),i=1,x=-1;
        vector <int> nums1 =  nums;
        sort(nums1.begin(), nums1.end());
        while(i<len){
            if(nums[i-1]>nums[i]) {
                x=i;
                cout<<x<<"\n";
                break;
            }
            i++;
            }
        if(x==-1) return 1; 
        else {
            for(i=0;i<len;i++){
                if(nums1[i]!=nums[(i+x)%len]) return 0;
            }
            return 1;
        }
    }
};