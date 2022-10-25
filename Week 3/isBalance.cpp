/*
    - Bài toán: Cho một chuỗi ký tự chứa toàn ký tự dấu ngoặc ("(){}[]"). Hãy viết hàm cho biết chuỗi ký tự đó có cân bằng hay không.
    - Input: một chuỗi ký tự chứa toàn các ký tự dấu ngoặc.
    - Output: trả về "YES" nếu chuỗi đó là chuỗi dấu ngoặc cân bằng, ngược lại trả về "NO".
    - Ý tưởng: Nếu độ dài của chuỗi không chia hết cho hai thì có thể kết luận không phải là chuỗi cân bằng. Sử dụng hai biến chỉ địa chỉ *left* và *right*. Cho *left* chạy đến ký tự mở ngoặc cuối cùng trước ký tự đóng ngoặc tiếp theo, *right* trỏ đến ký tự đóng 
    ngoặc đầu tiên. Nếu ký tự ở vị trí *left* khác ký tự của *right* thì có thể kết luận chuỗi không cân bằng. Ngược lại, xóa hai ký tự đó trong biến, cho *left* lùi lại
    1 đơn vị, *right* bằng *left* và làm tiếp tục các bước như trên cho đến khi hết chuỗi.
    - Độ phức tạp: 
*/
string isBalanced(string s) {
    if(s.size() % 2 != 0) return "NO";
    int left = 0, right = 0;
    while(left < s.size() - 1 && right < s.size())
    {
        while(left < s.size() - 1 && (s[left + 1] == '(' || s[left + 1] == '{' || s[left + 1] == '['))
        {
            left++;
        }
        if(left >= s.size() - 1) return "NO";
        right = left + 1;
        if((s[left] == '(' && s[right] == ')') || (s[left] == '{' && s[right] == '}') || (s[left] == '[' && s[right] == ']')){
            s.erase(s.begin() + left, s.begin() + left + 2);
            if(left > 0) left--;
            right = left;
        }
        else return "NO";
        //cout << s << endl;
    }
    return "YES";
}
