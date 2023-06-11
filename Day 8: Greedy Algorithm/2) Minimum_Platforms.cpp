int findPlatform(int arr[], int dep[], int n)
    {
        
        sort(arr, arr + n);
        sort(dep, dep + n);
    
        // plat_needed indicates number of platforms
        // needed at a time
        int plat_needed = 1, result = 1;
        int i = 1, j = 0;
    
        while (i < n) {
            //arrival is less so we need a new platform for the train
            if (arr[i] <= dep[j]) {
                plat_needed++;
                i++;
            }
            //if dep is less than arrival then it means that train is leaving so 
            //one platform is cleared now!
            else {
                plat_needed--;
                j++;
            }
    
            if (plat_needed > result)
                result = plat_needed;
        }
    
        return result;
    }
