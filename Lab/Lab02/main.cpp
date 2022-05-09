/* How many number you want: 3
Enter the numbers: 1 2 3
Display the results: 1 2 3 */

#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int num;

    cout << "How many number you want: ";
    cin >> num;

    float *ptr = new float[num];

    cout << "Enter the numbers: ";
    for (int i = 0; i < num; i++)
    {
        cin >> *(ptr + i);
    }

    cout << "Display the results: ";
    for (int i = 0; i < num; i++)
    {
        cout << *(ptr + i) << ' ';
    }

    delete[] ptr;

    ptr = NULL;
}