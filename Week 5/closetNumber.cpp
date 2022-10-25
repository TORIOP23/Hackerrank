vector<int> closestNumbers(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int minDiff = INT_MAX;
    for(int i = 0; i < arr.size() - 1; i++) {
        minDiff = min(minDiff, arr[i + 1] - arr[i]);
    }
    vector<int> ans;
    for(int i = 0; i < arr.size() - 1; i++) {
        if(arr[i + 1] - arr[i] == minDiff) {
            ans.push_back(arr[i]);
            ans.push_back(arr[i + 1]);
        }
    }
    return ans;
}
