// https://leetcode.com/problems/wiggle-sort/description/
vector<int> wiggleSort(int n, vector<int> nums) {
    // Write your code here.
    int m = n/2;
    priority_queue<int>pq; //max heap : to store first n/2 smallest numbers
    priority_queue<int, vector<int>, greater<int>>pq2; //min heap : to store first n/2 largest numbers
    if(n&1){
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            pq2.push(nums[i]);
            if(pq.size()>m+1)pq.pop();
            if(pq2.size()>m)pq2.pop();
        }
    }
    else{
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            pq2.push(nums[i]);
            if(pq.size()>m)pq.pop();
            if(pq2.size()>m)pq2.pop();
        }
    }
    stack<int>st;
    while(!pq2.empty()){
        st.push(pq2.top());
        pq2.pop();
    }
    for(int i=0;i<n;i+=2){
        if(!pq.empty() && i<n){
            auto it=pq.top();
            nums[i]=it;
            pq.pop();
        }
        if(!st.empty() && i<n){
            auto it=st.top();
            nums[i+1]=it;
            st.pop();
        }
    }
    return nums;
}

