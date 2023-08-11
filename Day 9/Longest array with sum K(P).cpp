#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int len= a.size(),arr_len=0,maxlen=0,i=0,j=0;
    long long sum=a[0];
    while(j<len){
        
        while (i<=j && sum > k) {
            sum-=a[i];
            i++;
        }
        if(sum==k){
            maxlen=max(maxlen,j-i+1);
        }
        j++;
        if(j<len) sum+=a[j];
    }
    return maxlen;
}