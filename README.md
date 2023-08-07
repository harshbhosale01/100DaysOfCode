## Day 5
Today, I solved the problem [Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/) on Leetcode.
```cpp
/*Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.*/
//For Example: If array [1,2,3,4,5] is rotated as [3,4,5,1,2] then A[0] is rotated to index 3 therefore x will be 3.
class Solution {
public:
    bool check(vector<int>& nums) {
        int len=nums.size(),i=1,x=-1;
        vector <int> nums1 =  nums;
        sort(nums1.begin(), nums1.end()); //Sorting the vector
        while(i<len){ 
            if(nums[i-1]>nums[i]) //Checking if Current element is less than previous element to find the rotation index
            {
                x=i; //Copying the rotation index in x
                cout<<x<<"\n";
                break;
            }
            i++;
            }
        if(x==-1) return 1; //If Rotation index does not exists the Array is sorted
        else {
            for(i=0;i<len;i++){
                if(nums1[i]!=nums[(i+x)%len]) return 0; 
            }
            return 1;
        }
    }
};
```