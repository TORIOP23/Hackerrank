/*
    - Bài toán: Xác định xem danh sách liên kết có chứa vòng hay không?
    - Input: Một danh sách liên kết đầu vào.
    - Output: trả về true nếu danh sách liên kết có chứa vòng, trả về false nếu danh sách liên kết không chứa vòng.
    - Ý tưởng: Sử dụng hai con trỏ, trong đó một con trỏ sẽ bước 1 bước, một con trỏ bước hai bước. Nếu ở một thời điểm mà hai con
    trở lại trùng vị trí với nhau thì danh sách liên kết kia có vòng, ngược lại, nếu chỉ cần 1 trong hai con trỏ trỏ đến NULL thì
    danh sách liên kết không có vòng.
    - Độ phức tạp:
*/
bool has_cycle(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* fast = head;
    SinglyLinkedListNode* slow = head;
    while(fast -> next != NULL && fast -> next -> next != NULL && slow -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
        if(fast == slow) return true;
    }
    return false;
}
