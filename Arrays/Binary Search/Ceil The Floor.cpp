pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int l = 0;
	int r = n-1;

	int floor = -1;
	while(l <= r){
		int mid = l +(r-l)/2;
		if(a[mid] == x){
			floor = a[mid];
			break;
		}else if(a[mid] < x){
			floor = a[mid];
			l = mid+1;
		}else{
			r = mid-1;
		}
	}

	l = 0;
	r = n-1;
	int ceil = -1;

	while(l <= r){
		int mid = l+(r-l)/2;
		if(a[mid] == x){
			ceil = a[mid];
			break;
		}else if(a[mid] > x){
			ceil = a[mid];
			r = mid - 1;
		}else{
			l = mid+1;
		}
	}

	return {floor, ceil};
}
