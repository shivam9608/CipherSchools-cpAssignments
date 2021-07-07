//Ques.4) Detect and Remove Loop in a Linked List.
//Sol.
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
};
void removeLoop(struct Node*, struct Node*);
int detectAndRemoveLoop(struct Node* list)
{
    struct Node *slow_p = list, *fast_p = list;
     while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            removeLoop(slow_p, list);
            return 1;
        }
    }
    return 0;
}
void removeLoop(struct Node* loop_node, struct Node* head)
{
    struct Node* ptr1;
    struct Node* ptr2;
    ptr1 = head;
    while (1) {
        ptr2 = loop_node;
        while (ptr2->next != loop_node
               && ptr2->next != ptr1)
            ptr2 = ptr2->next;
        if (ptr2->next == ptr1)
            break;
        ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
}
void printList(struct Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 struct Node* newNode(int key)
{
    struct Node* temp = new Node();
    temp->data = key;
    temp->next = NULL;
    return temp;
}
int main()
{
    struct Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
    head->next->next->next->next->next = head->next->next;
     detectAndRemoveLoop(head);
     cout << "Linked List after removing loop" << endl;
     printList(head);
     return 0;
}
