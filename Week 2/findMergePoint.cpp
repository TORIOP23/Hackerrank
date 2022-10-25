/*
    - Bài toán: Cho hai danh sách liên kết có đoạn được trônj vào với nhau từ 1 điểm. Hãy viết hàm để cho biết giá trị cẩu điểm
    bắt đầu trộn giữa hai danh sách.
    - Input: Hai danh sách liên kết có đoạn chung.
    - Output: Giá trị của điểm bắt đầu được trộn vào nhau của hai danh sách.
    - Ý tưởng: Ta xét bắt đầu từ đầu của một danh sách, so sánh từng phần tử của danh sách còn lại với phần tử của danh sách kia.
    Nếu phần tử của danh sách thứ hai trùng với phần từ của danh sách thứ nhất thì điểm đó là điểm bắt đầu được merge lại với
    nhau.
    - Độ phức tạp: O(m * n) với m, n là độ dài của hai danh sách liên kết.
*/

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *walk1 = head1;
    while(walk1 != NULL)
    {
        SinglyLinkedListNode* walk2 = head2;
        while(walk2 != NULL)
        {
            if(walk2 == walk1)
            {
                return walk2 -> data;
            }
            else walk2 = walk2 -> next;
        }
        walk1 = walk1 -> next;
    }
    return -1;
}

