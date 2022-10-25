/*
    - Bài toán: Xóa đi những phần tử trùng trong danh sách liên kết đã được sắp xếp tăng dần.
    - Input: Danh sách liên kết đã được sắp xếp tăng dần.
    - Output: Danh sách liên kết chứa các phần tử phân biệt đã được loại bỏ các phần tử giống nhau.
    - Ý tưởng: Sử dụng một node tạm để dịch chuyển và một biến int để lưu giá trị của node hiện tại. Nếu giá trị của nde tiếp theo
    trùng với giá trị của node hiện tại thì sẽ xóa node tiếp theo đó, ngược lại nếu khác nhau thì sẽ giữ nguyên, dịch chuyển sang node
    tiếp theo và lưu giá trị của node đó vào biến int hiện tại.
    - Độ phức tạp: O(n)
*/
SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode *walk = llist;
    int val = llist -> data;
    while(walk -> next != NULL)
    {
        if(walk -> next -> data == val)
        {
            SinglyLinkedListNode *tmp = walk -> next;
            walk -> next = walk -> next -> next;
            delete(tmp);
        }
        else {
            val = walk -> next -> data;
            walk = walk -> next;
        }
    }
    return llist;
}
