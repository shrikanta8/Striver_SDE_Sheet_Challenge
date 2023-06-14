#include<bits/stdc++.h>
using namespace std;

bool checking(long long int a[],long long int mid,int n,int c);
bool checking(long long int a[],long long int mid,int n,int c){
    int chk=1;
    long long int var=a[0];
    for(int i=1;i<n;i++){
        if(a[i]-var>=mid)
        {   
            if(++chk ==c)
                { 
                    return true;
                }
            var=a[i];
        }
    }
    return false;
}
int main(){
    long long int t,mid,start,end;
    bool chk;
    int c,n,i;
    scanf("%lld",&t);
    while(t--)
    {
        long long int lmid=-1;
        scanf("%d%d",&n,&c);
        long long int a[n];
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        sort(a,a+n);
        start= 0;end=a[n-1]-a[0];
        while(start<=end){
            mid=start + (end-start)/2;
            chk=checking(a,mid,n,c);
            if(!chk)
                end=mid-1;
            else{
                lmid =mid;
                start=mid+1;
            }
        }
        printf("%lld\n",lmid);
    }
    return 0;
}
