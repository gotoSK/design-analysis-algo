// C++ code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1
#include <iostream>
using namespace std;
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;

    return -1;
}
int main(void)

{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = search(arr, n, x);
    (result == -1) ? cout << "Element is not present in array"

                   : cout << "Element is present at index " << result;

    return 0;
}