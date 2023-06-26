class Solution {
public:
    bool func(int num, vector<int> edge[]){
        queue<int> q;
        int c=0;
        vector<int> inDeg(num,0);
        for(int i=0;i<num;i++){
            for(auto n: edge[i]){
                inDeg[n]++;
            }
        }
        for(int i=0;i<num;i++){ //taking all the nodes whose indegree is 0
            if(inDeg[i]==0) q.push(i);
        }
        while(q.size()){
            int f= q.front();
            c++;
            q.pop();
            for(auto n: edge[f]){
                inDeg[n]--;
                if(inDeg[n] == 0)q.push(n);
            }
        }
        return c==num; //if true it means there is no cycle
    }
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        
        vector<int> edge[numCourses];
        for(auto n: p){
            edge[n[0]].push_back(n[1]);
        }
        return func(numCourses,edge);
    }
};
