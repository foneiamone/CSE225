/* Task 2: Ask the user to enter the length/size of an array. Dynamically
allocate memory for a floating point array of the given length, check the
memory used by the program before and after creating the program, delete
the array and set the pointer to null. */

#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int size;

    cout << "Enter array size: ";
    cin >> size;

    float *arr = new float(size);

    cout << "Enter array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    delete[] arr;

    arr = NULL;
}