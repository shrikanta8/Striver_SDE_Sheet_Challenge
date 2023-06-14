double eps= 1e-7;    //we want 6 decimal places hence 7
double func(double mid, int n)
{
    double num=1.0;
    for(int i=1;i<=n; i++)
    {
         num*= mid;
    }
    return num;
}

double findNthRootOfM(int n, long long m) {
    double low=1, high=m, mid ;
    
    while((high-low)> eps)
    {
        mid=(low+high)/2.0;
       
        if(func(mid, n)< m)
        {
            low= mid;
        }
        else 
            high=mid;
    }
    return low;
}


Time Complexity: N x log(M x 10^d)
//N times we are multiplying 
//d is accuracy

Space Complexity: O(1)
