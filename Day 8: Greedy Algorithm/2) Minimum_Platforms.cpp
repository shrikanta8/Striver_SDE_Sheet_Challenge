class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int i=0,j=0,n=arr.size(),ans=0;
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        while(i<n){
            while(i<n && arr[i]<=dep[j]){
                i++;
            }
            ans=max(ans,i-j);
            j++;
        }
        return ans;
    }
};
