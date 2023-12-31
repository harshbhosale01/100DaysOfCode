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
### [Find the Union](https://www.codingninjas.com/studio/problems/sorted-array_6613259)
```cpp
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
### [Find missing number in an Array](https://leetcode.com/problems/missing-number/)
```cpp
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
### [Maximum Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/)
```cpp
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
### [Single Number](https://leetcode.com/problems/single-number/)
```cpp
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
## Day 9
Today, I solved 2 probelms based on Array.

### [Longest Subarray With Sum K (Positive)](https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399)

```cpp
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
```

### [Longest Subarray With Sum K (Positive and Negative)](https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_5713505)

```cpp
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
```

## Day 10
Today I solved the problem 'Sort an array of 0, 1 and 2' using Dutch National Flag approach.

### [Sort an array of 0,1 and 2](https://leetcode.com/problems/sort-colors/description/)
```cpp
    class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len=nums.size(),i=0,j=0,k=len-1;
        while(j<=k){
            if(nums[j]!=1){
                if(nums[j]==0){
                    //while(nums[i]==0 && i<j) i++;
                    swap(nums[i],nums[j]);
                    i++;
                    j++;
                }
                else {
                    //while(nums[k]==2 && k>j) k--;
                    swap(nums[k],nums[j]);
                    k--;
                }
            }
            else j++;
        }
    }
};
```

## Day 11
### [Majority Element(>n/2)](https://leetcode.com/problems/majority-element/description/)
```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len=nums.size(),i=0,count=0,element;
        while(i<len){
            if(count==0) element=nums[i];
            if(element==nums[i]) count++;
            else count--;
            i++;
        }
        return element;
    }
};
```

## DAY 12
Today, I learned Kadanes's algorithm to find the maximum sum in an array.
### [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/description/)
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0, len=nums.size(),sum=0,maxi=INT_MIN;
        while(i<len){
            sum+=nums[i];
            maxi=max(sum,maxi);
            if(sum<0) sum=0;
            i++;
        }
        return maxi;
    }
};
```

## Day 13
### [Best time to buy and sell stocks](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/)
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro=0,minprice=INT_MAX,i=0;
        while(i<prices.size()){
            minprice=min(minprice,prices[i]);
            maxpro=max(maxpro,prices[i]-minprice);
            i++;
        }
        return maxpro;
    } 
};
```

## Day 14

### [Rearrange-array-elements-by-sign](https://leetcode.com/problems/rearrange-array-elements-by-sign/)
```cpp
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
```

### [Next Permutation](https://leetcode.com/problems/next-permutation/)
```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j,len=nums.size(),diff=INT_MAX,index;
        for(i=len-2;i>0;i--){
            diff=INT_MAX;
            index=-1;
            for(j=i+1;j<len;j++){
                if((diff>(nums[j]-nums[i])) && ((nums[j]-nums[i])>0)) 
                {
                    diff=nums[j]-nums[i];
                    index=j;
                }
            }
            if(index!=-1) break;
        }
        swap(nums[i], nums[index]);
        sort(nums.begin()+i+1,nums.end());
    }
};
```
## Day 15
### [Leaders in an Array](https://www.codingninjas.com/studio/problems/superior-elements_6783446?leftPanelTab=1)
```cpp
    vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    int i=a.size()-1, max=INT_MIN;
    vector <int> a1;
    while(i>=0){
        if(a[i]>max) {
            a1.push_back(a[i]);
            max=a[i];
        }
        i--;
    }
    return a1;
}
```

### [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)
```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int con=0,max_con=0;
        if(nums.size()==0) return 0; 
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]-nums[i+1]==-1){
                con++;
            }
            else if(nums[i]-nums[i+1]==0){
                continue;
            }
            else {
                con=0;
            }
            max_con=max(max_con,con);
        }
        return max_con+1;
    }
};
```

## Day 16

