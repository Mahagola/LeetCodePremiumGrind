// https://leetcode.com/problems/meeting-scheduler/
#include<bits/stdc++.h>
using namespace std;

bool isOverlap(vector<int>&a, vector<int>&b){
    return a[1]>b[0];
}
vector<int>solve(vector<vector<int>>&slot1, vector<vector<int>>&slot2){
    int n = slot1.size(), m = slot2.size(), duration = 8;
    sort(slot1.begin(), slot1.end(), [](const vector<int>&a, const vector<int>&b){
        if(a[0]!=b[0]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    });

    sort(slot1.begin(), slot1.end(), [](const vector<int>&a, const vector<int>&b){
        if(a[0]!=b[0]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    });

    int i = 0, j = 0;
    int ans = 0;
    while(i<n && j<m){
        int st1 = slot1[i][0], st2 = slot2[j][0];
        int end1 = slot1[i][1], end2 = slot2[j][1];
        if(isOverlap(slot1[i], slot2[j])){
            int width = min(end1, end2) - max(st1, st2);
            if(width>=duration)return {max(st1, st2) , max(st1, st2) + duration};
        }
        if(slot1[i][1] < slot2[j][1])i++;
        else j++;
    }
    return {-1, -1};
}
int main(){
    vector<vector<int>>slot1 = {{10, 50}, {60, 120}, {140, 210}};
    vector<vector<int>>slot2 = {{0, 15}, {60, 70}};
	  vector<int>ans = solve(slot1, slot2);
    cout<<ans[0]<<" , "<<ans[1]<<endl;
}
