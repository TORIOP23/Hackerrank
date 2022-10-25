/*
    https://www.hackerrank.com/challenges/sparse-arrays
    - Bài toán: Cho một tập chuỗi đầu vào strings và một tập chuỗi truy vấn queries. Đối với chuỗi truy vấn, đếm xem nó xuất hiện
    bao nhiêu lần trong chuỗi đầu vào. Trả về một mảng kết quả.
    - Input: chuỗi đầu vào strings và chuỗi truy vấn queries.
    - Output: Mảng lưu số lần xuất hiện của từng chuỗi truy vấn trong chuỗi đầu vào.
    - Ý tưởng: Sử dụng một mảng động vector có độ dài là độ dài của tập chuỗi truy vấn queries. Sử dụng cấu trúc dữ liệu
    map<string, int> để đếm số lần xuất hiện của từng chuỗi trong queries trong tập strings. Mỗi lần chuỗi trong queries xuất hiện,
    cộng vào phần biến int một đơn vị. Sau khi đi hết chuỗi queries, lưu giá trị vào mảng động.
    - Độ phức tạp:
        + Truy vấn đến giá trị của map: O(logn)
        + Vòng for cho mảng động: O(n)
    => Độ phức tạp = O(nlogn)
*/

vector<int> matchingStrings(vector<string> strings, vector<string> queries)
{
    vector<int> ans(queries.size());
    map<string, int> frequent;
    for (auto i : strings)
    {
        frequent[i]++;
    }
    for (int i = 0; i < queries.size(); i++)
    {
        ans[i] = frequent[queries[i]];
    }
    return ans;
}
