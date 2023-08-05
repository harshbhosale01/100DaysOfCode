class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int des=0;
        vector<int> v1;
        for(int i=0;i<nums.size();i++){
            des=target-nums.at(i);
            for(int j = i+1; j<nums.size();j++){
                if(des==nums.at(j)) {
                    v1.push_back(i);
                    v1.push_back(j);
                    return v1;
                }
            }
        }
        return v1;
    }
};