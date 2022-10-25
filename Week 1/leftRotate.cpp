/*
    https://www.hackerrank.com/challenges/array-left-rotation
    - Bài toán: Thao tác xoay trái trên một mảng có kích thước n, có nghĩa là dịch chuyển vị trí của các phần tử sang bên trái.
    Cho một số nguyên d, hãy dịch chuyển nhiều bước và trả về kết quả cuối cùng.
    - Input: Một mảng arr chứa các số nguyên và số nguyên d cho biết số lần xoay trái.
    - Output: Mảng đó sau d lần thao tác xoay trái.
    - Ý tưởng: Trước hết, nếu số lần quay bằng số phần tử trong mảng, mảng sẽ quay về vị trí cũ, vì vậy, trước hết ta phải lấy
    dư của số lần quay với số phần tử để loại bỏ quay nhiều vòng tròn. Khi quay trái, các phần tử đầu chuyển về cuối, các phần tử
    còn lại dịch về phía trái 1 đơn vị. Vậy nên, sau d lần quay, những phần từ từ 0 đến d - 1 sẽ chuyển xuống cuối, các phần tử còn
    lại sẽ dịch chuyển lên trên d đơn vị.
    - Độ phức tạp: O(max(d, n - d))
*/

vector<int> rotateLeft(int d, vector<int> arr)
{
    int n = arr.size();
    d %= n;
    vector<int> tmp;
    for (int i = d; i < n; i++)
    {
        tmp.push_back(arr[i]);
    }
    for (int i = 0; i < d; i++)
    {
        tmp.push_back(arr[i]);
    }
    return tmp;
}
