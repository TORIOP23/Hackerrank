long arrayManipulation(int n, vector<vector<int>> queries) {

    // Solution 1
    vector<long> arr(n, 0);
    for(int i = 0; i < queries.size(); i++)
    {
        for(int j = queries[i][0] - 1; j < queries[i][1]; j++)
        {
            arr[j] += (long)queries[i][2];
        }

    }
    long ans = *max_element(arr.begin(), arr.end());
    return ans;


    //Solution 2
    vector<long> add(n + 1, 0);
    vector<long> sub(n + 1, 0);
    for(int i = 0; i < queries.size(); i++) {
        add[queries[i][0]] += queries[i][2];
        if(queries[i][1] < n) sub[queries[i][1] + 1] += queries[i][2];
    }
    for(int i = 1; i <= n; i++) {
        add[i] += add[i - 1];
        sub[i] += sub[i - 1];

    }
    vector<long> ans(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        ans[i] = (add[i] - sub[i]);
    }
    return *max_element(ans.begin(), ans.end());
}
