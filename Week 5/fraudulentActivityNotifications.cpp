int activityNotifications(vector<int> expenditure, int d) {
    map<int, int> arr;
    for(int i = 0; i < d; i++) {
        arr[expenditure[i]]++;
    }
    int count = 0;
    int idx = 0;
    for(int i = d; i < expenditure.size(); i++) {
        if(i > d) {
            arr[expenditure[idx]]--;
            arr[expenditure[i - 1]]++;
            idx++;
        }
        int id1, id2;
        if(d % 2 != 0) {
            int tmp = 0;
            for(auto j: arr) {
                int n = 0;
                while(n < j.second && tmp < d / 2 + 1) {
                    n++;
                    tmp++;
                }
                if(tmp == d / 2 + 1) {
                    id1 = j.first;
                    id2 = j.first;
                    break;
                }

            }

        }
        else {
            long tmp1 = 0;
            long tmp2 = 0;
            for(auto j: arr) {
                int n = 0;
                while(n < j.second && tmp2 < d / 2 + 1) {
                    n++;
                    tmp1++;
                    if(tmp1 == d / 2) id1 = j.first;
                    tmp2++;
                }
                if(tmp2 == d / 2 + 1) {
                    id2 = j.first;
                    break;
                }
            }
        }
        if(id1 + id2 <= expenditure[i]) count++;
    }
    return count;
}
