//Ques.8) Remove all occurrences of duplicates in a sorted linked list.
//Sol.
#include <bits/stdc++.h>
using namespace std;
struct LL{
  int data;
  LL *next;  
};
void insertAtBeginning(struct LL**head,int dataToBeInserted)
{
  struct LL*temp=*head,*curr=new LL;
      curr->data=dataToBeInserted;
      curr->next=NULL;
  if(*head==NULL)
      *head=curr;
    
  else
    {
      curr->next=*head;
      *head=curr;
    }
    
    //O(1) constant time
}
void removeDuplicatesSorted(struct LL ** head)
{
    
    struct LL* curr = *head , * temp; 
   
    if (curr == NULL) 
       return; 
 
    while (curr->next != NULL)  //Traverse till end
    {
       if (curr->data == curr->next->data)  //if data is same then advance the pointer to next of next
       {            
           temp = curr->next->next;
           delete(curr->next);
           curr->next = temp;  
       }
       else  //move ahead if data is not equal
          curr = curr->next; 
    }
  
}
void display(struct LL**head)
{
  struct LL*temp=*head;
  while(temp!=NULL)
    {
      if(temp->next!=NULL)
      cout<data<<" ->";
      else
      cout<data;
      
      temp=temp->next; //move to next node
    }
    //O(number of nodes)
  cout<<endl;
}
int main()
{
    struct LL *head = NULL; //initial list has no elements
  insertAtBeginning(&head,23);
  insertAtBeginning(&head,23);
  insertAtBeginning(&head,23);
  insertAtBeginning(&head,49);
  insertAtBeginning(&head,49);
  insertAtBeginning(&head,49);
  insertAtBeginning(&head,49);
  insertAtBeginning(&head,73);
  insertAtBeginning(&head,73);
  insertAtBeginning(&head,115);
  insertAtBeginning(&head,115);
  insertAtBeginning(&head,115);
  insertAtBeginning(&head,115);
  insertAtBeginning(&head,162);
  insertAtBeginning(&head,211);
  insertAtBeginning(&head,211);
  insertAtBeginning(&head,211);
  insertAtBeginning(&head,211);
  insertAtBeginning(&head,211);
  insertAtBeginning(&head,716);
  insertAtBeginning(&head,982); 
  insertAtBeginning(&head,982);
  insertAtBeginning(&head,982);
  insertAtBeginning(&head,982);
    cout<<"\nCurrent List is :-\n";
  display(&head);
    removeDuplicatesSorted(&head);
    cout<<"\nAfter removing duplicates from sorted given list the list becomes :-\n";
  display(&head);
    return 0;
}	 
