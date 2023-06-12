void func(vector<int>& arr, vector<int>& ans, int N,int sum,int ind){
    if(ind>=N){
        ans.push_back(sum);
        return;
    }
    func(arr,ans, N, sum+arr[ind],ind+1);
    func(arr,ans, N, sum,ind+1);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
     vector<int> ans;
     func(arr,ans,N,0,0);
     return ans;
}
