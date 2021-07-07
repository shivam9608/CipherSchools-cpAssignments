//Ques.13) Swap k nodes from the end.
//Sol.
#include<bits/stdc++.h>
using namespace std;
class MyLinkedList {
public:
    struct ListNode {
        ListNode *next;
        int val;
        ListNode(int a): next(NULL), val(a){}
    };
    ListNode *head;
    MyLinkedList():head(NULL) {
    }
    
    void addAtHead(int val) {
        ListNode *node = new ListNode(val);
        node->next = head;
        head = node;
    }
    
    void swapNodes(int k) {
        int len=0;
        ListNode* curr = head;
        for(int i=1;i<k;i++){
            curr = curr->next;
        }
        ListNode* p1 = head,*p2 = curr->next;
        while(p2){
            p1 = p1->next;
            p2=p2->next;
        }
        swap(curr->val,p1->val);
    }
    void print_list(){
      ListNode* node = head;
    while(node){
      cout<<node->val<<" ";
      node = node->next;
    }
        cout<<endl;
  }
};
int main(){
  MyLinkedList *list = new MyLinkedList();
  list->addAtHead(5);
  list->addAtHead(4);
  list->addAtHead(3);
  list->addAtHead(2);
  list->addAtHead(1);
  
  list->print_list();
  list->swapNodes(2);
    list->print_list();
}
