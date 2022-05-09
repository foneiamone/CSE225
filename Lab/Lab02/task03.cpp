/* Task 3: Dynamically allocate memory for a 2D character array of size 10x8.
Delete all the arrays and set the pointer to null. */

#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int i;

    char **arr = new char *[10];

    for (i = 0; i < 10; i++)
    {
        arr[i] = new char[8];
    }
    
    for (i = 0; i < 10; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
    arr = NULL;
}