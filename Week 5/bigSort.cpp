bool compare(string a, string b) {
    if(a.size() == b.size()) {
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) return a[i] < b[i];
        }
    }
    return a.size() < b.size();
}
vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), compare);
    return unsorted;
}
