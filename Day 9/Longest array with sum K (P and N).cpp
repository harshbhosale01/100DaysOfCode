#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    int len= nums.size(),arr_len=0,maxlen=0;
    int rem;
    int sum=0;
    map<int,int> umap;
    for(int i=0;i<len;i++){
        sum+=nums[i];
        if(sum==k) maxlen=max(maxlen,i+1);
         rem=sum-k;
        if(umap.find(rem)!=umap.end()){
            maxlen=max(maxlen,i-umap[rem]);
        }
        if(umap.find(sum)==umap.end()) umap[sum]=i;
    }
    return maxlen;
}