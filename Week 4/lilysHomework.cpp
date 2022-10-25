/*
    - Bài toán:
    - Input:
    - Output:
*/


/*
    Phương pháp 1: Sử dụng Selection Sort.
*/

int lilysHomework(vector<int> arr) {
    vector<int> sorted = arr;
    vector<int> tmp = arr;
    sort(sorted.begin(), sorted.end());
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(tmp[i] == sorted[i]) continue;
        for(int j = i + 1; j < arr.size(); j++) {
            if(tmp[j] == sorted[i]) {
                swap(tmp[i], tmp[j]);
                count++;
                break;
            }
        }
    }
    int tmpCount = 0;
    sort(sorted.begin(), sorted.end(), [](const int &l, const int &r){
        return l > r;
    });
    tmp = arr;
    for(int i = 0; i < arr.size(); i++) {
        if(tmp[i] == sorted[i]) continue;
        for(int j = i + 1; j < arr.size(); j++) {
            if(tmp[j] == sorted[i]) {
                swap(tmp[i], tmp[j]);
                tmpCount++;
                break;
            }
        }
    }
    cout << count << " " << tmpCount << endl;
    count = min(count, tmpCount);
    return count;
}

/*
    Phương án 2:
*/
int lilysHomework(vector<int> arr) {
    map<int, vector<int>> nums;
    map<int, int> pos;
    for(int i = 0; i < arr.size(); i++) {
        nums[arr[i]].push_back(i);
    }
    map<int, vector<int>> num2;
    num2 = nums;
    vector<int> tmp = arr;
    vector<int> tmp2 = arr;
    sort(tmp.begin(), tmp.end());
    int count = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(tmp[i] == arr[i]) {
            nums[tmp[i]].erase(nums[tmp[i]].begin() + 0);
        }
        else {
            int j =  nums[tmp[i]][0];
            swap(nums[arr[i]][0], nums[tmp[i]][0]);
            swap(arr[i], arr[j]);
            nums[tmp[i]].erase(nums[tmp[i]].begin() + 0);
            count++;
        }
    }
    sort(tmp.begin(), tmp.end(), [](const int &l, const int &r) {
        return l > r;
    });
    int tmpCount = 0;
    for(int i = 0; i < tmp2.size(); i++) {
        if(tmp2[i] == tmp[i]) {
            num2[tmp[i]].erase(num2[tmp[i]].begin() + 0);
        }
        else {
            int j =  num2[tmp[i]][0];
            swap(num2[tmp2[i]][0], num2[tmp[i]][0]);
            swap(tmp2[i], tmp2[j]);
            num2[tmp[i]].erase(num2[tmp[i]].begin() + 0);
            tmpCount++;
        }
    }
    count = min(count, tmpCount);
    return count;
}
