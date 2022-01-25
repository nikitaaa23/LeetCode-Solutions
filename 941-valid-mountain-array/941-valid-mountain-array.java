class Solution {
    public boolean validMountainArray(int[] arr) {
        if(arr.length<3){
            return false;
        }
        if(arr[0]>=arr[1] || arr[arr.length-1]>=arr[arr.length-2]){
            return false;
        }
        
        int l = 0, h = arr.length-1;
        boolean inc = true, dec = true;
        while(l<h && (inc || dec)){
            if(arr[l]<arr[l+1]){
                l++;
            }
            else{
                inc = false;
            }
            
            if(arr[h] <arr[h-1]){
                h--;
            }
            else{
                dec = false;
            }
        }
        return l==h;
    }
}