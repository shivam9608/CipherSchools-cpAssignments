//Question 3. Add two numbers in the linked list.

#include<bits/stdc++.h>
using namespace std;

list addListNumbers(list<int> l1, list<int> l2){
   if(l1.size() > l2.size()){
      for(int i = l2.size(); i != l1.size(); i++){
         l2.push_front(0);
      }
   }else if(l1.size() < l2.size()){
      for(int i = l1.size(); i != l2.size(); i++){
         l1.push_front(0);
      }
   }
   list<int>::reverse_iterator it1 = l1.rbegin();
   list<int>::reverse_iterator it2 = l2.rbegin();
   list<int> result;
   int carry = 0;
   while(it1 != l1.rend()){
      result.push_front((*it1 + *it2 + carry) % 10);
      carry = (*it1 + *it2 + carry) / 10;
      it1++; it2++;
   }
   if(carry != 0){
      result.push_front(carry);
   }
   return result;
}
list<int> numToList(int n){
   list<int> numList;
   while(n != 0){
      numList.push_front(n % 10);
      n /= 10;
   }
   return numList;
}
void displayListNum(list<int> numList){
   for(list<int>::iterator it = numList.begin(); it != numList.end();
   it++){
      cout<<*it;
   }
   cout << endl;
}
int main() {
   int n1 = 512;
   int n2 = 14578;
   list<int> n1_list = numToList(n1);
   list<int> n2_list = numToList(n2);
   list<int> res = addListNumbers(n1_list, n2_list);
   cout << "First number: "; displayListNum(n1_list);
   cout << "Second number: "; displayListNum(n2_list);
   cout << "Result: "; displayListNum(res);
}
