/*
Write a function that takes a string as parameter and 
returns the number of words in that string. 
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int StrLen(string str)
{
    int wordCount = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            wordCount++;
        }
    }

    return wordCount;
}

int main()
{
    string str1;

    cout << "Enter a string: ";
    getline(cin, str1);

    cout << "Number of words in the string: " << StrLen(str1) + 1;
}