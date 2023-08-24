class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map <int,int> set;
        int i=0,len=nums.size(),count=0,x=0;
        while(i<len){
            x+=nums[i];
            if(x==k) count++;
            if(set.find(x-k)!=set.end()){
                count=count+set[x-k];
            }
            if(set.find(x)==set.end()){
                set[x]=1;
            }
            else set[x]++;
            i++;
        }
        return count;
    }
};