class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v;
        if(n<3)
            return v;   //no answer
        
        sort(nums.begin(),nums.end());
       
        int a,j,k;
        
        for(int i=0;i<n-2;i++){
            //taking unique nums[i]
            if(i==0 || (i>0 && nums[i] != nums[i-1])){
                j=i+1,k=n-1;
                a = nums[i];
            
                while(j<k ){
                    if(nums[j] + nums[k] == 0-a){

                        vector<int> arr;
                        arr.push_back(a);arr.push_back(nums[j]);arr.push_back(nums[k]);
                        v.push_back(arr);

                        while( j<k && nums[j] == nums[j+1]) 
                            j++;

                        while( j < k && nums[k] == nums[k-1] )
                            k--;

                        j++; //get new  numbers != num[j-1]
                        k--;
                    }
                    else if(nums[j] + nums[k] > 0-a){
                        k--;
                    }
                    else
                        j++;
                }
            }
           
        }
        return v;
    }
};
