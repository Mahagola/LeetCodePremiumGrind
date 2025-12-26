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


// using line sweep 
class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n = start.size();
        vector<pair<int, int>>v;
        for(int i = 0;i<start.size();i++){
            v.push_back({start[i], 1});
            v.push_back({end[i], -1});
        }
        
        sort(v.begin(), v.end(), [](const pair<int, int>&a, const pair<int, int>&b){
            if(a.first!=b.first){
                return a.first < b.first;
            } 
            return a.second < b.second;
        });
        
        int maxi = 1;
        int cnt = 0;
        for(int i=0; i<v.size();i++){
            cnt+=v[i].second;
            if(cnt > 1){
                maxi = max(cnt, maxi);
            }
        }
        return maxi;
    }
};