### [Watermelon](https://codeforces.com/problemset/problem/4/A)
```cpp
#include <iostream>
using namespace std;
int main(){
    int w;
    cin>>w;
    if(w<=2) cout<<"NO";
    else if(w%2==0) cout<<"YES";
    else cout<<"NO";
    return 0;   
}
```

### [Bit++](https://codeforces.com/problemset/problem/282/A)
```cpp
#include <iostream>
using namespace std;
int main(){
    char str[3];
    int n,count=0;
    cin>>n;
    while(n--){
        cin>>str;
        if(str[1]=='+') count++;
        else count --;
    }
    cout<<count<<endl;
}
```

### [Chewbaсca and Number](https://codeforces.com/contest/514/problem/A)
```cpp  
#include <iostream>
#include <string>
using namespace std;
int main(){
    string num;
    cin>>num;
    int i=num.size()-1;
    while(i>0){
        if((*(num.begin()+i))>'4') {
            *(num.begin()+i)=(('9'-(*(num.begin()+i)))+'0');
        }
        i--;
    }
    if(*num.begin()!='9' && *(num.begin())>'4') {
        *(num.begin())=(('9'-(*(num.begin())))+'0');
    }
    cout<<num<<endl;
    return 0;
}
```

## Day 17 

### [Beautiful Matrix](https://codeforces.com/contest/263/problem/A)
```cpp
#include <iostream>
using namespace std;
int main()
{
    int mat[5][5],i=0,j=0,result;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cin>>mat[i][j];
            if(mat[i][j]==1) {
                result=abs(2-i)+abs(2-j);
            }
        }
    }
    cout<<result<<endl;
}
```

### [Soft Drinking](https://codeforces.com/contest/151/problem/A)
```cpp
#include<iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,k,l,c,d,p,nl,np,result;  
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    int x=(k*l)/nl;
    int y=c*d;
    int z=(p/np);
    result=min(x,y);
    result=min(result,z)/n;
    cout<<result<<endl;
    return 0;
}
```

### [Rotate Image](https://leetcode.com/problems/rotate-image/description/)
```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),i=0,j=0;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
```

## Day 18 

### [Gift Carpet](https://codeforces.com/contest/1862/problem/A)
```cpp
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int num, n, m, i, j, c = 0,pass=0;
    cin >> num;
    string str = {'v', 'i', 'k', 'a'};
    
    while (num--)
    {
        c=0;
        cin >> n; //row 
        cin >> m; //column
        char* vec= new char(n*m);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cin >> vec[i*m+j];
            }
        }
        for (i = 0; i < m; i++) //column
        {   
            pass=0;
            for (j = 0; j < n ; j++) //row
            {   
                if (vec[j*m+i] == str[c])
                {
                    pass=1;
                    break;
                }
                if(c==4) break;
            }
            if(pass==1 && c<4) c++;
        }
        delete[] vec;
        if(c==4) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
```

### [Sequmce Game](https://codeforces.com/contest/1862/problem/B)
```cpp
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int num,bsize,i,m,n,element,temp;
    cin>>num;
    while(num--){
        cin>>bsize;
        vector<int> b;
        vector<int> a;
        for(i=0;i<bsize;i++){
            cin>>element;
            b.push_back(element);
        }
        a.push_back(b[0]);
        m=0,n=1;
        for(i=0;i<bsize-1;i++){
            temp=b[i]-1;
            if(b[i]-b[i+1]==0){
                a.push_back(b[i+1]);
            }
            else{
            while(temp>b[i+1]) temp--;
            if(temp!=0) a.push_back(temp);
            a.push_back(b[i+1]);
            }
        }
        cout<<a.size()<<endl;
        for(i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        a.clear();
        b.clear();
    }
}
```

### [Subarray sum equals k](https://leetcode.com/problems/subarray-sum-equals-k/description/)
```cpp
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
```

## Day 19

