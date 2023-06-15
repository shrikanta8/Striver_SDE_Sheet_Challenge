void addElement(vector<int>& arr){
    int sz = arr.size();
    int childIndex = sz-1;
    while(childIndex > 0){
        int parentIndex = (childIndex-1)/2;
        if(arr[childIndex] < arr[parentIndex])
            swap(arr[childIndex] , arr[parentIndex]);
        else
            break;
        childIndex = parentIndex;
    }
    return;
}
void removeMin( vector<int>& arr){
    swap(arr[0],arr[arr.size()-1]);
    arr.pop_back();
    int parentIndex = 0;
    int child1 = parentIndex * 2+ 1;
    int child2 = parentIndex * 2+ 2;
    
    while( child1 < arr.size() ){
        int minIndex = parentIndex;
        if(arr[minIndex] > arr[child1])
            minIndex = child1;
        
        if(child2 < arr.size() && arr[minIndex] > arr[child2])
            minIndex = child2;
        
        if(minIndex == parentIndex)
            break;
        swap(arr[parentIndex],arr[minIndex]);
        parentIndex = minIndex;
        child1 = parentIndex * 2+ 1;
        child2 = parentIndex * 2+ 2;
    }
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> arr,ans;
    
    for(auto num:q){
        if(num[0] == 1){
            ans.push_back(arr[0]);
            removeMin(arr);
        }
        else{
            arr.push_back(num[1]);
            addElement(arr);
        }
    }
    return ans;
    // Write your code here.
}
