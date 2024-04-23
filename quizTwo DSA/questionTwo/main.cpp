#include <iostream>

using namespace std;

struct listNode {
  int value;
  listNode *next;
  listNode(int x = 0, listNode *ptr = nullptr) : value(x), next(ptr) {}
};

listNode* detectCycle(listNode* head) {
  listNode *slow = head, *fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      slow = head;
      while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
      }
      return slow;
    }
  }
  return nullptr;
}
int main() {
  listNode* head = new listNode(7);
  head->next = new listNode(2);
  head->next->next = new listNode(3);
  // Create cycle
  head->next->next->next = head;

  listNode* cycleStart = detectCycle(head);

  if (cycleStart) {
    cout << "Starting node of the cycle: " << cycleStart->value<< endl;
  } else {
    cout << "No cycle detected in the linked list." <<endl;
  }

  return 0;
}

//can be solved using constant time when their is only one element in the list.
