/*
Write a function that checks if an array is sorted or not. 
If the array is sorted in ascending order the function returns true, 
otherwise false.
*/

#include <iostream>

using std::cin;
using std::cout;

bool isSorted(int a[], int n)
{
    if (n <= 1)
    {
        return true;
    }

    for (int i = 0; i < (n - 1); i++)
    {
        if (a[i] > a[i + 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int size, *arr;

    cout << "Enter array size: ";
    cin >> size;

    arr = new int[size];

    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    bool chkArr = isSorted(arr, size);

    (chkArr) ? cout << "Array is sorted." : cout << "Array is unsorted.";

    return 0;
}