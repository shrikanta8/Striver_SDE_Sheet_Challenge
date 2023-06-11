int maxMeetings(int start[], int end[], int n)
    {
         pair<int , int> meet[n];    //array of pairs<finish, start time>
        
        for(int i=0;i<n;i++){
            meet[i]={end[i],start[i]};
        }
        
        sort(meet, meet+n); //on the basis of finish time
        
        int ans=1,init = meet[0].first;
        
        for(int i=1;i<n;i++){
            if(meet[i].second>init){        //if next's start time is greater than previous end time then ans++
                ans++;
                init =  meet[i].first;
            }
        }
        return ans;
    }
