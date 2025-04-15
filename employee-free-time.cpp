// problem link : https://leetcode.com/problems/employee-free-time/description/

vector<vector<ll>>mergeIntervals(vector<vector<ll>>&v) {
    vector<vector<ll>>ans;
    ans.push_back(v[0]);
    for (ll i = 1; i < v.size(); i++) {
        ll cs = v[i][0];
        ll ce = ans.back()[1];
        ll ne = v[i ][1];
        if (ce >= cs) {
            ans.back()[1] = max(ce, ne);
        }
        else ans.push_back(v[i]);
    }
    return ans;
}

void solve() {
    vector<vector<vector<ll>>>schedule = {{{1, 3}, {6, 7}}, {{2, 4}}, {{2, 5}, {9, 12}}};
    vector<vector<ll>>v, ans;
    for (auto it : schedule) {
        for (auto it2 : it) {
            v.push_back(it2);
        }
    }
    sort(v.begin(), v.end());
    v = mergeIntervals(v);
    ll ce = v[0][1];
    for (ll i = 1; i < v.size(); i++) {
        ll cs = v[i][0];
        if (cs > ce) {
            ans.push_back({ce, cs});
        }
        ce = v[i][1];
    }
    for (auto it : ans) {
        cout << "{ " << it[0] << "," << it[1] << " }" << endl;
    }
}
