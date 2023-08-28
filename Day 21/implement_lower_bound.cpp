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