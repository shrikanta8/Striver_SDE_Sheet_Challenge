class Solution {
  public:
    
    vector<int> jobSequencing(vector<int> &deadline,
                           vector<int> &profit) {
        int n = deadline.size();
        int cnt = 0;
        int totProfit = 0;
    
        // pair the profit and deadline of
        // all the jos together
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({ deadline[i],profit[i]});
        }
    
        // sort the jobs based
        sort(jobs.begin(), jobs.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for (auto ele:jobs) {
            int d=ele.first;
            if(pq.size()<d){
                pq.push(ele.second);
            }
            else if(pq.size() && pq.top()<ele.second){
                pq.pop();
                pq.push(ele.second);
            }
        }
        while(!pq.empty()){
            cnt++;
            totProfit+=pq.top();pq.pop();
        }
        return {cnt, totProfit};
    }
};


// [2, 1, 2, 1, 1]
// [100, 19, 27, 25, 15]

// 1,25
// 1,19
// 1,15
// 2,100
// 2,27


// 100 2
// 27  2
// 25
// 19
// 15





// 50 2
// 30 3
// 20 1
// 10 1




// 20  3
// 30 2
// 50 2
// 10 1

