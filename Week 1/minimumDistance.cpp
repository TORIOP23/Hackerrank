/*
    https://www.hackerrank.com/challenges/minimum-distances
    - Bài toán: Cho một dãy các số nguyên, tìm khoảng cách nhỏ nhất giữa các phần tử giống nhau trong dãy. Nếu không tồn tại thì
    trả về -1.
    - Input: mảng a chứa các số nguyên.
    - Output: Khoảng cách nhỏ nhất giữa các phần tử giống nhau. Nếu không có, trả về -1;
    - Ý tưởng: Sử dụng một map<int, vector<int>> để lưu giá trị vị trí của các phần tử giống nhau. Sau đó, xét từng cặp vị trí
    liên tiếp của từng giá trị giống nhau và so sánh với giá trị nhỏ nhất trước đó.
    - Độ phức tạp:
*/

int minimumDistances(vector<int> a)
{
    unordered_map<int, vector<int>> hashmap;
    for (int i = 0; i < a.size(); i++)
    {
        hashmap[a[i]].push_back(i);
    }
    int ans = pow(2, 31) - 1;
    for (auto i : hashmap)
    {
        if (i.second.size() <= 1)
            continue;
        for (int j = 0; j < i.second.size() - 1; j++)
        {
            ans = min(ans, i.second[j + 1] - i.second[j]);
        }
    }
    if (ans == pow(2, 31) - 1)
        return -1;
    else
        return ans;
}
