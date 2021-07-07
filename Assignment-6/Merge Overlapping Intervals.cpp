//Ques.11) Merge Overlapping Intervals.
//Sol.
#include <bits/stdc++.h>
#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
using namespace std;
struct interval{
   int start;
   int end;
};
bool compareInterval(interval i1, interval i2){
   return (i1.start < i2.start);
}
void mergeOverlappingIntervals(interval *arr, int n){
   if (n <= 0) {
      return;
   }
   stack<interval> s;
   sort(arr, arr + n, compareInterval);
   s.push(arr[0]);
   for (int i = 1; i < n; ++i) {
      interval top = s.top();
      if (top.end < arr[i].start) {
         s.push(arr[i]);
      } else if(top.end < arr[i].end) {
         top.end = arr[i].end;
         s.pop();
         s.push(top);
      }
   }
   cout << "Merged intervals: " << endl;
   while (!s.empty()) {
      interval i = s.top();
      cout << "{" << i.start << ", " << i.end << "}" << " ";
      s.pop();
   }
   cout << endl;
}
int main(){
   interval arr[] = {{12, 14}, {11, 13}, {20, 22}, {21, 23}};
   mergeOverlappingIntervals(arr, SIZE(arr));
   return 0;
}
