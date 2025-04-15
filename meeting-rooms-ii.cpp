//problem link: https://leetcode.com/problems/meeting-rooms-ii/description/
int Solution::solve(vector<vector<int> > &A) {
    vector<int>st, ed;
    for(auto it:A){
        st.push_back(it[0]);
        ed.push_back(it[1]);
    }
    sort(st.begin(), st.end());
    sort(ed.begin(), ed.end());
    int i=0, j=0;
    int maxi=0,cnt=0;
    while(i<st.size()){
        if(st[i]<ed[j]){  
            cnt++;
            i++;
        }
        else{
            cnt--;
            j++;
        }
        maxi=max(maxi, cnt);
    }
    return maxi;
}   
