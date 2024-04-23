#include <iostream>

using namespace std;

class ListNode {
public:
    int value;
    ListNode *next;
    ListNode(int x) : value(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->value<< " ";
        head = head->next;
    }
    cout <<endl;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(16);

    cout << "Original list: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