### [Same Differences](https://codeforces.com/contest/1520/problem/D)
```cpp
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    int num,len,i,element;
    long long int count;
    cin>>num;
    while(num--){
        cin>>len;
        map<long long int,long long int> umap;
        //vector<int> vec(len,0);
        count=0;
        for(i=0;i<len;i++){
            cin>>element;
            if(umap.find(element-i)!=umap.end()){
                count=count+umap[element-i];
            }
            if(umap.find(element-i)==umap.end()) umap[element-i]=1;
            else umap[element-i]++;
        }
        cout<<count<<endl;
        umap.clear();
    }
return 0;
}
```

## Day 20

### [Increasing and Decreasing](https://codeforces.com/contest/1864/problem/A)
```cpp
#include <iostream>
using namespace std;
int main(){
    long long int num,x,y,n,i;
    cin>>num;
    while(num--){
        cin>>x>>y>>n;
        int* arr=new int(n);
        long long int diff=1;
        arr[0]=x;
        arr[n-1]=y;
        for(i=n-2;i>0;i--){
            arr[i]=arr[i+1]-diff;
            diff++;
        }
        if(!(diff<=(arr[1]-arr[0]))) cout<<"-1"<<endl;
        else {
            for(i=0;i<n;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
```

## Day 21

### [Implement Lower Bound](https://www.codingninjas.com/studio/problems/lower-bound_8165382?leftPanelTab=1)
```cpp
int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int low=0,mid,high=n-1,idx=n;
	while(low<=high){
		mid=(low+high)/2;
                if (arr[mid] >= x) {
				  high = mid - 1;
				  idx=mid;
                } 
				else low = mid + 1;
        }
	return idx;
}
```

## Day 22

### [Implement Upper Bound](https://www.codingninjas.com/studio/problems/implement-upper-bound_8165383)
```cpp
int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	
	int low=0,high=arr.size()-1,mid,idx=high+1;
	while(low<=high){
		mid=(low+high)/2;
		if(arr[mid]>x){
			high=mid-1;
			idx=mid;
		}
		else low=mid+1;
	}
	return idx;
}
```

### [Search Insert Position](https://leetcode.com/problems/search-insert-position/)
```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int mid, low=0, high=nums.size()-1;
    if(nums[0]>=target) return 0;
    else if(nums[high]<=target) return high+1;
    while(low!=high){
    mid = (low + high)/2;
    if (target == nums[mid])
        return mid;
    else if (target > nums[mid]) // x is on the right side
        low = mid + 1;
    else                       // x is on the left side
        high = mid - 1;
    }
    return low+1;
    }
};
```

## Day 23

### [Floor and Ceil in Array](https://www.codingninjas.com/studio/problems/ceiling-in-a-sorted-array_1825401)

```cpp
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	// Write your code here.
	int i=0,low=INT_MIN,high=INT_MAX;
	pair <int,int> PAIR1;
	while(i<n){
		if(arr[i]<=x) low=max(low,arr[i]);
		if(arr[i]>=x) high=min(high,arr[i]);
		i++;
	}
	//cout<<low<<" "<<high<<endl;
	if(low!=INT_MIN) PAIR1.first=low;
	else PAIR1.first=-1;
	if(high!=INT_MAX) PAIR1.second=high;
	else PAIR1.second=-1;
	return PAIR1;
}
```

