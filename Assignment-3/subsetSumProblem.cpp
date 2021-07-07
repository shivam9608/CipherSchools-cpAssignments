// Q10. Subset Sum Problem

#include <iostream>
using namespace std;

bool subsetSum(int arr[], int n, int sum)
{
    // return true if the sum becomes 0 (subset found)
    if (sum == 0) {
        return true;
    }
    if (n < 0 || sum < 0) {
        return false;
    }
    bool include = subsetSum(arr, n - 1, sum - arr[n]);
    bool exclude = subsetSum(arr, n - 1, sum);
    return include || exclude;
}
int main()
{
    int arr[] = { 7, 3, 2, 5, 8 };
    int sum = 14;
    int n = sizeof(arr) / sizeof(arr[0]);
 
    if (subsetSum(arr, n - 1, sum)) {
        cout << "Subsequence with the given sum exists";
    }
    else {
        cout << "Subsequence with the given sum does not exist";
    }
     return 0;
}
