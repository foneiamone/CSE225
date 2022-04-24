/*
Write a function that takes a string as parameter and 
returns true if the string is a palindrome, 
if not, it returns false. 
*/

#include <iostream>

using std::cin;
using std::cout;
using std::string;

bool isPalindrome(string b)
{
    for (int i = 0; i < b.length() / 2; i++)
    {
        if (b[i] != b[b.length() - i - 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string a;

    cout << "Enter a string: ";
    cin >> a;

    bool result = isPalindrome(a);

    (result) ? cout << "Palindrome." : cout << "Not a Palindrome.";

    return 0;
}