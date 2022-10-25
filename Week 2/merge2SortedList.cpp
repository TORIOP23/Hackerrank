/*
    - Bài toán: Cho hai danh sách liên kết có cái giá trị tăng dần. Hãy trộn hai danh sách trên thành một danh sách liên kết
    có sắp xếp.
    - Input: Hai danh sách liên kết có các giá trị đã được sắp xếp tăng dần.
    - Output: Một danh sách đơn được sắp xếp tăng dần.
    - Ý tưởng: Tạo một danh sách liên kết mới là danh sách liên kết cần tạo, ba danh sách tạm để dịch chuyển theo các danh sách
    liên kết. Khi các con trỏ của hai danh sách liên kết trỏ đến từng node, so sánh giá trị giữa hai dánh sách liên kết để lấy giá
    trị nhỏ hơn, đồng thời dịch chuyển danh sách đã được lấy giá trị. Vòng lặp đó sẽ dừng lại nếu 1 trong 2 danh sách liên kết đã
    cho đi đến cuối cùng. Cuối cùng, chuyển hết các node của danh sách còn lại vào cuối của danh sách kết quả.
    - Độ phức tạp: O(m + n) với m, n là độ dài của hai danh sách liên kết.
*/


SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *ans;
    SinglyLinkedListNode *walk1 = head1;
    SinglyLinkedListNode *walk2 = head2;
    if(walk1 -> data <= walk2 -> data)
    {
        ans = new SinglyLinkedListNode(walk1 -> data);
        walk1 = walk1 -> next;
    }
    else {
        ans = new SinglyLinkedListNode(walk2 -> data);
        walk2 = walk2 -> next;
    }
    SinglyLinkedListNode *head = ans;
    while(walk1 != NULL && walk2 != NULL){
        if(walk1 -> data <= walk2 -> data)
        {
            SinglyLinkedListNode *tmp = new SinglyLinkedListNode(walk1 -> data);
            ans -> next = tmp;
            ans = ans -> next;
            walk1 = walk1 -> next;
        }
        else
        {
            SinglyLinkedListNode *tmp = new SinglyLinkedListNode(walk2 -> data);
            ans -> next = tmp;
            ans = ans -> next;
            walk2 = walk2 -> next;
        }
    }
    while(walk1 != NULL)
    {
        SinglyLinkedListNode *tmp = new SinglyLinkedListNode(walk1 -> data);
        ans -> next = tmp;
        ans = ans -> next;
        walk1 = walk1 -> next;
    }
    while(walk2 != NULL)
    {
        SinglyLinkedListNode *tmp = new SinglyLinkedListNode(walk2 -> data);
        ans -> next = tmp;
        ans = ans -> next;
        walk2 = walk2 -> next;
    }
    return head;
}
