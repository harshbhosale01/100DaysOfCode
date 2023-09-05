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