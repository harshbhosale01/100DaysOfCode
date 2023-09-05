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