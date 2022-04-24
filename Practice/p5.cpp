/*
Write a function that takes a string as a parameter,
changes all the letters to uppercase letters and returns
the updated string.
*/

#include <iostream>

using std::cin;
using std::cout;
using std::string;

string toUpCase(string b)
{
    for (int i = 0; i < b.length(); i++)
    {
        b[i] = toupper(b[i]);
    }

    return b;
}

int main()
{
    string a;

    cout << "Enter a string: ";
    cin >> a;

    cout << "After: " << toUpCase(a);
}
