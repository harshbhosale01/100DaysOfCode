class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len=nums.size(),i=0,count=0,element;
        while(i<len){
            if(count==0) element=nums[i];
            if(element==nums[i]) count++;
            else count--;
            i++;
        }
        return element;
    }
};