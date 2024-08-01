struct ListNode* reverseList(struct ListNode* previous, struct ListNode* node) {
    struct ListNode* temp;
    if (node->next == NULL) {
        node->next = previous;
        return node;
    }
    temp = node->next;
    node->next = previous;
    return reverseList(node, temp);
}
int getSize(struct ListNode* head) {
    int size = 1;
    while (head->next != NULL) {
        size++;
        head = head->next;
    }
    return size;
}
void reorderList(struct ListNode* head) {
    if (head->next == NULL) {
        return;
    }
    struct ListNode* temp = head;
    int size = getSize(temp);
    int tsize = (size / 2) + (size % 2);
    while (tsize > 0) {
        temp = temp->next;
        tsize--;
    }
    if (temp->next != NULL) {
        temp = reverseList(NULL, temp);
    }
    struct ListNode* copy = head->next;
    struct ListNode* result = head;
    while (size > 2) {
        result->next = temp;
        temp = temp->next;
        result = result->next;
        result->next = copy;
        copy = copy->next;
        result = result->next;
        size -= 2;
    }
    if (size == 2) {
        result->next = copy;
        result->next->next = NULL;
    }
    if (size == 1) {
        result->next = NULL;
    }
    return;
}