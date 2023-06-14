#include<bits/stdc++.h>
bool isPossible(vector<int> &A,long long int mid,int B){
    
    long long int sum=0;
    int stdcnt=1;
    
    for(auto num:A){
        sum+=num;
        if(sum>mid){
            stdcnt++;
            sum=num;
        }
    }
   
    return stdcnt<=B;
}

int Solution::books(vector<int> &A, int B) {
    
    int n=A.size();
    if(n<B) return -1;
     
    long long int low=*max_element(A.begin(),A.end());  //max element of A
    long long int high=0;
    high=accumulate(A.begin(),A.end(),high);
    
    long long int mid;
    
    while(low<=high){
        mid=low+(high-low)/2;
        
        if(isPossible(A,mid,B)){
            high=mid-1;
        }
        else
            low=mid+1;
            
    }
    return low;
}
