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
## Day 8

Today, I solved 4 problems on arrays.
## [Find the Union](https://www.codingninjas.com/studio/problems/sorted-array_6613259)
```
vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    int i = 0, j = 0; // pointers
    int n=a.size().m=b.size();
  vector < int > Union;
  while (i < n && j < m) {
    if (a[i] <= b[j]) 
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(a[i]);
      i++;
    } else 
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(b[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != a[i])
      Union.push_back(a[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != b[j])
      Union.push_back(b[j]);
    j++;
  }
  return Union;
}
```
## [Find missing number in an Array](https://leetcode.com/problems/missing-number/)
```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0,len=nums.size(),actual_sum=0;
        actual_sum =(len*(len+1))/2;
        while(len){
            sum+=nums[--len];
        }
        return (actual_sum-sum);
    }
};
```
## [Maximum Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/)
```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len=nums.size(),max_count=0,count=0;
        while(len){
            if(nums[--len]==1) count++;
            else count=0;
            if(max_count<count)max_count=count;
        }
        return max_count;
    }
};
```
## [Single Number](https://leetcode.com/problems/single-number/)
```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int exor=0,len=nums.size();
        while(len){
            exor^=nums[--len];
        }
        return exor;
    }
};
```