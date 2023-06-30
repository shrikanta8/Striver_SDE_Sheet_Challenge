vector<string> AllPossibleStrings(string s){
    int n =s.length();
    vector<string> ans;
    string str;
    for(int i=1;i<pow(2,n);i++){
        str="";
        for(int j=0;j<n;j++){
            if(i & (1<<j) )
                str += s[j];
        }
        ans.emplace_back(str);
    }
    // Code here
    sort(ans.begin(), ans.end());
    return ans;
}
