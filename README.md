## Day 1
Today, I solved the problem [Remove Duplicates from sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) on Leetcode.
- In this approach there will be two pointers, we will increment the pointer j in each iteration and copy the element at j to i if both elements are different, we will increment i pointer before copying.
- What happens is if there are duplicated element then the pointer i does not move ahead while pointer j does, And when elements at both pointers are different the duplicated elemnet is replaced with element at j. 
```cpp
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
```
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
## Day 6
Today, I gave coding test for a consultancy firm. In which I was able to figure out solution for one problem, but I was encountered by segmentation fault. I need to work with Dynamic Initialisation of 2D array/vector to avoid such errors in future.

## Day 7
Today, I solved 2 problems based on array. 
### [Rotate Array](https://leetcode.com/problems/rotate-array/)

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size(),i,j=0;
        vector<int> nums1(len);
        k=k%len;
        for(i=len-k;i<len;i++){
            nums1[j++]=nums[i];
        }
        i=0;
        for(;j<len;j++){
            nums1[j]=nums[i++];
        }
        nums=nums1;

    }
};
```
### [Move Zeros to End](https://leetcode.com/problems/move-zeroes/)
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     int i=0,j=0;
     while(j<nums.size()){
         if(nums[j]!=0) swap(nums[i++],nums[j]);
         j++;
     }
    }
};
```