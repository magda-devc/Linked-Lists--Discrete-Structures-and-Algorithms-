#include <iostream>

using namespace std;

class listNode{

public:
    int data;
    listNode* next;

    listNode(int data) : data(data), next(nullptr) {}
};

bool Cycle(listNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    listNode* slow = head;
    listNode* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    listNode* head = new listNode(1);
    head->next = new listNode(2);
    head->next->next = new listNode(3);
    //The list will have no cycle:
    head->next->next->next = head;

    if (Cycle(head)) {
        cout << "True" <<endl;
    } else {
        cout << "False" <<endl;
    }
    return 0;
}
