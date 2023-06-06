typedef long long ll;
class Solution {
public:

    int ans=0;
    void merging(vector<int>& arr, int st, int mid, int en){
        int right=mid;
        
        for(int l=st;l<mid;l++){
            while(right<=en && arr[l] > (ll)2 * arr[right]){
                right++;
            }
            ans += (right-mid);
        }

        //merge
        int i=st,j=mid;
        vector<int> mergeArr;
        while(i < mid && j<=en){
            if(arr[i] <= arr[j]){
                mergeArr.push_back(arr[i]);
                i++;
            }
            else{
                mergeArr.push_back(arr[j]);
                j++;
            }
        }
        while(i<mid){
            mergeArr.push_back(arr[i++]);
        }
        while(j <= en){
            mergeArr.push_back(arr[j++]);
        }   
        int k=0;
        for(int i=st;i<=en;i++){
            arr[i] =mergeArr[k++];
        }
        // return ans;
    }
    void reversePairsHelper(vector<int>& arr,int st, int en){
        if(st < en){
            int mid = st + (en - st)/2;
            reversePairsHelper(arr,st,mid);
            reversePairsHelper(arr, mid+1, en);
            merging(arr,st,mid+1,en);
        }
    }
    int reversePairs(vector<int>& arr) {
        int n = arr.size();
         reversePairsHelper(arr,0,n-1);
         return ans;
        
    }
};
