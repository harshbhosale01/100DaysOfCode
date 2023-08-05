class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len= nums.size(),i=0,j=len-1,count=0;
        if(len==1){
            if(nums.at(0)==val) {
                //nums.erase(0);
                return 0;
            }
            else return 1;
        }
        
        for(;i<=j ;i++){
            if(nums.at(i)==val){
                count++;
                while(nums.at(j)==val && i<j){ 
                    j--;
                    count++;
                }
                nums.at(i)=nums.at(j--);
            }
        }
        return len-count;
    }
};