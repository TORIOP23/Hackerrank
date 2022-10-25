/*
    -
*/
void solve(vector<pair<int, string>> str) {
    vector<queue<string>> save(100);
    for(int i = 0; i < str.size(); i++) {
        save[str[i].first].push(str[i].second);
    }
    for(int i = 0; i < save.size(); i++) {
        while(!save[i].empty()){
            cout << save[i].front() << " ";
            save[i].pop();
        }
    }
}
void countSort(vector<vector<string>> arr) {
    int half = arr.size() / 2;
    if(arr.size() % 2 == 1) half++;
    vector<pair<int, string>> str;
    for(int i = 0; i < arr.size(); i++) {
        int num = stoi(arr[i][0]);
        if(i < half) arr[i][1] = "-";
        str.push_back(make_pair(num, arr[i][1]));
    }
    solve(str);
}
