//also on https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1/

#include <bits/stdc++.h> 
typedef long long ll;
    long long merging(long long *arr, long long st, long long mid, long long en){
        long long i=st,j=mid,ans=0;
        
        vector<int> mergeArr;
        while(i < mid && j<=en){
            if(arr[i] <= arr[j]){
                mergeArr.push_back(arr[i]);
                i++;
            }
            else{
                mergeArr.push_back(arr[j]);
                j++;
                ans+=mid-i;
            }
        }
        while(i<mid){
            mergeArr.push_back(arr[i++]);
        }
        while(j <= en){
            mergeArr.push_back(arr[j++]);
        }   
        ll k=0;
        for(int i=st;i<=en;i++){
            arr[i] =mergeArr[k++];
        }
        return ans;
    }
    long long inversionCountHelper(long long *arr, long long st, long long en){
        long long ans = 0;
        if(st < en){
            ll mid = st + (en - st)/2;
            ans += inversionCountHelper(arr,st,mid);
            ans += inversionCountHelper(arr, mid+1, en);
            ans += merging(arr,st,mid+1,en);
        }
        return ans;
    }

long long getInversions(long long *arr, int n){
    return inversionCountHelper(arr,0,n-1);
}
