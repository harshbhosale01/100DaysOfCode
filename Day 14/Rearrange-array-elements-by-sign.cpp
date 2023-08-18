class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i=0,j=1,k=0;
        vector <int> arr(nums.size(),0);
        while(k<nums.size()){
            if(nums[k]<0){
                arr[j]=nums[k];
                j=j+2;
            }
            else{
                arr[i]=nums[k];
                i=i+2;
            }
            k++;
        }
        return arr;
    }

};