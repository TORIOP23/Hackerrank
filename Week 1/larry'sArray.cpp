/*
    https://www.hackerrank.com/challenges/larrys-array
    - Bài toán: Một mảng có thể được sắp xếp bằng cách chọn 3 phần tử liên tiếp và xoay. Viết hàm trả về "YES" nếu mảng đó có
    thể sử dụng cách trên để sắp xếp, ngược lại trả về "NO".
    - Input: Một mảng số nguyên.
    - Output: "YES" nếu mảng có thể được sắp xếp, ngược lại trả về "NO"
    - Ý tưởng: Sử dụng một mảng tạm để chứa mảng đã cho khi đã được sắp xếp tăng dần. Chạy lần lượt mảng đã cho, so sánh giá trị
    ở vị trí đó của mảng đề bài với mạng đã được sắp xếp. Nếu đã trùng nhau, chuyển sang phần tử tiếp theo, còn nếu chưa bằng
    nhau, di chuyển xuống dưới để tìm vị trí của phần tư đó. Sau đó dùng xoay 3 phần tử để đưa phần tử đó lên trên đầu của bộ ba
    phần tử đó. Làm như vậy cho đến phần tử n - 4. Ta chỉ cần xét 3 phần tử cuối để xem có sắp xếp được không.
        Nếu 3 phần tử cuối đã sắp xếp hoặc có dạng: BCA (nghĩa là phần từ thứ 3 nhỏ nhất -> phần tử đầu tiên -> phần tử thứ hai)
    hoặc CAB (phần tử ở giữa nhỏ nhất -> phần tử cuối -> phần tử đầu) thì có thể sắp xếp được. Ngược lại thì không thể sắp xếp.
    - Độ phức tạp: O(nlogn).
*/
string larrysArray(vector<int> A)
{
    vector<int> sortedArr = A;
    sort(sortedArr.begin(), sortedArr.end());
    for (int i = 0; i < A.size() - 3; i++)
    {
        if (A[i] == sortedArr[i])
            continue;
        int idx = i;
        while (A[idx] != sortedArr[i])
        {
            idx++;
        }
        while (idx >= i + 2)
        {
            swap(A[idx - 1], A[idx]);
            swap(A[idx - 2], A[idx - 1]);
            idx -= 2;
        }
        if (idx == i + 1)
        {
            swap(A[idx - 1], A[idx]);
            swap(A[idx], A[idx + 1]);
        }
    }
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    int n = A.size() - 1;
    if (A == sortedArr)
        return "YES";
    if ((A[n] <= A[n - 2] && A[n - 2] < A[n - 1]) || (A[n - 1] <= A[n] && A[n] <= A[n - 2]))
    {
        return "YES";
    }
    else
        return "NO";
}
