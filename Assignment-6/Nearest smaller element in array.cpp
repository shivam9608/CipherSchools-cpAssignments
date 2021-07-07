//Ques.15) Nearest smaller element in array.
//Sol.
#include <iostream> 
using namespace std; 
  
// Prints smaller elements on left side of every element 
void printPrevSmaller(int arr[], int n) 
{ 
    // Always print empty or '_' for first element 
    cout << "_, "; 
  
    // Start from second element 
    for (int i=1; i<n; i++) 
    { 
        // look for smaller element on left of 'i' 
        int j; 
        for (j=i-1; j>=0; j--) 
        { 
            if (arr[j] < arr[i]) 
            { 
                cout << arr[j] << ", "; 
                break; 
            } 
        } 
  
        // If there is no smaller element on left of 'i' 
        if (j == -1) 
           cout << "_, " ; 
    } 
} 
  
/* Driver program to test insertion sort */
int main() 
{ 
    int arr[] = {1, 3, 0, 2, 5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printPrevSmaller(arr, n); 
    return 0; 
}
