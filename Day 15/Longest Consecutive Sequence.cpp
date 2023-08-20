class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int con=0,max_con=0;
        if(nums.size()==0) return 0; 
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]-nums[i+1]==-1){
                con++;
            }
            else if(nums[i]-nums[i+1]==0){
                continue;
            }
            else {
                con=0;
            }
            max_con=max(max_con,con);
        }
        return max_con+1;
    }
};