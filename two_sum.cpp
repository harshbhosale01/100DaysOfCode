class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> des;
        auto j = des.begin();
        for(int i=0;i<nums.size();i++){
            if(des.find(target-nums.at(i))==des.end()){
                des.insert({i,nums.at(i)});
            }
            else {

            }
        }
    }
};