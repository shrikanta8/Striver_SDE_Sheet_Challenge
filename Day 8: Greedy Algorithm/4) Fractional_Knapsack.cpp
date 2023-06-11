
bool comp(Item a, Item b){
        // double r1 = (double)a.value/(double)a.weight;
        // double r2 = (double)b.value/(double)b.weight;
        return ((double)a.value/a.weight) > ((double)b.value/b.weight); 
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
   double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        double remain =0,totVal = 0,totWei=0;
        
        for(int i=0;i<n; i++){
           if(totWei + arr[i].weight <= W){
               totWei += arr[i].weight;
               totVal += arr[i].value;
           } 
           else{
               remain = W - totWei;
               totVal += ((double)arr[i].value/arr[i].weight) * remain;
               break;
           }
        }
        return totVal;
        // Your code here
    }
        
};
