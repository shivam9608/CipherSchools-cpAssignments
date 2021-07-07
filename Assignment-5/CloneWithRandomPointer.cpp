//Question 11. Clone with linked with random pointer.

#include <iostream>
#include <unordered_map> 
using namespace std;
 
struct Node
{
    int data;
    Node* next;
    Node* random;
 
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
 
// Recursive function to print a linked list
void traverse(Node* head)
{
    if (head == nullptr)
    {
        cout << "null" << endl;
        return;
    }
 
    // print current node data and random pointer data
    if (head->random) {
        cout << head->data << "(" << head->random->data << ") —> ";
    }
    else {
        cout << head->data << "(" << "X" << ") —> ";
    }
 
    // recur for the next node
    traverse(head->next);
}
 
// Recursive function to copy random pointers from the original linked list
// into the cloned linked list using the map
void updateRandomPointers(Node* head, unordered_map<Node*, Node*> &map)
{
    // base case
    if (map[head] == nullptr) {
        return;
    }
 
    // update the random pointer of the cloned node
    map[head]->random = map[head->random];
 
    // recur for the next node
    updateRandomPointers(head->next, map);
}
 
// Recursive function to clone the data and next pointer for each node
// of the linked list into a given map
Node* cloneLinkedList(Node* head, unordered_map<Node*, Node*> &map)
{
    // base case
    if (head == nullptr) {
        return nullptr;
    }
 
    // clone all fields of the head node except the random pointer
 
    // create a new node with the same data as the head node
    map[head] = new Node(head->data);
 
    // clone the next node
    map[head]->next = cloneLinkedList(head->next, map);
 
    // return cloned head node
    return map[head];
}
 
// Function to clone a linked list having random pointers
Node* cloneLinkedList(Node* head)
{
    // Create a map to store mappings from a node to its clone
    unordered_map<Node*, Node*> map;
 
    // clone data and next pointer for each node of the original
    // linked list and put references into the map
    cloneLinkedList(head, map);
 
    // update random pointers from the original linked list in the map
    updateRandomPointers(head, map);
 
    // return the cloned head node
    return map[head];
}
 
int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
 
    head->random = head->next->next->next;
    head->next->next->random = head->next;
 
    cout << "Original Linked List:\n";
    traverse(head);
 
    Node* clone = cloneLinkedList(head);
 
    cout << "\nCloned Linked List:\n";
    traverse(clone);
 
    return 0;
}
