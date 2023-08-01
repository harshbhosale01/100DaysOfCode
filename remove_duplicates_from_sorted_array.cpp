class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size(),i=0;
        for(int j =1; j<len ;j++){
            if(nums.at(i)!=nums.at(j)) nums.at(++i)=nums.at(j);
        }
        return i+1;
    }
};