### [First and Last position of element in sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,mid,high=nums.size()-1,pass=0,low_idx=-1,high_idx=-1;
        vector <int> ans;
        if(nums.size()==1 && nums[0]==target) {
            ans.push_back(0);
            ans.push_back(0);
            return ans;
        }
        else if(nums.size()==1 && nums[0]!=target) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else{
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target) {
                pass=1;
                break;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        if(pass==1) {
            low_idx=mid;
            high_idx=mid;
            if(low_idx-1>=0) {
                while(nums[low_idx-1]==nums[low_idx]) 
                {
                    low_idx--;
                    if(low_idx==0) break;
                }
            }
            if(high_idx+1<nums.size()){
            while(nums[high_idx+1]==nums[high_idx]) 
            {
                high_idx++;
                if(high_idx==nums.size()-1) break;
            }
            }
        }
        ans.push_back(low_idx);
        ans.push_back(high_idx);
        
        return ans;
        
        }
    }
};
```

### [Number of Occurences in a sorted array](https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456)

```cpp
int count(vector<int>& nums, int n, int target) {
	int low=0,mid,high=nums.size()-1,pass=0,low_idx=-1,high_idx=-1;
        vector <int> ans;
        if(nums.size()==1 && nums[0]==target) {
            ans.push_back(0);
            ans.push_back(0);
            return ans[1]-ans[0];;
        }
        else if(nums.size()==1 && nums[0]!=target) {
            ans.push_back(-1);
            ans.push_back(-1);
            return  ans[1]-ans[0];;
        }
        else{
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target) {
                pass=1;
                break;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        if(pass==1) {
            low_idx=mid;
            high_idx=mid;
            if(low_idx-1>=0) {
                while(nums[low_idx-1]==nums[low_idx]) 
                {
                    low_idx--;
                    if(low_idx==0) break;
                }
            }
            if(high_idx+1<nums.size()){
            while(nums[high_idx+1]==nums[high_idx]) 
            {
                high_idx++;
                if(high_idx==nums.size()-1) break;
            }
            }
            ans.push_back(low_idx);
            ans.push_back(high_idx);
            return (ans[1]-ans[0])+1;
        }
        ans.push_back(low_idx);
        ans.push_back(high_idx);
        return (ans[1]-ans[0]);
        
        }
    
}
```

### [Search in rotated sorted Array 1](https://leetcode.com/problems/search-in-rotated-sorted-array/)

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,mid;
        while(low<=high){
            mid=(low+high)/2;
            if (nums[mid]==target ) return mid;
            else if(nums[low]<=nums[mid]) {
                if(nums[low]<=target && target<=nums[mid]) high=mid-1;
                else low=mid+1;
            }
            else{
                if(nums[mid]<=target && target<=nums[high]) low=mid+1;
                else high=mid-1;
            }
        }
        return -1;
    }
};
```

### [Search in rotated sorted Array 2](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)
```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,mid;
        while(low<=high){
            mid=(low+high)/2;
            if (nums[mid]==target) return 1;
            else if(nums[low]==nums[mid] && nums[mid]==nums[high]) {
                 low++;
                 high--;
                 continue;
            }
            else if(nums[low]<=nums[mid]) {
                if(nums[low]<=target && target<=nums[mid]) high=mid-1;
                else low=mid+1;
            }
            else{
                if(nums[mid]<=target && target<=nums[high]) low=mid+1;
                else high=mid-1;
            }
        }
        return 0;
    }
};
```

### [Find Minimum in rotated sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid,mini=INT_MAX;
        while(low<=high){
            mid=(low+high)/2;
             if(nums[low]<=nums[mid]) {
                mini=min(mini, nums[low]);
                low=mid+1;
            }
            else{
                mini=min(mini, nums[mid]);
                high=mid-1;
            }
        }
        return mini;
    }
};
```

### [Find the rotated position in sorted array](https://www.codingninjas.com/studio/problems/rotation_7449070)
THis problem solution is same as previous problem solution because by finding the lowest valued element index you are finding the rotated position.

### [Single Element in Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array/)
```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
            int low=1,mid,high=nums.size()-2;
            if(nums.size()==1) return nums[0];
            else if(nums[0]!=nums[1]) return nums[0];
            else if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
            while(low<=high)
            {
                mid=(low+high)/2;
                if((nums[mid-1]!=nums[mid]) && (nums[mid+1]!=nums[mid]))
                {
                    return nums[mid];
                }
                else if((mid%2 == 0 && nums[mid]==nums[mid+1]) || (mid%2 == 1 && nums[mid]==nums[mid-1]))
                {
                    low=mid+1;
                }
                else high=mid-1;;
            }
            return -1;
    }
};
```