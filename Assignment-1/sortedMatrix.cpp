//Question 3. Search in sorted matrix

#include <bits/stdc++.h> 
using namespace std; 

int searchnumber(int a[4][4], int nu, int x) 
{ 
  if (nu == 0) 
    return -1; 
  int smallest = a[0][0], largest = a[nu - 1][nu - 1]; 
  if (x < smallest || x > largest) 
    return -1; 
  
  int i = 0, j = nu - 1; 
  while (i < nu && j >= 0) { 
    if (a[i][j] == x) { 
      cout << " Found at "<< i << ", " << j; 
      return 1; 
    } 
    if (a[i][j] > x) 
      j--; 
    else 
      i++; 
  } 
    cout << " not found"; 
  return 0; 
} 
int main() 
{ 
  int a[4][4] = { { 1, 2, 3, 4 }, 
          { 10, 12, 13, 14 }, 
          { 20, 22, 23,24  }, 
          { 30, 32, 33, 34 } }; 
  searchnumber(a, 3, 23); 
  return 0; 
} 
