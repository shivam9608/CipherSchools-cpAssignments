//Question 7. Alternative Soting.

#include <iostream>
using namespace std;

void alternateSort(int arr[], int n) ;
void swap(int *xp, int *yp) ;
void selectionSort(int arr[], int n) ;

void alternateSort(int arr[], int n){
   selectionSort(arr, n);
   int i = 0, j = n-1;
   while (i < j) {
      cout << arr[j--] << " ";
      cout << arr[i++] << " ";
   }
  
   if (n % 2 != 0)
      cout << arr[i];
}

void swap(int *xp, int *yp){
   int temp = *xp;
   *xp = *yp;
   *yp = temp;
}

void selectionSort(int arr[], int n){
   int i, j, min_idx;
   for (i = 0; i < n-1; i++){
      min_idx = i;
   for (j = i+1; j < n; j++)
      if (arr[j] < arr[min_idx])
         min_idx = j;
      swap(&arr[min_idx], &arr[i]);
   }
}

int main()
{
   int arr[] = { 4,1,8,2,9,3,7};
   int n = sizeof(arr)/sizeof(arr[0]);
   alternateSort(arr, n);
   return 0;
}
