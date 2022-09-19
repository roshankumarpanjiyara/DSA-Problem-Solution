class Solve {
    Pair getFloorAndCeil(int[] arr, int n, int x) {
        // code here
        Arrays.sort(arr);
        int floor = -1;
        int ceil = -1;
        int l = 0;
        int h = n-1;
        while(l<=h){
            int mid = (h+l)/2;
            if(arr[mid] == x){
                return new Pair(x,x);
            }else if(arr[mid]<x){
                floor = arr[mid];
                l = mid+1;
            }else{
                ceil = arr[mid];
                h = mid-1;
            }
        }
        return new Pair(floor,ceil);
    }
}
