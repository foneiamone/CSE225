/* Task 1: Dynamically allocate memory for an integer variable, set a value
to it, print the value, there delete the variable and set the pointer to
null.

5 */

#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int *num = new int(5);

    cout << *num;

    delete num;

    num = NULL;
}